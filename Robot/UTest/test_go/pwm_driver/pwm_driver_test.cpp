/*
 * thermal_camera_test.cpp
 *
 *  Created on: May 28, 2020
 *      Author: espenv
 */


#include <cstdint>

#include "CppUTest/TestHarness.h"

#include "../../../Core/components/PWM_Driver/include/PWM_Driver.hpp"







TEST_GROUP(PWM_DRIV_GRP)
{
    PWM_Driver m_driver;
	void setup(){
	    m_driver.initialze();
	}
	void teardown(){

	}
};


// test to see if init of image is correct
TEST(PWM_DRIV_GRP, NOT_INIT)
{
    pwm_driver::pwm_channel_t channel;
    pwm_driver::pwm_conf_t conf;
    PWM_Driver driver;
CHECK_EQUAL(GE_NOT_INITIALIZED,driver.enable_channel(channel, conf));

}
// test to see if init of image is correct
TEST(PWM_DRIV_GRP, INIT)
{

    PWM_Driver driver;
CHECK_EQUAL(GE_OK,driver.initialze());

}


// test to see if init of image is correct
TEST(PWM_DRIV_GRP, EN)
{
    pwm_driver::pwm_channel_t channel;
    pwm_driver::pwm_conf_t conf;
    conf.frequency = 250;

CHECK_EQUAL(GE_OK,m_driver.enable_channel(channel, conf));

}

