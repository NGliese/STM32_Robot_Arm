
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
 * @param[in] GPIO_TypeDef  *GPIOx
 * @param[in] const gpio_conf_t &conf
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t gpio_hal::HAL::initialize(GPIO_TypeDef  *GPIOx,const gpio_conf_t &conf) {
	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, ">> gpio_hal::HAL::initialize >> ");
	#endif


	m_conf = conf;
	m_port = GPIOx;

	m_initialized = true;
#ifdef UNIT_TEST_MODE
	return GE_OK;
#endif

#ifdef __STM32__
	// convert the config to stm32 hal config
	GPIO_InitTypeDef stm32_gpio_conf = convertConfig();

	HAL_GPIO_Init(m_port,&stm32_gpio_conf);
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
	// convert the config to stm32 hal config
	GPIO_InitTypeDef stm32_gpio_conf = convertConfig();
	HAL_GPIO_WritePin(m_port,stm32_gpio_conf.Pin,(GPIO_PinState)val);
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

#ifdef __STM32__
    // convert the config to stm32 hal config
    GPIO_InitTypeDef stm32_gpio_conf = convertConfig();
    return (bool)HAL_GPIO_ReadPin(m_port,stm32_gpio_conf.Pin);
#endif

	return false;
}
#ifdef __STM32__
GPIO_InitTypeDef gpio_hal::HAL::convertConfig(void) {

    GPIO_InitTypeDef stm32_gpio_conf={0};
    if(!m_initialized)
    {   // this return is failed
        return stm32_gpio_conf;
    }

    stm32_gpio_conf.Pin       = m_conf.Pin;
    stm32_gpio_conf.Mode      = m_conf.Mode;
    stm32_gpio_conf.Pull      = m_conf.Pull;
    stm32_gpio_conf.Speed     = m_conf.Speed;
    stm32_gpio_conf.Alternate = m_conf.Alternate;

return stm32_gpio_conf;
}

#endif
