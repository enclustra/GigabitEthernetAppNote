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

#include "SystemDefinitions.h"

//-------------------------------------------------------------------------------------------------
// Use correct header for types
// This is different for the target platform because uboot implements types in lib/linux/types.h
//-------------------------------------------------------------------------------------------------
#if SYSTEM == XILINX_MICROBLAZE
#include <stdint.h>
#elif SYSTEM == XILINX_ARM_SOC
#include <stdint.h>
#elif SYSTEM == ALTERA_NIOS
#include <stdint.h>


#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif


#elif SYSTEM == ALTERA_ARM_SOC
#include <stdint.h>
#elif SYSTEM == UBOOT
#include <asm/types.h>

typedef s8 int8_t;
typedef u8 uint8_t;

typedef s16 int16_t;
typedef u16 uint16_t;

typedef s32 int32_t;
typedef u32 uint32_t;

typedef s64 int64_t;
typedef u64 uint64_t;

#define true 1
#define false 0
#endif

#ifndef __cplusplus
#define bool char
#define true 1
#define false 0
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif
