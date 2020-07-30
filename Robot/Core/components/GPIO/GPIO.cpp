/*
 * GPIO.cpp
 *
 *  Created on: Jul 21, 2020
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
 *  \file       GPIO.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/GPIO.hpp"
//#define __DEBUG__
#ifdef __DEBUG__
static const char *LOG_TAG = "GPIO";
#endif

basic::GPIO::GPIO() {
}

basic::GPIO::~GPIO() {
}
/**
 * @brief initialize the gpio
 *
 * @param[in] const gpio_conf_t &conf
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t basic::GPIO::initialize(const gpio_hal::gpio_conf_t &conf) {
	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, ">> basic::GPIO::initialize >> ");
	#endif

	// check that we initialize correctly
	if(m_hal.initialize(conf) == GE_OK){
	m_initialize = true;
	}
	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, "<< basic::GPIO::initialize << ");
	#endif

	return GE_FAIL;
}
/**
 * @brief  set the gpio high
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t basic::GPIO::set_high(void) {
	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, ">> basic::GPIO::set_high >> ");
	#endif
	if(!m_initialize)
	{
		return GE_NOT_INITIALIZED;
	}


	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, "<< basic::GPIO::set_high << ");
	#endif

	return 	m_hal.set_pin(true);
}
/**
 * @brief  set the gpio low
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t basic::GPIO::set_low(void) {
	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, ">> basic::GPIO::set_low >> ");
	#endif


	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, "<< basic::GPIO::set_low << ");
	#endif

	return GE_FAIL;
}

bool basic::GPIO::get_level(void) {
	return false;
}
