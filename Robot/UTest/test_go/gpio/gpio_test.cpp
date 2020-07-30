/*
 * gpio_test.cpp
 *
 *  Created on: Jul 22, 2020
 *      Author: nikolaj
 */





#include <cstdint>

#include "CppUTest/TestHarness.h"

#include "../../../Core/components/GPIO/include/GPIO.hpp"
#include "../../../Core/components/GPIO/include/HAL.hpp"






TEST_GROUP(GPIO_GRP)
{
	basic::GPIO m_gpio;
	gpio_hal::gpio_conf_t conf;
	void setup(){




		m_gpio.initialize(conf);
	}
	void teardown(){

	}
};


// test to see if init of image is correct
TEST(GPIO_GRP, NOT_INIT)
{
	basic::GPIO gpio;
CHECK_EQUAL(GE_NOT_INITIALIZED,gpio.set_high());

}
// test to see if init of image is correct
TEST(GPIO_GRP, INIT)
{

CHECK_EQUAL(GE_OK,m_gpio.set_high());

}
