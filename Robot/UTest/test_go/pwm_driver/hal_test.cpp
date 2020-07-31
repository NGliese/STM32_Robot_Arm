/*
 * thermal_camera_test.cpp
 *
 *  Created on: May 28, 2020
 *      Author: espenv
 */


#include <cstdint>

#include "CppUTest/TestHarness.h"

#include "../../../Core/components/PWM_Driver/include/HAL.hpp"




TEST_GROUP(PWM_HAL_GRP)
{
    pwm_driver::HAL m_hal;
    void setup(){
        m_hal.initialze();
    }
    void teardown(){

    }
};


// test to see if init of image is correct
TEST(PWM_HAL_GRP, NOT_INIT)
{
    pwm_driver::pwm_channel_t channel;
    pwm_driver::pwm_conf_t conf;
    pwm_driver::HAL hal;
    CHECK_EQUAL(GE_NOT_INITIALIZED,hal.enable_channel(channel, conf));

}
// test to see if init of image is correct
TEST(PWM_HAL_GRP, INIT)
{
    pwm_driver::HAL hal;
    CHECK_EQUAL(GE_OK,hal.initialze());

}


// test to see if init of image is correct
TEST(PWM_HAL_GRP, SEND)
{
    pwm_driver::pwm_channel_t channel;
    pwm_driver::pwm_conf_t conf;
    conf.frequency = 500;
    conf.duty_cycle = 500;
    CHECK_EQUAL(GE_OK,m_hal.enable_channel(channel, conf));

}



// test to see if init of image is correct
TEST(PWM_HAL_GRP, low_byte)
{
    uint16_t byte = 0xffbb;
    uint8_t exp_byte = 0xbb;
    uint8_t res_byte = m_hal.lowByte(byte);
    CHECK_EQUAL(exp_byte,res_byte);

}


// test to see if init of image is correct
TEST(PWM_HAL_GRP, high_byte)
{
    uint16_t byte = 0xffbb;
    uint8_t exp_byte = 0xff;
    uint8_t res_byte = m_hal.highByte(byte);
    CHECK_EQUAL(exp_byte,res_byte);

}
