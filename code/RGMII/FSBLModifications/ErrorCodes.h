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

#include "SystemDefinitions.h"


//-------------------------------------------------------------------------------------------------
// Error code definitions
//-------------------------------------------------------------------------------------------------

/** \cond */

typedef enum EN_RESULT
{
    EN_SUCCESS = 0x00000000,

    EN_ERROR_NULL_POINTER = 0x80000000,
    EN_ERROR_INVALID_ARGUMENT,
    EN_ERROR_FAILED_TO_SET_I2C_DEVICE_ADDRESS,
    EN_ERROR_FAILED_TO_INITIALISE_I2C_CONTROLLER,
    EN_ERROR_FAILED_TO_START_XIIC_DEVICE,
    EN_ERROR_FAILED_TO_STOP_XIIC_DEVICE,
    EN_ERROR_FAILED_TO_INITIALISE_INTERRUPT_CONTROLLER,
    EN_ERROR_FAILED_TO_START_INTERRUPT_CONTROLLER,
    EN_ERROR_XIIC_SEND_FAILED,
    EN_ERROR_XIIC_RECEIVE_FAILED,
    EN_ERROR_I2C_READ_FAILED,
    EN_ERROR_I2C_WRITE_FAILED,
    EN_ERROR_I2C_READ_TIMEOUT,
    EN_ERROR_I2C_WRITE_TIMEOUT,
    EN_ERROR_I2C_SLAVE_NACK,
    EN_ERROR_TIMER_INITIALISATION_FAILED,
    EN_ERROR_TIMER_SELF_TEST_FAILED,
    EN_ERROR_INVALID_MODULE_CONFIG_PROPERTY_INDEX,
    EN_ERROR_MODULE_CONFIG_PROPERTY_VALUE_OUT_OF_RANGE,
    EN_ERROR_MODULE_CONFIG_PROPERTIES_NOT_YET_READ,
    EN_ERROR_MODULE_CONFIG_PROPERTY_DOES_NOT_HAVE_VALUE_KEY,
    EN_ERROR_FAILED_TO_INITIALISE_EEPROM,
    EN_ERROR_FAILED_TO_WAKE_ATMEL_ATSHA204A,
    EN_ERROR_ATSHA204A_INVALID_ADDRESS_PARAMETER,
    EN_ERROR_ATSHA204A_INVALID_RESPONSE_CRC,
    EN_ERROR_ATSHA204A_INVALID_RESPONSE_SIZE,
    EN_ERROR_ATSHA204A_EXECUTION_ERROR,
    EN_ERROR_ATSHA204A_FIRST_COMMAND_AFTER_WAKE,
    EN_ERROR_ATSHA204A_INVALID_MAC,
    EN_ERROR_ATSHA204A_IO_ERROR,
    EN_ERROR_ATSHA204A_PARSE_ERROR,
    EN_ERROR_ATSHA204A_UNKNOWN_ERROR,
    EN_ERROR_ATSHA204A_FUNCTIONALITY_NOT_YET_IMPLEMENTED,
    EN_ERROR_ATSHA204A_WRITE_VERIFICATION_ERROR,
    EN_ERROR_ATSHA204A_INVALID_DATA_SLOT_INDEX,
    EN_ERROR_RTC_DEVICE_NOT_DETECTED,
    EN_ERROR_RTC_FEATURE_NOT_SUPPORTED,
    EN_ERROR_RTC_NOT_WORKING,
    EN_ERROR_IOTEST_FAILED,
    EN_ERROR_SUPPLY_OUT_OF_RANGE

} EN_RESULT;

/** \endcond */


//-------------------------------------------------------------------------------------------------
// Macros
//-------------------------------------------------------------------------------------------------


/**
 * \brief Returns a boolean true if the argument status code \a status represents an error.
 */
#define EN_FAILED(status) (((EN_RESULT)(status)) != EN_SUCCESS)

/**
 * \brief Returns a boolean true if the argument status code \a status represents a success.
 */
#define EN_SUCCEEDED(status) (((EN_RESULT)(status)) == EN_SUCCESS)


#define EN_PRINT_ERROR(status, message)																					\
	    do                                                                                                              \
	    {                                                                                                               \
	        EN_PRINTF("Error, status code 0x%x: %s\r\n", status, message);                                              \                                                                                                             \
	    } while (0)


/**
 * \brief Tests the status code \a status and returns if it's a failure code.
 *
 * Used to neaten code and avoid large if-else trees.
 */
#define EN_RETURN_IF_FAILED(status)                                                                                    \
    do                                                                                                                 \
    {                                                                                                                  \
        EN_RESULT _status = status;                                                                                    \
        if (EN_FAILED(_status))                                                                                        \
        {                                                                                                              \
            return _status;                                                                                            \
        }                                                                                                              \
    } while (0)


/**
 * \brief Tests the status code \a status and returns if it's a failure code.
 *
 * Used to neaten code and avoid large if-else trees.
 */
#define EN_RETURN_IF_FAILED_PRINT(status, message)                                                                     \
    do                                                                                                                 \
                                                                                                                       \
    {                                                                                                                  \
        EN_RESULT _status = status;                                                                                    \
        if (EN_FAILED(_status))                                                                                        \
        {    																										   \
        	EN_PRINTF("Error: %s (status code = 0x%x)\r\n", message, status);  										   \
            return _status;                                                                                            \
        }                                                                                                              \
    } while (0)


#if SYSTEM == XILINX_MICROBLAZE
/**
 * This macro is used to handle errors in calls to the Xilinx Microblaze driver functions.
 */
#define RETURN_IF_XILINX_CALL_FAILED(x, returnCode)                                                                    \
    do                                                                                                                 \
    {                                                                                                                  \
        int _status = x;                                                                                               \
        if (_status != XST_SUCCESS)                                                                                    \
        {                                                                                                              \
            return returnCode;                                                                                         \
        }                                                                                                              \
    } while (0)
#endif

#if SYSTEM == XILINX_ARM_SOC
/**
 * This macro is used to handle errors in calls to the Xilinx Microblaze driver functions.
 */
#define RETURN_IF_XILINX_CALL_FAILED(x, returnCode)                                                                    \
    do                                                                                                                 \
    {                                                                                                                  \
        int _status = x;                                                                                               \
        if (_status != XST_SUCCESS)                                                                                    \
        {                                                                                                              \
            return returnCode;                                                                                         \
        }                                                                                                              \
    } while (0)
#endif
