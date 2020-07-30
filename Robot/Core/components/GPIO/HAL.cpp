
/*
 * HAL.cpp
 *
 *  Created on: Jul 22, 2020
 *      Author: nikolaj
 */



/***********************************************************************************************+
 *  \brief       -- XX -- Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       HAL.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/HAL.hpp"
#ifdef __STM32__
#include "stm32f4xx_hal.h"
#endif

//#define __DEBUG__
#ifdef __DEBUG__
static const char *LOG_TAG = "HAL";
#endif

gpio_hal::HAL::HAL() {
}

gpio_hal::HAL::~HAL() {
}
/**
 * @brief     initiaize the block
 *
 * @param[in] const gpio_conf_t &conf
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t gpio_hal::HAL::initialize(const gpio_conf_t &conf) {
	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, ">> gpio_hal::HAL::initialize >> ");
	#endif




#ifdef UNIT_TEST_MODE
	m_initialized = true;
	return GE_OK;
#endif

#ifdef __STM32__
	// convert the config to stm32 hal config
	GPIO_InitTypeDef stm32_gpio_conf;
	stm32_gpio_conf.Pin = conf.Pin;
	stm32_gpio_conf.Mode;

	stm32_gpio_conf.Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
	                           This parameter can be a value of @ref GPIO_pull_define */

	stm32_gpio_conf.Speed;     /*!< Specifies the speed for the selected pins.
	                           This parameter can be a value of @ref GPIO_speed_define */

	  uint32_t Alternate;  /*!< Peripheral to be connected to the selected pins.
	                            This parameter can be a value of @ref GPIO_Alternate_function_selection */


#endif

	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, "<< gpio_hal::HAL::initialize << ");
	#endif

	return GE_OK;
}
/**
 * @brief set value
 *
 * @param[in] const bool& val
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t gpio_hal::HAL::set_pin(const bool& val) {
	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, ">> gpio_hal::HAL::set_pin >> ");
	#endif

	if(!m_initialized)
	{
		return GE_NOT_INITIALIZED;
	}

#ifdef UNIT_TEST_MODE
	return GE_OK;
#endif

#ifdef __STM32__


#endif

	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, "<< gpio_hal::HAL::set_pin << ");
	#endif

	return GE_FAIL;
}
/**
 * @brief     return pin value
 *
 * @attention
 *
 *
 * @return
 *    - N/A
 *    -
 *    -
 */
bool gpio_hal::HAL::get_pin_val(void) {
	return false;
}
