/*
 * (C) Copyright 2012 Xilinx
 *
 * Configuration settings for the Xilinx Zynq ZC770 board.
 * See zynq_common.h for Zynq common configs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_ZYNQ_ZC770_H
#define __CONFIG_ZYNQ_ZC770_H

/*
 * High Level Configuration Options
 */
#define CONFIG_ZC770 /* Board */

#include <configs/zynq_common.h>

/* Default environment */
#define CONFIG_IPADDR   10.10.70.102
#define CONFIG_SERVERIP 10.10.70.101

#if defined(CONFIG_ZC770_XM012)
#undef CONFIG_SYS_NO_FLASH
#else
#define CONFIG_SYS_NO_FLASH
#endif

#include <config_cmd_default.h>	
#define CONFIG_CMD_DATE		/* RTC? */
#define CONFIG_CMD_SAVEENV	/* Command to save ENV to Flash */
#define CONFIG_REGINFO		/* Again, debugging */
#undef CONFIG_CMD_SETGETDCR	/* README says 4xx only */

#define CONFIG_TIMESTAMP	/* print image timestamp on bootm, etc */

#define CONFIG_PANIC_HANG /* For development/debugging */

#define CONFIG_AUTO_COMPLETE
#define CONFIG_CMDLINE_EDITING

/* this is to initialize GEM at uboot start */
/* #define CONFIG_ZYNQ_INIT_GEM	*/
/* this is to set ipaddr, ethaddr and serverip env variables. */
#define CONFIG_ZYNQ_IP_ENV

#if defined(CONFIG_ZC770_XM010) || defined(CONFIG_ZC770_XM012)
/* Place a Xilinx Boot ROM header in u-boot image? */
#define CONFIG_ZYNQ_XILINX_FLASH_HEADER
#endif

/*
 * NOR Flash Settings
 */
#ifndef CONFIG_SYS_NO_FLASH

#define CONFIG_SYS_FLASH_BASE           0xE2000000 
#define CONFIG_SYS_FLASH_SIZE           (16 * 1024 * 1024)
#define CONFIG_SYS_MAX_FLASH_BANKS      1
/* max number of sectors/blocks on one chip */
#define CONFIG_SYS_MAX_FLASH_SECT       512
#define CONFIG_SYS_FLASH_ERASE_TOUT     1000
#define CONFIG_SYS_FLASH_WRITE_TOUT     5000
#define CONFIG_FLASH_SHOW_PROGRESS	10

#define CONFIG_SYS_FLASH_CFI
#undef CONFIG_SYS_FLASH_EMPTY_INFO
#define CONFIG_FLASH_CFI_DRIVER
#undef CONFIG_SYS_FLASH_PROTECTION /* don't use hardware protection */
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE /* use buffered writes (20x faster) */
#define CONFIG_ENV_OFFSET		0xC0000		/*768 KB*/
#define CONFIG_ENV_SECT_SIZE    	0x20000		/*128 KB*/
#define CONFIG_ENV_IS_IN_FLASH
#ifdef CONFIG_ZYNQ_XILINX_FLASH_HEADER
#define CONFIG_ZYNQ_XIP_START CONFIG_SYS_FLASH_BASE
#endif
#else
#define CONFIG_ENV_IS_NOWHERE
#endif

/*
 * Physical Memory map
 */
#define PHYS_SDRAM_1_SIZE (1024 * 1024 * 1024)

#if defined(CONFIG_ZC770_XM010) || defined(CONFIG_ZC770_XM011) \
	|| defined(CONFIG_ZC770_XM012)
#define CONFIG_UART1
#else
#define CONFIG_UART0
#endif

/*
 * Ethernet Settings
 */
#if defined(CONFIG_ZC770_XM010) || defined(CONFIG_ZC770_XM013)
#define CONFIG_CMD_PING
#define CONFIG_ZYNQ_GEM
#define CONFIG_XGMAC_PHY_ADDR 0x7
#else
#undef CONFIG_CMD_NET
#undef CONFIG_CMD_NFS
#undef CONFIG_BOOTM_NETBSD
#endif

/*
 * SPI Settings
 */
#if defined(CONFIG_ZC770_XM010) || defined(CONFIG_ZC770_XM013)
#define CONFIG_ZYNQ_SPI
#define CONFIG_CMD_SPI
#define CONFIG_SF_DEFAULT_SPEED 30000000
#define CONFIG_SPI_FLASH
#define CONFIG_CMD_SF

#ifdef CONFIG_ZYNQ_XILINX_FLASH_HEADER
/* Address Xilinx boot rom should use to launch u-boot */
#define CONFIG_ZYNQ_XIP_START XPSS_QSPI_LIN_BASEADDR
#endif
#endif

#if defined(CONFIG_ZC770_XM013)
#define CONFIG_GEM1
#define CONFIG_TTC1
#define CONFIG_SPI_FLASH_SPANSION
#endif

#if defined(CONFIG_ZC770_XM010)
#define CONFIG_GEM0
#define CONFIG_TTC0
#define CONFIG_SPI_FLASH_STMICRO
#endif

/*
 * NAND Flash settings
 */
#if defined(CONFIG_ZC770_XM011)
#define CONFIG_NAND_ZYNQ
#define CONFIG_CMD_NAND
#define CONFIG_CMD_NAND_LOCK_UNLOCK
#define CONFIG_SYS_MAX_NAND_DEVICE 1
#define CONFIG_SYS_NAND_BASE XPSS_NAND_BASEADDR
#define CONFIG_SYS_NAND_ONFI_DETECTION
#define CONFIG_MTD_DEVICE
#endif

#if defined(CONFIG_ZC770_XM010)
/* Secure Digital */
#define CONFIG_MMC

#ifdef CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_ZYNQ_MMC
#define CONFIG_CMD_MMC
#define CONFIG_CMD_FAT
#define CONFIG_CMD_EXT2
#define CONFIG_DOS_PARTITION
#endif
#endif

#endif /* __CONFIG_ZYNQ_ZC770_H */
