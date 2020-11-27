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

#pragma once


//-------------------------------------------------------------------------------------------------
// System type options
//-------------------------------------------------------------------------------------------------

#define XILINX_MICROBLAZE 0
#define XILINX_ARM_SOC 1
#define ALTERA_NIOS 2
#define ALTERA_ARM_SOC 3
#define UBOOT 4


//-------------------------------------------------------------------------------------------------
// System clock frequency
//-------------------------------------------------------------------------------------------------

#define SYSTEM_CLOCK_FREQUENCY_HZ 100000000

//-------------------------------------------------------------------------------------------------
// Project definitons
//-------------------------------------------------------------------------------------------------

#define MODULE_TESTING 0
#define REFERENCE_DESIGN 1

#define PROJECT MODULE_TEST



//-------------------------------------------------------------------------------------------------
// Module type definitions
//-------------------------------------------------------------------------------------------------

#define MARS_MX1 0
#define MARS_MX2 1
#define MERCURY_CA1 2
#define MARS_ZX2 3
#define MARS_ZX3 4
#define MARS_AX3 5
#define MERCURY_KX1 6
#define MERCURY_SA1 7
#define MERCURY_ZX1 8
#define MERCURY_ZX5 9
#define MERCURY_SA2 10
#define MERCURY_KX2 11
#define MERCURY_AA1 12
#define MERCURY_XU1 13
#define MARS_XU3 14
#define COSMOS_XZQ10 15
#define MARS_MA3 16
#define MERCURY_XU5 17
#define MERCURY_XU7 18
#define MERCURY_XU8 19
#define MERCURY_XU9 20

//-------------------------------------------------------------------------------------------------
// Base board definitions
//-------------------------------------------------------------------------------------------------

#define MARS_STARTER 0
#define MERCURY_STARTER 1
#define MARS_PM3 2
#define MERCURY_PE1 3
#define MARS_EB1 4
#define MARS_ST3 5

//-------------------------------------------------------------------------------------------------
// Printf definitions
//-------------------------------------------------------------------------------------------------

#if SYSTEM == XILINX_MICROBLAZE
#include "xil_printf.h"
#define EN_PRINTF xil_printf
#define EN_FLUSH fflush(stdout)
#elif SYSTEM == XILINX_ARM_SOC
#include "xil_printf.h"
#define EN_FLUSH fflush(stdout)
#define EN_PRINTF xil_printf
#elif SYSTEM == ALTERA_NIOS
#define EN_PRINTF printf
#define EN_FLUSH alt_dcache_flush_all()
#elif SYSTEM == ALTERA_ARM_SOC
#if TARGET_MODULE==MERCURY_AA1
#define EN_PRINTF printf
#define EN_FLUSH fflush(stdout)
#else
#include "uart0_support.h"
#define EN_PRINTF uart0_printf
#define EN_FLUSH fflush(stdout)
#endif
#elif SYSTEM == UBOOT
#define EN_PRINTF printf
#define EN_FLUSH fflush(stdout)
#endif
