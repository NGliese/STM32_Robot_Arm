/*
 * main2.cpp
 *
 *  Created on: Jul 30, 2020
 *      Author: nikolaj
 */



#include "main2.h"

#include "../components/BPS/include/BASIC.hpp"
#include "../components/BPS/include/General_Error.hpp"

#include "../components/GPIO/include/GPIO.hpp"

int main2(void)
{
	basic::GPIO m_gpio;

	gpio_hal::gpio_conf_t conf = gpio_hal::default_output;
	conf.Pin = GPIO_PIN_2;

	m_gpio.initialize(GPIOC, conf);

	for(size_t i = 0; i < 100; i++)
	{
	    m_gpio.toggle();
	}

	return 1;

}
