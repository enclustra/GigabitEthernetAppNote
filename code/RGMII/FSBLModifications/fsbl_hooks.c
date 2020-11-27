/******************************************************************************
*
* Copyright (C) 2015 -18 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
*
*
******************************************************************************/

/*****************************************************************************/
/**
*
* @file xfsbl_hooks.c
*
* This is the file which contains FSBL hook functions.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date        Changes
* ----- ---- -------- -------------------------------------------------------
* 1.00  kc   04/21/14 Initial release
* 2.0   bv   12/05/16 Made compliance to MISRAC 2012 guidelines
*       ssc  03/25/17 Set correct value for SYSMON ANALOG_BUS register
*
* </pre>
*
* @note
*
******************************************************************************/
/***************************** Include Files *********************************/
#include "xfsbl_hw.h"
#include "xfsbl_hooks.h"
#include "psu_init.h"
#include "xemacps.h"

//-------------------------------------------------------------------------------------------------
// Enclustra Includes
//-------------------------------------------------------------------------------------------------

#include "I2cInterface.h"
#include "InterruptController.h"
#include "ModuleEeprom.h"
/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Function Prototypes ******************************/
static int ConfigEthPhy(void);
/************************** Variable Definitions *****************************/

#ifdef XFSBL_BS
u32 XFsbl_HookBeforeBSDownload(void )
{
	u32 Status = XFSBL_SUCCESS;

	/**
	 * Add the code here
	 */


	return Status;
}


u32 XFsbl_HookAfterBSDownload(void )
{
	u32 Status = XFSBL_SUCCESS;

	/**
	 * Add the code here
	 */

	return Status;
}
#endif

u32 XFsbl_HookBeforeHandoff(u32 EarlyHandoff)
{
	u32 Status = XFSBL_SUCCESS;

	Status = ConfigEthPhy();
	if (Status != XST_SUCCESS) {
		XFsbl_Printf(DEBUG_GENERAL,"Error configuring PHY\n\r");
	} else {
		XFsbl_Printf(DEBUG_GENERAL,"PHY configured\n\r");
	}

	return Status;
}

/*****************************************************************************/
/**
 * This is a hook function where user can include the functionality to be run
 * before FSBL fallback happens
 *
 * @param none
 *
 * @return error status based on implemented functionality (SUCCESS by default)
 *
  *****************************************************************************/

u32 XFsbl_HookBeforeFallback(void)
{
	u32 Status = XFSBL_SUCCESS;

	/**
	 * Add the code here
	 */

	return Status;
}

/*****************************************************************************/
/**
 * This function facilitates users to define different variants of psu_init()
 * functions based on different configurations in Vivado. The default call to
 * psu_init() can then be swapped with the alternate variant based on the
 * requirement.
 *
 * @param none
 *
 * @return error status based on implemented functionality (SUCCESS by default)
 *
  *****************************************************************************/

u32 XFsbl_HookPsuInit(void)
{
	u32 Status;
#ifdef XFSBL_ENABLE_DDR_SR
	u32 RegVal;
#endif

	/* Add the code here */

#ifdef XFSBL_ENABLE_DDR_SR
	/* Check if DDR is in self refresh mode */
	RegVal = Xil_In32(XFSBL_DDR_STATUS_REGISTER_OFFSET) &
		DDR_STATUS_FLAG_MASK;
	if (RegVal) {
		Status = (u32)psu_init_ddr_self_refresh();
	} else {
		Status = (u32)psu_init();
	}
#else
	Status = (u32)psu_init();
#endif

	if (XFSBL_SUCCESS != Status) {
			XFsbl_Printf(DEBUG_GENERAL,"XFSBL_PSU_INIT_FAILED\n\r");
			/**
			 * Need to check a way to communicate both FSBL code
			 * and PSU init error code
			 */
			Status = XFSBL_PSU_INIT_FAILED + Status;
	}

	/**
	 * PS_SYSMON_ANALOG_BUS register determines mapping between SysMon supply
	 * sense channel to SysMon supply registers inside the IP. This register
	 * must be programmed to complete SysMon IP configuration.
	 * The default register configuration after power-up is incorrect.
	 * Hence, fix this by writing the correct value - 0x3210.
	 */

	XFsbl_Out32(AMS_PS_SYSMON_ANALOG_BUS, PS_SYSMON_ANALOG_BUS_VAL);

	return Status;
}

/*****************************************************************************/
/**
 * This function detects type of boot based on information from
 * PMU_GLOBAL_GLOB_GEN_STORAGE1. If Power Off Suspend is supported FSBL must
 * wait for PMU to detect boot type and provide that information using register.
 * In case of resume from Power Off Suspend PMU will wait for FSBL to confirm
 * detection by writing 1 to PMU_GLOBAL_GLOB_GEN_STORAGE2.
 *
 * @return Boot type, 0 in case of cold boot, 1 for warm boot
 *
 * @note none
 *****************************************************************************/
#ifdef ENABLE_POS
u32 XFsbl_HookGetPosBootType(void)
{
	u32 WarmBoot = 0;
	u32 RegValue = 0;

	do {
		RegValue = XFsbl_In32(PMU_GLOBAL_GLOB_GEN_STORAGE1);
	} while (0U == RegValue);

	/* Clear Gen Storage register so it can be used later in system */
	XFsbl_Out32(PMU_GLOBAL_GLOB_GEN_STORAGE1, 0U);

	WarmBoot = RegValue - 1;

	/* Confirm detection in case of resume from Power Off Suspend */
	if (0 != RegValue) {
		XFsbl_Out32(PMU_GLOBAL_GLOB_GEN_STORAGE2, 1U);
	}

	return WarmBoot;
}
#endif

static int ConfigEthPhy(void)
{

	XEmacPs EmacPsInstance;
	XEmacPs *EmacPsInstancePtr = (XEmacPs*) &EmacPsInstance;
	int Status;
	u16 PhyData, PhyAddr, PhyType;
	XEmacPs_Config *Config;
	volatile int i;

    uint32_t serialNumber;
    ProductNumberInfo_t productNumberInfo;
    uint8_t macAddress[6];
    char EmacPsMAC[6];
    int MacAddrSet = 0;

    // Initialise the EEPROM.
	if (EN_SUCCEEDED(Eeprom_Initialise()))
    {
		// Read the EEPROM.
		if (EN_SUCCEEDED(Eeprom_Read()))
		{
		    // After reading the EEPROM, the information is stored in its own translation unit - we can
		    // query it using the EEPROM API functions.
			if (EN_SUCCEEDED(Eeprom_GetModuleInfo(&serialNumber, &productNumberInfo, (uint64_t*)&macAddress))){
				XFsbl_Printf(DEBUG_GENERAL,"MAC address configured successfully from EEPROM\n\r");
				EmacPsMAC[0] = macAddress[5];
				EmacPsMAC[1] = macAddress[4];
				EmacPsMAC[2] = macAddress[3];
				EmacPsMAC[3] = macAddress[2];
				EmacPsMAC[4] = macAddress[1];
				EmacPsMAC[5] = macAddress[0];
				MacAddrSet = 1;
			}

		}
    }
	if (MacAddrSet == 0){
		EN_PRINTF("Error reading EEPROM, using default MAC address\n\r");
		EmacPsMAC[0] = 0x00;
		EmacPsMAC[1] = 0x0a;
		EmacPsMAC[2] = 0x35;
		EmacPsMAC[3] = 0x01;
		EmacPsMAC[4] = 0x02;
		EmacPsMAC[5] = 0x03;
	}


	Config = XEmacPs_LookupConfig(XPAR_XEMACPS_0_DEVICE_ID);

	Status = XEmacPs_CfgInitialize(EmacPsInstancePtr, Config,
					Config->BaseAddress);

	if (Status != XST_SUCCESS) {
		XFsbl_Printf(DEBUG_INFO,"Error in initialize\n\r");
		return XST_FAILURE;
	}

	/*
	 * Set the MAC address
	 */
	Status = XEmacPs_SetMacAddress(EmacPsInstancePtr, EmacPsMAC, 1);
	if (Status != XST_SUCCESS) {
		XFsbl_Printf(DEBUG_INFO,"Error setting MAC address\n\r");
		return XST_FAILURE;
	}

	XEmacPs_SetMdioDivisor(EmacPsInstancePtr, MDC_DIV_224);

	// detect PHY
	PhyAddr = 3;
	XEmacPs_PhyRead(EmacPsInstancePtr, PhyAddr, 0x3, (u16*)&PhyData);  // read value
	PhyType = (PhyData >> 4);

	// enabling RGMII delays
	if (PhyType == 0x162){ // KSZ9031
		XFsbl_Printf(DEBUG_GENERAL,"Detected KSZ9031 Ethernet PHY\n\r");
		//Ctrl Delay
		u16 RxCtrlDelay=7; // 0..15, default 7
		u16 TxCtrlDelay=7; // 0..15, default 7
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xD, 0x0002);
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xE, 0x0004); // Reg 0x4
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xD, 0x4002);
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xE, (TxCtrlDelay+(RxCtrlDelay<<4)));
		//Data Delay
		u16 RxDataDelay=7; // 0..15, default 7
		u16 TxDataDelay=7; // 0..15, default 7
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xD, 0x0002);
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xE, 0x0005); // Reg 0x5
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xD, 0x4002);
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xE, (RxDataDelay+(RxDataDelay << 4)+(RxDataDelay << 8)+(RxDataDelay << 12)));
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xD, 0x0002);
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xE, 0x0006); // Reg 0x6
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xD, 0x4002);
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xE, (TxDataDelay+(TxDataDelay << 4)+(TxDataDelay << 8)+(TxDataDelay << 12)));
		//Clock Delay
		u16 RxClockDelay=31; // 0..31, default 15
		u16 TxClockDelay=31; // 0..31, default 15
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xD, 0x0002);
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xE, 0x0008); // Reg 0x8 RGMII Clock Pad Skew
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xD, 0x4002);
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xE, (RxClockDelay+(TxClockDelay<<5)));
	} else if (PhyType == 0x161){ // KSZ9021
		XFsbl_Printf(DEBUG_GENERAL,"Detected KSZ9021 Ethernet PHY\n\r");
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xB, 0x8104); // write Reg 0x104
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xC, 0xF0F0); // set write data
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xB, 0x8105); // write Reg 0x105
		XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0xC, 0x0000); // set write data
	}

	// Issue a reset to phy
	Status  = XEmacPs_PhyRead(EmacPsInstancePtr, PhyAddr, 0x0, &PhyData);
	PhyData |= 0x8000;
	Status = XEmacPs_PhyWrite(EmacPsInstancePtr, PhyAddr, 0x0, PhyData);
	for (i=0; i<100000; i++);
	Status |= XEmacPs_PhyRead(EmacPsInstancePtr, PhyAddr, 0x0, &PhyData);
	if (Status != XST_SUCCESS)
	{
		XFsbl_Printf(DEBUG_GENERAL,"Error reset phy \n\r");
		return -1;
	} else {
		return 0;
	}
}
