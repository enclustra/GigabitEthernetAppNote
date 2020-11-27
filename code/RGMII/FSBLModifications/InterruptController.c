/**---------------------------------------------------------------------------------------------------
-- Copyright (c) 2020 by Enclustra GmbH, Switzerland.
--
-- Permission is hereby granted, free of charge, to any person obtaining a copy of
-- this hardware, software, firmware, and associated documentation files (the
-- "Product"), to deal in the Product without restriction, including without
-- limitation the rights to use, copy, modify, merge, publish, distribute,
-- sublicense, and/or sell copies of the Product, and to permit persons to whom the
-- Product is furnished to do so, subject to the following conditions:
--
-- The above copyright notice and this permission notice shall be included in all
-- copies or substantial portions of the Product.
--
-- THE PRODUCT IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
-- INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
-- PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
-- HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
-- OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
-- PRODUCT OR THE USE OR OTHER DEALINGS IN THE PRODUCT.
---------------------------------------------------------------------------------------------------
*/

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------

#include "InterruptController.h"
#include "I2cInterfaceVariables.h"
#include "TimerInterfaceVariables.h"

#include <xil_exception.h>
#include <xscugic.h>
#include <xparameters.h>

//-------------------------------------------------------------------------------------------------
// Definitions and constants
//-------------------------------------------------------------------------------------------------

#define INTC_DEVICE_ID XPAR_SCUGIC_SINGLE_DEVICE_ID

//-------------------------------------------------------------------------------------------------
// Global variable definitions
//-------------------------------------------------------------------------------------------------

/// Interrupt controller, declared in InterruptController.h
XScuGic g_interruptController;

//-------------------------------------------------------------------------------------------------
// Function definitions
//-------------------------------------------------------------------------------------------------

EN_RESULT SetupInterruptSystem()
{

    XScuGic_Config* pInterruptControllerConfig;

    // Initialize the exception table.
    Xil_ExceptionInit();

    // Initialize the interrupt controller driver so that it's ready to use.
    pInterruptControllerConfig = XScuGic_LookupConfig(INTC_DEVICE_ID);

    if (NULL == pInterruptControllerConfig)
    {
        return EN_ERROR_NULL_POINTER;
    }

    RETURN_IF_XILINX_CALL_FAILED(XScuGic_CfgInitialize(&g_interruptController,
                                                       pInterruptControllerConfig,
                                                       pInterruptControllerConfig->CpuBaseAddress),
                                 EN_ERROR_FAILED_TO_INITIALISE_INTERRUPT_CONTROLLER);

    // Register the interrupt controller handler with the exception table.
    Xil_ExceptionRegisterHandler(
        XIL_EXCEPTION_ID_IRQ_INT, (Xil_ExceptionHandler)XScuGic_InterruptHandler, &g_interruptController);

    // Connect the device driver handler that will be called when an I2C interrupt
    // occurs
    RETURN_IF_XILINX_CALL_FAILED(XScuGic_Connect(&g_interruptController,
                                                 IIC_INTR_ID,
                                                 (Xil_InterruptHandler)XIicPs_MasterInterruptHandler,
                                                 &g_XIicPsInstance),
                                 EN_ERROR_FAILED_TO_INITIALISE_INTERRUPT_CONTROLLER);

    // Enable the interrupts for the IIC device.
    XScuGic_Enable(&g_interruptController, IIC_INTR_ID);

    // INSERT ANY FURTHER INTERRUPT ENABLES HERE //

    // Enable non-critical exceptions.
    Xil_ExceptionEnable();

    return EN_SUCCESS;
}
