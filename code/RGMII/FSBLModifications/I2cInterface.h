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
// Includes
//-------------------------------------------------------------------------------------------------

#include "StandardIncludes.h"


//-------------------------------------------------------------------------------------------------
// Types, definitions and constants
//-------------------------------------------------------------------------------------------------

/**
* \brief I2C subaddress modes.
*/
typedef enum
{
    EI2cSubAddressMode_None,    ///< No subaddress
    EI2cSubAddressMode_OneByte, ///< One-byte subaddress
    EI2cSubAddressMode_TwoBytes ///< Two-byte subaddress
} EI2cSubAddressMode_t;




//-------------------------------------------------------------------------------------------------
// Function definitions
//-------------------------------------------------------------------------------------------------

/**
 * \brief Perform any required initialisation for I2C operations.
 *
 * @return		Result code
 */
EN_RESULT InitialiseI2cInterface();


/**
 * \brief Perform a read from the I2C bus.
 *
 * \param[in]	deviceAddress			The device address
 * \param[in]	subAddress				Register subaddress
 * \param[in]	subAddressMode			Subaddress mode
 * \param[in]	numberOfBytesToRead		The number of bytes to read
 * \param[out]	pReadBuffer				Buffer to receive read data
 * \returns								Result code
 */
EN_RESULT I2cRead(uint8_t deviceAddress,
                  uint16_t subAddress,
                  EI2cSubAddressMode_t subAddressMode,
                  uint32_t numberOfBytesToRead,
                  uint8_t* pReadBuffer);

/**
 * \brief Perform a write to the I2C bus.
 *
 * \param	deviceAddress			Device address
 * \param	subAddress				Register subaddress
 * \param	subAddressMode			Subaddress mode
 * \param	writeBuffer				Buffer containing write data
 * \param	numberOfBytesToWrite	The number of bytes to write
 * \returns							Result code
 */
EN_RESULT I2cWrite(uint8_t deviceAddress,
                   uint16_t subAddress,
                   EI2cSubAddressMode_t subAddressMode,
                   const uint8_t* pWriteBuffer,
                   uint32_t numberOfBytesToWrite);
