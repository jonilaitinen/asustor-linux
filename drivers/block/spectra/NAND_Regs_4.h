/*
 * NAND Flash Controller Device Driver
 * Copyright (c) 2008-2010, Intel Corporation and its suppliers.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */



























  #define DEVICE_RESET                                     0x0   
  #define     DEVICE_RESET__BANK0                                             0x0001  
  #define     DEVICE_RESET__BANK1                                             0x0002  
  #define     DEVICE_RESET__BANK2                                             0x0004  
  #define     DEVICE_RESET__BANK3                                             0x0008  

  #define TRANSFER_SPARE_REG                               0x4   
  #define     TRANSFER_SPARE_REG__FLAG                                        0x0001  

  #define LOAD_WAIT_CNT                                    0x8   
  #define     LOAD_WAIT_CNT__VALUE                                            0xffff  

  #define PROGRAM_WAIT_CNT                                 0xc   
  #define     PROGRAM_WAIT_CNT__VALUE                                         0xffff  

  #define ERASE_WAIT_CNT                                  0x10   
  #define     ERASE_WAIT_CNT__VALUE                                           0xffff  

  #define INT_MON_CYCCNT                                  0x14   
  #define     INT_MON_CYCCNT__VALUE                                           0xffff  

  #define RB_PIN_ENABLED                                  0x18   
  #define     RB_PIN_ENABLED__BANK0                                           0x0001  
  #define     RB_PIN_ENABLED__BANK1                                           0x0002  
  #define     RB_PIN_ENABLED__BANK2                                           0x0004  
  #define     RB_PIN_ENABLED__BANK3                                           0x0008  

  #define MULTIPLANE_OPERATION                            0x1c   
  #define     MULTIPLANE_OPERATION__FLAG                                      0x0001  

  #define MULTIPLANE_READ_ENABLE                          0x20   
  #define     MULTIPLANE_READ_ENABLE__FLAG                                    0x0001  

  #define COPYBACK_DISABLE                                0x24   
  #define     COPYBACK_DISABLE__FLAG                                          0x0001  

  #define CACHE_WRITE_ENABLE                              0x28   
  #define     CACHE_WRITE_ENABLE__FLAG                                        0x0001  

  #define CACHE_READ_ENABLE                               0x2c   
  #define     CACHE_READ_ENABLE__FLAG                                         0x0001  

  #define PREFETCH_MODE                                   0x30   
  #define     PREFETCH_MODE__PREFETCH_EN                                      0x0001  
  #define     PREFETCH_MODE__PREFETCH_BURST_LENGTH                            0xfff0  

  #define CHIP_ENABLE_DONT_CARE                           0x34   
  #define     CHIP_ENABLE_DONT_CARE__FLAG                                     0x0001  

  #define ECC_ENABLE                                      0x38   
  #define     ECC_ENABLE__FLAG                                                0x0001  

  #define GLOBAL_INT_ENABLE                               0x3c   
  #define     GLOBAL_INT_ENABLE__FLAG                                         0x0001  

  #define WE_2_RE                                         0x40   
  #define     WE_2_RE__VALUE                                                  0x003f  

  #define ADDR_2_DATA                                     0x44   
  #define     ADDR_2_DATA__VALUE                                              0x003f  

  #define RE_2_WE                                         0x48   
  #define     RE_2_WE__VALUE                                                  0x003f  

  #define ACC_CLKS                                        0x4c   
  #define     ACC_CLKS__VALUE                                                 0x000f  

  #define NUMBER_OF_PLANES                                0x50   
  #define     NUMBER_OF_PLANES__VALUE                                         0x0007  

  #define PAGES_PER_BLOCK                                 0x54   
  #define     PAGES_PER_BLOCK__VALUE                                          0xffff  

  #define DEVICE_WIDTH                                    0x58   
  #define     DEVICE_WIDTH__VALUE                                             0x0003  

  #define DEVICE_MAIN_AREA_SIZE                           0x5c   
  #define     DEVICE_MAIN_AREA_SIZE__VALUE                                    0xffff  

  #define DEVICE_SPARE_AREA_SIZE                          0x60   
  #define     DEVICE_SPARE_AREA_SIZE__VALUE                                   0xffff  

  #define TWO_ROW_ADDR_CYCLES                             0x64   
  #define     TWO_ROW_ADDR_CYCLES__FLAG                                       0x0001  

  #define MULTIPLANE_ADDR_RESTRICT                        0x68   
  #define     MULTIPLANE_ADDR_RESTRICT__FLAG                                  0x0001  

  #define ECC_CORRECTION                                  0x6c   
  #define     ECC_CORRECTION__VALUE                                           0x001f  

  #define READ_MODE                                       0x70   
  #define     READ_MODE__VALUE                                                0x000f  

  #define WRITE_MODE                                      0x74   
  #define     WRITE_MODE__VALUE                                               0x000f  

  #define COPYBACK_MODE                                   0x78   
  #define     COPYBACK_MODE__VALUE                                            0x000f  

  #define RDWR_EN_LO_CNT                                  0x7c   
  #define     RDWR_EN_LO_CNT__VALUE                                           0x001f  

  #define RDWR_EN_HI_CNT                                  0x80   
  #define     RDWR_EN_HI_CNT__VALUE                                           0x001f  

  #define MAX_RD_DELAY                                    0x84   
  #define     MAX_RD_DELAY__VALUE                                             0x000f  

  #define CS_SETUP_CNT                                    0x88   
  #define     CS_SETUP_CNT__VALUE                                             0x001f  

  #define SPARE_AREA_SKIP_BYTES                           0x8c   
  #define     SPARE_AREA_SKIP_BYTES__VALUE                                    0x003f  

  #define SPARE_AREA_MARKER                               0x90   
  #define     SPARE_AREA_MARKER__VALUE                                        0xffff  

  #define DEVICES_CONNECTED                               0x94   
  #define     DEVICES_CONNECTED__VALUE                                        0x0007  

  #define DIE_MASK                                        0x98   
  #define     DIE_MASK__VALUE                                                 0x00ff  

  #define FIRST_BLOCK_OF_NEXT_PLANE                       0x9c   
  #define     FIRST_BLOCK_OF_NEXT_PLANE__VALUE                                0xffff  

  #define WRITE_PROTECT                                   0xa0   
  #define     WRITE_PROTECT__FLAG                                             0x0001  

  #define RE_2_RE                                         0xa4   
  #define     RE_2_RE__VALUE                                                  0x003f  

  #define MANUFACTURER_ID                                 0xc0   
  #define     MANUFACTURER_ID__VALUE                                          0x00ff  

  #define DEVICE_ID                                       0xc4   
  #define     DEVICE_ID__VALUE                                                0x00ff  

  #define DEVICE_PARAM_0                                  0xc8   
  #define     DEVICE_PARAM_0__VALUE                                           0x00ff  

  #define DEVICE_PARAM_1                                  0xcc   
  #define     DEVICE_PARAM_1__VALUE                                           0x00ff  

  #define DEVICE_PARAM_2                                  0xd0   
  #define     DEVICE_PARAM_2__VALUE                                           0x00ff  

  #define LOGICAL_PAGE_DATA_SIZE                          0xd4   
  #define     LOGICAL_PAGE_DATA_SIZE__VALUE                                   0xffff  

  #define LOGICAL_PAGE_SPARE_SIZE                         0xd8   
  #define     LOGICAL_PAGE_SPARE_SIZE__VALUE                                  0xffff  

  #define REVISION                                        0xdc   
  #define     REVISION__VALUE                                                 0xffff  

  #define ONFI_DEVICE_FEATURES                            0xe0   
  #define     ONFI_DEVICE_FEATURES__VALUE                                     0x003f  

  #define ONFI_OPTIONAL_COMMANDS                          0xe4   
  #define     ONFI_OPTIONAL_COMMANDS__VALUE                                   0x003f  

  #define ONFI_TIMING_MODE                                0xe8   
  #define     ONFI_TIMING_MODE__VALUE                                         0x003f  

  #define ONFI_PGM_CACHE_TIMING_MODE                      0xec   
  #define     ONFI_PGM_CACHE_TIMING_MODE__VALUE                               0x003f  

  #define ONFI_DEVICE_NO_OF_LUNS                          0xf0   
  #define     ONFI_DEVICE_NO_OF_LUNS__NO_OF_LUNS                              0x00ff  
  #define     ONFI_DEVICE_NO_OF_LUNS__ONFI_DEVICE                             0x0100  

  #define ONFI_DEVICE_NO_OF_BLOCKS_PER_LUN_L              0xf4   
  #define     ONFI_DEVICE_NO_OF_BLOCKS_PER_LUN_L__VALUE                       0xffff  

  #define ONFI_DEVICE_NO_OF_BLOCKS_PER_LUN_U              0xf8   
  #define     ONFI_DEVICE_NO_OF_BLOCKS_PER_LUN_U__VALUE                       0xffff  

  #define FEATURES                                        0xfc   
  #define     FEATURES__N_BANKS                                               0x0003  
  #define     FEATURES__ECC_MAX_ERR                                           0x003c  
  #define     FEATURES__DMA                                                   0x0040  
  #define     FEATURES__CMD_DMA                                               0x0080  
  #define     FEATURES__PARTITION                                             0x0100  
  #define     FEATURES__XDMA_SIDEBAND                                         0x0200  
  #define     FEATURES__GPREG                                                 0x0400  
  #define     FEATURES__INDEX_ADDR                                            0x0800  

  #define TRANSFER_MODE                                  0x100   
  #define     TRANSFER_MODE__VALUE                                            0x0003  

  #define INTR_STATUS0                                   0x104   
  #define     INTR_STATUS0__ECC_TRANSACTION_DONE                              0x0001  
  #define     INTR_STATUS0__ECC_ERR                                           0x0002  
  #define     INTR_STATUS0__DMA_CMD_COMP                                      0x0004  
  #define     INTR_STATUS0__TIME_OUT                                          0x0008  
  #define     INTR_STATUS0__PROGRAM_FAIL                                      0x0010  
  #define     INTR_STATUS0__ERASE_FAIL                                        0x0020  
  #define     INTR_STATUS0__LOAD_COMP                                         0x0040  
  #define     INTR_STATUS0__PROGRAM_COMP                                      0x0080  
  #define     INTR_STATUS0__ERASE_COMP                                        0x0100  
  #define     INTR_STATUS0__PIPE_CPYBCK_CMD_COMP                              0x0200  
  #define     INTR_STATUS0__LOCKED_BLK                                        0x0400  
  #define     INTR_STATUS0__UNSUP_CMD                                         0x0800  
  #define     INTR_STATUS0__INT_ACT                                           0x1000  
  #define     INTR_STATUS0__RST_COMP                                          0x2000  
  #define     INTR_STATUS0__PIPE_CMD_ERR                                      0x4000  
  #define     INTR_STATUS0__PAGE_XFER_INC                                     0x8000  

  #define INTR_EN0                                       0x108   
  #define     INTR_EN0__ECC_TRANSACTION_DONE                                  0x0001  
  #define     INTR_EN0__ECC_ERR                                               0x0002  
  #define     INTR_EN0__DMA_CMD_COMP                                          0x0004  
  #define     INTR_EN0__TIME_OUT                                              0x0008  
  #define     INTR_EN0__PROGRAM_FAIL                                          0x0010  
  #define     INTR_EN0__ERASE_FAIL                                            0x0020  
  #define     INTR_EN0__LOAD_COMP                                             0x0040  
  #define     INTR_EN0__PROGRAM_COMP                                          0x0080  
  #define     INTR_EN0__ERASE_COMP                                            0x0100  
  #define     INTR_EN0__PIPE_CPYBCK_CMD_COMP                                  0x0200  
  #define     INTR_EN0__LOCKED_BLK                                            0x0400  
  #define     INTR_EN0__UNSUP_CMD                                             0x0800  
  #define     INTR_EN0__INT_ACT                                               0x1000  
  #define     INTR_EN0__RST_COMP                                              0x2000  
  #define     INTR_EN0__PIPE_CMD_ERR                                          0x4000  
  #define     INTR_EN0__PAGE_XFER_INC                                         0x8000  

  #define PAGE_CNT0                                      0x10c   
  #define     PAGE_CNT0__VALUE                                                0x00ff  

  #define ERR_PAGE_ADDR0                                 0x110   
  #define     ERR_PAGE_ADDR0__VALUE                                           0xffff  

  #define ERR_BLOCK_ADDR0                                0x114   
  #define     ERR_BLOCK_ADDR0__VALUE                                          0xffff  

  #define INTR_STATUS1                                   0x118   
  #define     INTR_STATUS1__ECC_TRANSACTION_DONE                              0x0001  
  #define     INTR_STATUS1__ECC_ERR                                           0x0002  
  #define     INTR_STATUS1__DMA_CMD_COMP                                      0x0004  
  #define     INTR_STATUS1__TIME_OUT                                          0x0008  
  #define     INTR_STATUS1__PROGRAM_FAIL                                      0x0010  
  #define     INTR_STATUS1__ERASE_FAIL                                        0x0020  
  #define     INTR_STATUS1__LOAD_COMP                                         0x0040  
  #define     INTR_STATUS1__PROGRAM_COMP                                      0x0080  
  #define     INTR_STATUS1__ERASE_COMP                                        0x0100  
  #define     INTR_STATUS1__PIPE_CPYBCK_CMD_COMP                              0x0200  
  #define     INTR_STATUS1__LOCKED_BLK                                        0x0400  
  #define     INTR_STATUS1__UNSUP_CMD                                         0x0800  
  #define     INTR_STATUS1__INT_ACT                                           0x1000  
  #define     INTR_STATUS1__RST_COMP                                          0x2000  
  #define     INTR_STATUS1__PIPE_CMD_ERR                                      0x4000  
  #define     INTR_STATUS1__PAGE_XFER_INC                                     0x8000  

  #define INTR_EN1                                       0x11c   
  #define     INTR_EN1__ECC_TRANSACTION_DONE                                  0x0001  
  #define     INTR_EN1__ECC_ERR                                               0x0002  
  #define     INTR_EN1__DMA_CMD_COMP                                          0x0004  
  #define     INTR_EN1__TIME_OUT                                              0x0008  
  #define     INTR_EN1__PROGRAM_FAIL                                          0x0010  
  #define     INTR_EN1__ERASE_FAIL                                            0x0020  
  #define     INTR_EN1__LOAD_COMP                                             0x0040  
  #define     INTR_EN1__PROGRAM_COMP                                          0x0080  
  #define     INTR_EN1__ERASE_COMP                                            0x0100  
  #define     INTR_EN1__PIPE_CPYBCK_CMD_COMP                                  0x0200  
  #define     INTR_EN1__LOCKED_BLK                                            0x0400  
  #define     INTR_EN1__UNSUP_CMD                                             0x0800  
  #define     INTR_EN1__INT_ACT                                               0x1000  
  #define     INTR_EN1__RST_COMP                                              0x2000  
  #define     INTR_EN1__PIPE_CMD_ERR                                          0x4000  
  #define     INTR_EN1__PAGE_XFER_INC                                         0x8000  

  #define PAGE_CNT1                                      0x120   
  #define     PAGE_CNT1__VALUE                                                0x00ff  

  #define ERR_PAGE_ADDR1                                 0x124   
  #define     ERR_PAGE_ADDR1__VALUE                                           0xffff  

  #define ERR_BLOCK_ADDR1                                0x128   
  #define     ERR_BLOCK_ADDR1__VALUE                                          0xffff  

  #define INTR_STATUS2                                   0x12c   
  #define     INTR_STATUS2__ECC_TRANSACTION_DONE                              0x0001  
  #define     INTR_STATUS2__ECC_ERR                                           0x0002  
  #define     INTR_STATUS2__DMA_CMD_COMP                                      0x0004  
  #define     INTR_STATUS2__TIME_OUT                                          0x0008  
  #define     INTR_STATUS2__PROGRAM_FAIL                                      0x0010  
  #define     INTR_STATUS2__ERASE_FAIL                                        0x0020  
  #define     INTR_STATUS2__LOAD_COMP                                         0x0040  
  #define     INTR_STATUS2__PROGRAM_COMP                                      0x0080  
  #define     INTR_STATUS2__ERASE_COMP                                        0x0100  
  #define     INTR_STATUS2__PIPE_CPYBCK_CMD_COMP                              0x0200  
  #define     INTR_STATUS2__LOCKED_BLK                                        0x0400  
  #define     INTR_STATUS2__UNSUP_CMD                                         0x0800  
  #define     INTR_STATUS2__INT_ACT                                           0x1000  
  #define     INTR_STATUS2__RST_COMP                                          0x2000  
  #define     INTR_STATUS2__PIPE_CMD_ERR                                      0x4000  
  #define     INTR_STATUS2__PAGE_XFER_INC                                     0x8000  

  #define INTR_EN2                                       0x130   
  #define     INTR_EN2__ECC_TRANSACTION_DONE                                  0x0001  
  #define     INTR_EN2__ECC_ERR                                               0x0002  
  #define     INTR_EN2__DMA_CMD_COMP                                          0x0004  
  #define     INTR_EN2__TIME_OUT                                              0x0008  
  #define     INTR_EN2__PROGRAM_FAIL                                          0x0010  
  #define     INTR_EN2__ERASE_FAIL                                            0x0020  
  #define     INTR_EN2__LOAD_COMP                                             0x0040  
  #define     INTR_EN2__PROGRAM_COMP                                          0x0080  
  #define     INTR_EN2__ERASE_COMP                                            0x0100  
  #define     INTR_EN2__PIPE_CPYBCK_CMD_COMP                                  0x0200  
  #define     INTR_EN2__LOCKED_BLK                                            0x0400  
  #define     INTR_EN2__UNSUP_CMD                                             0x0800  
  #define     INTR_EN2__INT_ACT                                               0x1000  
  #define     INTR_EN2__RST_COMP                                              0x2000  
  #define     INTR_EN2__PIPE_CMD_ERR                                          0x4000  
  #define     INTR_EN2__PAGE_XFER_INC                                         0x8000  

  #define PAGE_CNT2                                      0x134   
  #define     PAGE_CNT2__VALUE                                                0x00ff  

  #define ERR_PAGE_ADDR2                                 0x138   
  #define     ERR_PAGE_ADDR2__VALUE                                           0xffff  

  #define ERR_BLOCK_ADDR2                                0x13c   
  #define     ERR_BLOCK_ADDR2__VALUE                                          0xffff  

  #define INTR_STATUS3                                   0x140   
  #define     INTR_STATUS3__ECC_TRANSACTION_DONE                              0x0001  
  #define     INTR_STATUS3__ECC_ERR                                           0x0002  
  #define     INTR_STATUS3__DMA_CMD_COMP                                      0x0004  
  #define     INTR_STATUS3__TIME_OUT                                          0x0008  
  #define     INTR_STATUS3__PROGRAM_FAIL                                      0x0010  
  #define     INTR_STATUS3__ERASE_FAIL                                        0x0020  
  #define     INTR_STATUS3__LOAD_COMP                                         0x0040  
  #define     INTR_STATUS3__PROGRAM_COMP                                      0x0080  
  #define     INTR_STATUS3__ERASE_COMP                                        0x0100  
  #define     INTR_STATUS3__PIPE_CPYBCK_CMD_COMP                              0x0200  
  #define     INTR_STATUS3__LOCKED_BLK                                        0x0400  
  #define     INTR_STATUS3__UNSUP_CMD                                         0x0800  
  #define     INTR_STATUS3__INT_ACT                                           0x1000  
  #define     INTR_STATUS3__RST_COMP                                          0x2000  
  #define     INTR_STATUS3__PIPE_CMD_ERR                                      0x4000  
  #define     INTR_STATUS3__PAGE_XFER_INC                                     0x8000  

  #define INTR_EN3                                       0x144   
  #define     INTR_EN3__ECC_TRANSACTION_DONE                                  0x0001  
  #define     INTR_EN3__ECC_ERR                                               0x0002  
  #define     INTR_EN3__DMA_CMD_COMP                                          0x0004  
  #define     INTR_EN3__TIME_OUT                                              0x0008  
  #define     INTR_EN3__PROGRAM_FAIL                                          0x0010  
  #define     INTR_EN3__ERASE_FAIL                                            0x0020  
  #define     INTR_EN3__LOAD_COMP                                             0x0040  
  #define     INTR_EN3__PROGRAM_COMP                                          0x0080  
  #define     INTR_EN3__ERASE_COMP                                            0x0100  
  #define     INTR_EN3__PIPE_CPYBCK_CMD_COMP                                  0x0200  
  #define     INTR_EN3__LOCKED_BLK                                            0x0400  
  #define     INTR_EN3__UNSUP_CMD                                             0x0800  
  #define     INTR_EN3__INT_ACT                                               0x1000  
  #define     INTR_EN3__RST_COMP                                              0x2000  
  #define     INTR_EN3__PIPE_CMD_ERR                                          0x4000  
  #define     INTR_EN3__PAGE_XFER_INC                                         0x8000  

  #define PAGE_CNT3                                      0x148   
  #define     PAGE_CNT3__VALUE                                                0x00ff  

  #define ERR_PAGE_ADDR3                                 0x14c   
  #define     ERR_PAGE_ADDR3__VALUE                                           0xffff  

  #define ERR_BLOCK_ADDR3                                0x150   
  #define     ERR_BLOCK_ADDR3__VALUE                                          0xffff  

  #define DATA_INTR                                      0x154   
  #define     DATA_INTR__WRITE_SPACE_AV                                       0x0001  
  #define     DATA_INTR__READ_DATA_AV                                         0x0002  

  #define DATA_INTR_EN                                   0x158   
  #define     DATA_INTR_EN__WRITE_SPACE_AV                                    0x0001  
  #define     DATA_INTR_EN__READ_DATA_AV                                      0x0002  

  #define GPREG_0                                        0x15c   
  #define     GPREG_0__VALUE                                                  0xffff  

  #define GPREG_1                                        0x160   
  #define     GPREG_1__VALUE                                                  0xffff  

  #define GPREG_2                                        0x164   
  #define     GPREG_2__VALUE                                                  0xffff  

  #define GPREG_3                                        0x168   
  #define     GPREG_3__VALUE                                                  0xffff  

  #define ECC_THRESHOLD                                  0x180   
  #define     ECC_THRESHOLD__VALUE                                            0x03ff  

  #define ECC_ERROR_BLOCK_ADDRESS                        0x184   
  #define     ECC_ERROR_BLOCK_ADDRESS__VALUE                                  0xffff  

  #define ECC_ERROR_PAGE_ADDRESS                         0x188   
  #define     ECC_ERROR_PAGE_ADDRESS__VALUE                                   0x0fff  
  #define     ECC_ERROR_PAGE_ADDRESS__BANK                                    0xf000  

  #define ECC_ERROR_ADDRESS                              0x18c   
  #define     ECC_ERROR_ADDRESS__OFFSET                                       0x0fff  
  #define     ECC_ERROR_ADDRESS__SECTOR_NR                                    0xf000  

  #define ERR_CORRECTION_INFO                            0x190   
  #define     ERR_CORRECTION_INFO__BYTEMASK                                   0x00ff  
  #define     ERR_CORRECTION_INFO__DEVICE_NR                                  0x0f00  
  #define     ERR_CORRECTION_INFO__ERROR_TYPE                                 0x4000  
  #define     ERR_CORRECTION_INFO__LAST_ERR_INFO                              0x8000  

  #define DMA_ENABLE                                     0x1c0   
  #define     DMA_ENABLE__FLAG                                                0x0001  

  #define IGNORE_ECC_DONE                                0x1c4   
  #define     IGNORE_ECC_DONE__FLAG                                           0x0001  

  #define DMA_INTR                                       0x1c8   
  #define     DMA_INTR__TARGET_ERROR                                          0x0001  
  #define     DMA_INTR__DESC_COMP_CHANNEL0                                    0x0002  
  #define     DMA_INTR__DESC_COMP_CHANNEL1                                    0x0004  
  #define     DMA_INTR__DESC_COMP_CHANNEL2                                    0x0008  
  #define     DMA_INTR__DESC_COMP_CHANNEL3                                    0x0010  
  #define     DMA_INTR__MEMCOPY_DESC_COMP                                     0x0020  

  #define DMA_INTR_EN                                    0x1cc   
  #define     DMA_INTR_EN__TARGET_ERROR                                       0x0001  
  #define     DMA_INTR_EN__DESC_COMP_CHANNEL0                                 0x0002  
  #define     DMA_INTR_EN__DESC_COMP_CHANNEL1                                 0x0004  
  #define     DMA_INTR_EN__DESC_COMP_CHANNEL2                                 0x0008  
  #define     DMA_INTR_EN__DESC_COMP_CHANNEL3                                 0x0010  
  #define     DMA_INTR_EN__MEMCOPY_DESC_COMP                                  0x0020  

  #define TARGET_ERR_ADDR_LO                             0x1d0   
  #define     TARGET_ERR_ADDR_LO__VALUE                                       0xffff  

  #define TARGET_ERR_ADDR_HI                             0x1d4   
  #define     TARGET_ERR_ADDR_HI__VALUE                                       0xffff  

  #define CHNL_ACTIVE                                    0x1d8   
  #define     CHNL_ACTIVE__CHANNEL0                                           0x0001  
  #define     CHNL_ACTIVE__CHANNEL1                                           0x0002  
  #define     CHNL_ACTIVE__CHANNEL2                                           0x0004  
  #define     CHNL_ACTIVE__CHANNEL3                                           0x0008  

  #define ACTIVE_SRC_ID                                  0x200   
  #define     ACTIVE_SRC_ID__VALUE                                            0x00ff  

  #define PTN_INTR                                       0x204   
  #define     PTN_INTR__CONFIG_ERROR                                          0x0001  
  #define     PTN_INTR__ACCESS_ERROR_BANK0                                    0x0002  
  #define     PTN_INTR__ACCESS_ERROR_BANK1                                    0x0004  
  #define     PTN_INTR__ACCESS_ERROR_BANK2                                    0x0008  
  #define     PTN_INTR__ACCESS_ERROR_BANK3                                    0x0010  
  #define     PTN_INTR__REG_ACCESS_ERROR                                      0x0020  

  #define PTN_INTR_EN                                    0x208   
  #define     PTN_INTR_EN__CONFIG_ERROR                                       0x0001  
  #define     PTN_INTR_EN__ACCESS_ERROR_BANK0                                 0x0002  
  #define     PTN_INTR_EN__ACCESS_ERROR_BANK1                                 0x0004  
  #define     PTN_INTR_EN__ACCESS_ERROR_BANK2                                 0x0008  
  #define     PTN_INTR_EN__ACCESS_ERROR_BANK3                                 0x0010  
  #define     PTN_INTR_EN__REG_ACCESS_ERROR                                   0x0020  

  #define PERM_SRC_ID_0                                  0x20c   
  #define     PERM_SRC_ID_0__SRCID                                            0x00ff  
  #define     PERM_SRC_ID_0__DIRECT_ACCESS_ACTIVE                             0x0800  
  #define     PERM_SRC_ID_0__WRITE_ACTIVE                                     0x2000  
  #define     PERM_SRC_ID_0__READ_ACTIVE                                      0x4000  
  #define     PERM_SRC_ID_0__PARTITION_VALID                                  0x8000  

  #define MIN_BLK_ADDR_0                                 0x210   
  #define     MIN_BLK_ADDR_0__VALUE                                           0xffff  

  #define MAX_BLK_ADDR_0                                 0x214   
  #define     MAX_BLK_ADDR_0__VALUE                                           0xffff  

  #define MIN_MAX_BANK_0                                 0x218   
  #define     MIN_MAX_BANK_0__MIN_VALUE                                       0x0003  
  #define     MIN_MAX_BANK_0__MAX_VALUE                                       0x000c  

  #define PERM_SRC_ID_1                                  0x21c   
  #define     PERM_SRC_ID_1__SRCID                                            0x00ff  
  #define     PERM_SRC_ID_1__DIRECT_ACCESS_ACTIVE                             0x0800  
  #define     PERM_SRC_ID_1__WRITE_ACTIVE                                     0x2000  
  #define     PERM_SRC_ID_1__READ_ACTIVE                                      0x4000  
  #define     PERM_SRC_ID_1__PARTITION_VALID                                  0x8000  

  #define MIN_BLK_ADDR_1                                 0x220   
  #define     MIN_BLK_ADDR_1__VALUE                                           0xffff  

  #define MAX_BLK_ADDR_1                                 0x224   
  #define     MAX_BLK_ADDR_1__VALUE                                           0xffff  

  #define MIN_MAX_BANK_1                                 0x228   
  #define     MIN_MAX_BANK_1__MIN_VALUE                                       0x0003  
  #define     MIN_MAX_BANK_1__MAX_VALUE                                       0x000c  

  #define PERM_SRC_ID_2                                  0x22c   
  #define     PERM_SRC_ID_2__SRCID                                            0x00ff  
  #define     PERM_SRC_ID_2__DIRECT_ACCESS_ACTIVE                             0x0800  
  #define     PERM_SRC_ID_2__WRITE_ACTIVE                                     0x2000  
  #define     PERM_SRC_ID_2__READ_ACTIVE                                      0x4000  
  #define     PERM_SRC_ID_2__PARTITION_VALID                                  0x8000  

  #define MIN_BLK_ADDR_2                                 0x230   
  #define     MIN_BLK_ADDR_2__VALUE                                           0xffff  

  #define MAX_BLK_ADDR_2                                 0x234   
  #define     MAX_BLK_ADDR_2__VALUE                                           0xffff  

  #define MIN_MAX_BANK_2                                 0x238   
  #define     MIN_MAX_BANK_2__MIN_VALUE                                       0x0003  
  #define     MIN_MAX_BANK_2__MAX_VALUE                                       0x000c  

  #define PERM_SRC_ID_3                                  0x23c   
  #define     PERM_SRC_ID_3__SRCID                                            0x00ff  
  #define     PERM_SRC_ID_3__DIRECT_ACCESS_ACTIVE                             0x0800  
  #define     PERM_SRC_ID_3__WRITE_ACTIVE                                     0x2000  
  #define     PERM_SRC_ID_3__READ_ACTIVE                                      0x4000  
  #define     PERM_SRC_ID_3__PARTITION_VALID                                  0x8000  

  #define MIN_BLK_ADDR_3                                 0x240   
  #define     MIN_BLK_ADDR_3__VALUE                                           0xffff  

  #define MAX_BLK_ADDR_3                                 0x244   
  #define     MAX_BLK_ADDR_3__VALUE                                           0xffff  

  #define MIN_MAX_BANK_3                                 0x248   
  #define     MIN_MAX_BANK_3__MIN_VALUE                                       0x0003  
  #define     MIN_MAX_BANK_3__MAX_VALUE                                       0x000c  

  #define PERM_SRC_ID_4                                  0x24c   
  #define     PERM_SRC_ID_4__SRCID                                            0x00ff  
  #define     PERM_SRC_ID_4__DIRECT_ACCESS_ACTIVE                             0x0800  
  #define     PERM_SRC_ID_4__WRITE_ACTIVE                                     0x2000  
  #define     PERM_SRC_ID_4__READ_ACTIVE                                      0x4000  
  #define     PERM_SRC_ID_4__PARTITION_VALID                                  0x8000  

  #define MIN_BLK_ADDR_4                                 0x250   
  #define     MIN_BLK_ADDR_4__VALUE                                           0xffff  

  #define MAX_BLK_ADDR_4                                 0x254   
  #define     MAX_BLK_ADDR_4__VALUE                                           0xffff  

  #define MIN_MAX_BANK_4                                 0x258   
  #define     MIN_MAX_BANK_4__MIN_VALUE                                       0x0003  
  #define     MIN_MAX_BANK_4__MAX_VALUE                                       0x000c  

  #define PERM_SRC_ID_5                                  0x25c   
  #define     PERM_SRC_ID_5__SRCID                                            0x00ff  
  #define     PERM_SRC_ID_5__DIRECT_ACCESS_ACTIVE                             0x0800  
  #define     PERM_SRC_ID_5__WRITE_ACTIVE                                     0x2000  
  #define     PERM_SRC_ID_5__READ_ACTIVE                                      0x4000  
  #define     PERM_SRC_ID_5__PARTITION_VALID                                  0x8000  

  #define MIN_BLK_ADDR_5                                 0x260   
  #define     MIN_BLK_ADDR_5__VALUE                                           0xffff  

  #define MAX_BLK_ADDR_5                                 0x264   
  #define     MAX_BLK_ADDR_5__VALUE                                           0xffff  

  #define MIN_MAX_BANK_5                                 0x268   
  #define     MIN_MAX_BANK_5__MIN_VALUE                                       0x0003  
  #define     MIN_MAX_BANK_5__MAX_VALUE                                       0x000c  

  #define PERM_SRC_ID_6                                  0x26c   
  #define     PERM_SRC_ID_6__SRCID                                            0x00ff  
  #define     PERM_SRC_ID_6__DIRECT_ACCESS_ACTIVE                             0x0800  
  #define     PERM_SRC_ID_6__WRITE_ACTIVE                                     0x2000  
  #define     PERM_SRC_ID_6__READ_ACTIVE                                      0x4000  
  #define     PERM_SRC_ID_6__PARTITION_VALID                                  0x8000  

  #define MIN_BLK_ADDR_6                                 0x270   
  #define     MIN_BLK_ADDR_6__VALUE                                           0xffff  

  #define MAX_BLK_ADDR_6                                 0x274   
  #define     MAX_BLK_ADDR_6__VALUE                                           0xffff  

  #define MIN_MAX_BANK_6                                 0x278   
  #define     MIN_MAX_BANK_6__MIN_VALUE                                       0x0003  
  #define     MIN_MAX_BANK_6__MAX_VALUE                                       0x000c  

  #define PERM_SRC_ID_7                                  0x27c   
  #define     PERM_SRC_ID_7__SRCID                                            0x00ff  
  #define     PERM_SRC_ID_7__DIRECT_ACCESS_ACTIVE                             0x0800  
  #define     PERM_SRC_ID_7__WRITE_ACTIVE                                     0x2000  
  #define     PERM_SRC_ID_7__READ_ACTIVE                                      0x4000  
  #define     PERM_SRC_ID_7__PARTITION_VALID                                  0x8000  

  #define MIN_BLK_ADDR_7                                 0x280   
  #define     MIN_BLK_ADDR_7__VALUE                                           0xffff  

  #define MAX_BLK_ADDR_7                                 0x284   
  #define     MAX_BLK_ADDR_7__VALUE                                           0xffff  

  #define MIN_MAX_BANK_7                                 0x288   
  #define     MIN_MAX_BANK_7__MIN_VALUE                                       0x0003  
  #define     MIN_MAX_BANK_7__MAX_VALUE                                       0x000c  
