/*
 *  GPL LICENSE SUMMARY
 *
 *  Copyright(c) 2012 Intel Corporation. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of version 2 of the GNU General Public License as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *  The full GNU General Public License is included in this distribution
 *  in the file called LICENSE.GPL.
 *
 *  Contact Information:
 *    Intel Corporation
 *    2200 Mission College Blvd.
 *    Santa Clara, CA  97052
 *
 */

/*
 *      Includes, defines, variables, module parameters, ...
 */

#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/miscdevice.h>
#include <linux/watchdog.h>
#include <linux/init.h>
#include <linux/pci.h>
#include <linux/ioport.h>
#include <linux/uaccess.h>
#include <linux/io.h>

/* Module and version information */
#define INTELCE_WDT_VERSION "0.1"
#define INTELCE_WDT_MODULE_NAME "intelce watchdog"
#define INTELCE_WDT_DRIVER_NAME INTELCE_WDT_MODULE_NAME ", v" INTELCE_WDT_VERSION
#define PFX INTELCE_WDT_MODULE_NAME ": "

#define PCI_DEVICE_ID_INTELCE_WDT	0x094A

/*Intel CE2600 watchdog clock(HZ)*/
#define INTELCE_WDT_CLK_FREQ  62500000

/* Memory mapped registers */
#define INTELCE_WDT_RELOAD   (BASEADDR + 0x14)/* IntelCE watchdog reload register  */
#define INTELCE_WDT_CTRL     (BASEADDR + 0x18)/* IntelCE watchdog ctrl register      */
#define INTELCE_WDT_KEY      (BASEADDR + 0x1C)/* IntelCE watchdog key register      */
#define INTELCE_WDT_STATUS (BASEADDR + 0x20)/* IntelCE watchdog key register      */

/* Control register bits*/
#define INTELCE_WTCON_ENABLE (0x01 << 2)  /* Enable WDT timer*/
#define INTELCE_WTCON_RSTEN  (0x01 << 0)  /* Enable WDT reset*/

/* Key value constants */
#define INTELCE_WDT_UNLOCK    0x482E   /* Key value to unlock watchdog registers  */

/* internal variables */
static void __iomem *BASEADDR;
static DEFINE_SPINLOCK(intelce_wdt_lock); /* Guards the hardware */
static unsigned long timer_alive;
static struct pci_dev *intelce_wdt_pci;
static char intelce_wdt_expect_close;
static unsigned int wdt_count;

/* We can only use 1 wdt due to the /dev/watchdog restriction */
static int wdt_found;

/* module parameters */
/* 30 sec default heartbeat (0 < heartbeat < 69) */
#define WATCHDOG_HEARTBEAT 30
static int heartbeat = WATCHDOG_HEARTBEAT;  /* in seconds */
module_param(heartbeat, int, 0);
MODULE_PARM_DESC(heartbeat,
		"Watchdog heartbeat in seconds. (0<heartbeat<69, default="
				__MODULE_STRING(WATCHDOG_HEARTBEAT) ")");

static int nowayout = WATCHDOG_NOWAYOUT;
module_param(nowayout, int, 0);
MODULE_PARM_DESC(nowayout,
		"Watchdog cannot be stopped once started (default="
				__MODULE_STRING(WATCHDOG_NOWAYOUT) ")");

static inline void intelce_wdt_unlock_registers(void)
{
	writel(INTELCE_WDT_UNLOCK, INTELCE_WDT_KEY);
}

static int intelce_wdt_start(void)
{
	u32 wdt_ctrl;

	spin_lock(&intelce_wdt_lock);
	intelce_wdt_unlock_registers();
	/* reload watchdog count value*/
	writel(wdt_count, INTELCE_WDT_RELOAD);
	/* enable watchdog timer*/
	wdt_ctrl = readl(INTELCE_WDT_CTRL);
	wdt_ctrl |= (INTELCE_WTCON_ENABLE | INTELCE_WTCON_RSTEN);
        writel(wdt_ctrl, INTELCE_WDT_CTRL);
	spin_unlock(&intelce_wdt_lock);
	return 0;
}

static void intelce_wdt_stop(void)
{
	u32 wdt_ctrl;

	spin_lock(&intelce_wdt_lock);
	intelce_wdt_unlock_registers();
	wdt_ctrl = readl(INTELCE_WDT_CTRL);
	wdt_ctrl &= ~(INTELCE_WTCON_ENABLE | INTELCE_WTCON_RSTEN);
	writel(wdt_ctrl, INTELCE_WDT_CTRL);
	spin_unlock(&intelce_wdt_lock);
}

static void intelce_wdt_keepalive(void)
{
	spin_lock(&intelce_wdt_lock);
	intelce_wdt_unlock_registers();
	writel(wdt_count, INTELCE_WDT_RELOAD);
	spin_unlock(&intelce_wdt_lock);
}

static int intelce_wdt_set_heartbeat(int time)
{
	if (time < 0x1 || time > 68)
		return -EINVAL;

	spin_lock(&intelce_wdt_lock);

	/* Watchdog timer count value */
	wdt_count = time * INTELCE_WDT_CLK_FREQ;

	/* Reload */
	intelce_wdt_unlock_registers();
	writel(wdt_count, INTELCE_WDT_RELOAD);

	/* Done */
	heartbeat = time;
	spin_unlock(&intelce_wdt_lock);
	return 0;
}

/*
 *	/dev/watchdog handling
 */

static int intelce_wdt_open(struct inode *inode, struct file *file)
{
	/* /dev/watchdog can only be opened once */
	if (test_and_set_bit(0, &timer_alive))
		return -EBUSY;

	/* Reload and activate timer */
	intelce_wdt_start();

	return nonseekable_open(inode, file);
}

static int intelce_wdt_release(struct inode *inode, struct file *file)
{
	/* Shut off the timer. */
	if (intelce_wdt_expect_close == 42)
		intelce_wdt_stop();
	else {
		printk(KERN_CRIT PFX
				"Unexpected close, not stopping watchdog!\n");
		intelce_wdt_keepalive();
	}
	clear_bit(0, &timer_alive);
	intelce_wdt_expect_close = 0;
	return 0;
}

static ssize_t intelce_wdt_write(struct file *file, const char __user *data,
			  size_t len, loff_t *ppos)
{
	/* See if we got the magic character 'V' and reload the timer */
	if (len) {
		if (!nowayout) {
			size_t i;

			intelce_wdt_expect_close = 0;

			/* scan to see whether or not we got the
			 * magic character */
			for (i = 0; i != len; i++) {
				char c;
				if (get_user(c, data + i))
					return -EFAULT;
				if (c == 'V')
					intelce_wdt_expect_close = 42;
			}
		}

		/* someone wrote to us, we should reload the timer */
		intelce_wdt_keepalive();
	}
	return len;
}

static long intelce_wdt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int new_heartbeat;
	void __user *argp = (void __user *)arg;
	int __user *p = argp;
	static const struct watchdog_info ident = {
		.options =		WDIOF_SETTIMEOUT |
					WDIOF_KEEPALIVEPING |
					WDIOF_CARDRESET |
					WDIOF_MAGICCLOSE,
		.firmware_version =	0,
		.identity =		INTELCE_WDT_MODULE_NAME,
	};

	switch (cmd) {
	case WDIOC_GETSUPPORT:
		return copy_to_user(argp, &ident,
					sizeof(ident)) ? -EFAULT : 0;

	case WDIOC_GETSTATUS:
	case WDIOC_GETBOOTSTATUS:
		return put_user(0, p);

	case WDIOC_KEEPALIVE:
		intelce_wdt_keepalive();
		return 0;

	case WDIOC_SETTIMEOUT:
	{
		if (get_user(new_heartbeat, p))
			return -EFAULT;
		if (intelce_wdt_set_heartbeat(new_heartbeat))
			return -EINVAL;
		intelce_wdt_keepalive();
		/* Fall */
	}
	case WDIOC_GETTIMEOUT:
		return put_user(heartbeat, p);
	default:
		return -ENOTTY;
	}
}

/*
 *      Kernel Interfaces
 */

static const struct file_operations intelce_wdt_fops = {
	.owner = THIS_MODULE,
	.llseek = no_llseek,
	.write = intelce_wdt_write,
	.unlocked_ioctl = intelce_wdt_ioctl,
	.open = intelce_wdt_open,
	.release = intelce_wdt_release,
};

static struct miscdevice intelce_wdt_miscdev = {
	.minor = WATCHDOG_MINOR,
	.name = "watchdog",
	.fops = &intelce_wdt_fops,
};

/*
 * Data for PCI driver interface
 */
static DEFINE_PCI_DEVICE_TABLE(intelce_wdt_pci_tbl) = {
	{ PCI_DEVICE(PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_INTELCE_WDT), },
	{ 0, },                 /* End of list */
};
MODULE_DEVICE_TABLE(pci, intelce_wdt_pci_tbl);

/*
 *      Init & exit routines
 */

static unsigned char __devinit intelce_wdt_getdevice(struct pci_dev *pdev)
{
	if (pci_enable_device(pdev)) {
		printk(KERN_ERR PFX "failed to enable device\n");
		goto err_devput;
	}

	if (pci_request_region(pdev, 0, INTELCE_WDT_MODULE_NAME)) {
		printk(KERN_ERR PFX "failed to request region\n");
		goto err_disable;
	}

	BASEADDR = pci_ioremap_bar(pdev, 0);
	if (BASEADDR == NULL) {
		/* Something's wrong here, BASEADDR has to be set */
		printk(KERN_ERR PFX "failed to get BASEADDR\n");
		goto err_release;
	}

	/* Done */
	intelce_wdt_pci = pdev;
	return 1;

err_release:
	pci_release_region(pdev, 0);
err_disable:
	pci_disable_device(pdev);
err_devput:
	return 0;
}

static void __devinit intelce_wdt_initdevice(void)
{
	intelce_wdt_unlock_registers();
	/* Set watchdog control register to default value,disable watchdog */
	writel(0, INTELCE_WDT_CTRL);
	/* Clear watchdog status flag,see detail to ce2600 system timers document */
	writel(0x18, INTELCE_WDT_STATUS);

	/* And set the correct timeout value */
	intelce_wdt_set_heartbeat(heartbeat);
}

static int __devinit intelce_wdt_probe(struct pci_dev *pdev,
		const struct pci_device_id *ent)
{
	int ret;

	wdt_found++;
	if (wdt_found == 1)
		printk(KERN_INFO PFX "Intel CE2600 WatchDog Timer Driver v%s\n",
			INTELCE_WDT_VERSION);

	if (wdt_found > 1) {
		printk(KERN_ERR PFX "This driver only supports 1 device\n");
		return -ENODEV;
	}

	/* Check whether or not the hardware watchdog is there */
	if (!intelce_wdt_getdevice(pdev) || intelce_wdt_pci == NULL)
		return -ENODEV;

	/* Check that the heartbeat value is within it's range;
	   if not reset to the default */
	if (heartbeat < 0x1 || heartbeat > 68) {
		heartbeat = WATCHDOG_HEARTBEAT;
		printk(KERN_INFO PFX
			"heartbeat value must be 0<heartbeat<69, using %d\n",
								heartbeat);
	}

	intelce_wdt_initdevice();

	/* Register the watchdog so that userspace has access to it */
	ret = misc_register(&intelce_wdt_miscdev);
	if (ret != 0) {
		printk(KERN_ERR PFX
			"cannot register miscdev on minor=%d (err=%d)\n",
							WATCHDOG_MINOR, ret);
		goto err_unmap;
	}
	printk(KERN_INFO PFX
		"initialized (0x%p). heartbeat=%d sec (nowayout=%d)\n",
						BASEADDR, heartbeat, nowayout);
	return 0;

err_unmap:
	iounmap(BASEADDR);
	pci_release_region(intelce_wdt_pci, 0);
	pci_disable_device(intelce_wdt_pci);
	intelce_wdt_pci = NULL;
	return ret;
}

static void __devexit intelce_wdt_remove(struct pci_dev *pdev)
{
	/* Stop the timer before we leave */
	if (!nowayout)
		intelce_wdt_stop();

	/* Deregister */
	misc_deregister(&intelce_wdt_miscdev);
	iounmap(BASEADDR);
	pci_release_region(intelce_wdt_pci, 0);
	pci_disable_device(intelce_wdt_pci);
	intelce_wdt_pci = NULL;
}

static void intelce_wdt_shutdown(struct pci_dev *pdev)
{
	intelce_wdt_stop();
}

#ifdef CONFIG_PM

static unsigned int wtctrl_save;
static unsigned int wtreload_save;

static int intelce_wdt_suspend(struct pci_dev *pdev, pm_message_t state)
{
        /* Save watchdog state */
        wtctrl_save = readl(INTELCE_WDT_CTRL);
        wtreload_save = readl(INTELCE_WDT_RELOAD);

        /* Stop watchdog */
        intelce_wdt_stop();
	
	/*PCI device save*/
	pci_save_state(pdev);
	pci_disable_device(pdev);
	pci_set_power_state(pdev, pci_choose_state(pdev, state));
        return 0;
}

static int intelce_wdt_resume(struct pci_dev *pdev)
{
        int retval = 0;
	/*PCI device restore*/
	pci_set_power_state(pdev, PCI_D0);
	pci_restore_state(pdev);
	retval = pci_enable_device(pdev);
	if (retval)
	   	 return retval;

	/* Restore watchdog state. */
	intelce_wdt_unlock_registers();
        writel(wtreload_save, INTELCE_WDT_RELOAD); /* Reset count */
        writel(wtctrl_save, INTELCE_WDT_CTRL);

        printk(KERN_INFO PFX "watchdog %sabled\n",
               (wtctrl_save & INTELCE_WTCON_ENABLE) ? "en" : "dis");

        return 0;
}

#else
#define intelce_wdt_suspend NULL
#define intelce_wdt_resume  NULL
#endif /* CONFIG_PM */


static struct pci_driver intelce_wdt_driver = {
	.name		= INTELCE_WDT_MODULE_NAME,
	.id_table	= intelce_wdt_pci_tbl,
	.probe          = intelce_wdt_probe,
	.remove         = __devexit_p(intelce_wdt_remove),
	.shutdown       = intelce_wdt_shutdown,
	.suspend = intelce_wdt_suspend,
	.resume = intelce_wdt_resume,
};

static int __init watchdog_init(void)
{
	return pci_register_driver(&intelce_wdt_driver);
}

static void __exit watchdog_cleanup(void)
{
	pci_unregister_driver(&intelce_wdt_driver);
	printk(KERN_INFO PFX "Watchdog Module Unloaded.\n");
}

module_init(watchdog_init);
module_exit(watchdog_cleanup);

MODULE_LICENSE("GPL");
MODULE_ALIAS_MISCDEV(WATCHDOG_MINOR);
