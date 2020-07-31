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

#include "../components/PWM_Driver/include/HAL.hpp"
#include "../components/PWM_Driver/include/PWM_Driver.hpp"



#ifdef __STM32__
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#endif

int gpio_version_1(void);
int test_i2c_version_1(void);
int scan_i2c_version_1(void);

int set_pwm_enable_version_1(void);

int main2(void)
{
   // gpio_version_1();
  //  scan_i2c_version_1();
  //  test_i2c_version_1();
    set_pwm_enable_version_1();
	return 1;

}

int set_pwm_enable_version_1(void)
{
    PWM_Driver driver;
    if( driver.initialze() != GE_OK)
    {
    LOG_PRINT_ERROR("ERROR","FAIL","");
    return 1;
    }
    pwm_driver::pwm_channel_t channel;
    pwm_driver::pwm_conf_t conf;
    conf.frequency = 250;
    conf.duty_cycle = 499;

    channel.channel_number = 4;
    driver.enable_channel(channel, conf);

    while(1);

    return 0;

}
int test_i2c_version_1(void){
    pwm_driver::HAL m_hal;

   if( m_hal.initialze() != GE_OK)
   {
   LOG_PRINT_ERROR("ERROR","FAIL","");
   return 1;
   }
   for(size_t i = 0; i < 100; i++)
   {
   m_hal.test_i2c("Hello World");
   HAL_Delay(1000);

   }
   return 1;
}
// test a gpio pin toggle
int gpio_version_1(void)
{
    basic::GPIO m_gpio;

    gpio_hal::gpio_conf_t conf = gpio_hal::default_output;
    conf.Pin = GPIO_PIN_2;

    m_gpio.initialize(GPIOC, conf);

    for(size_t i = 0; i < 100; i++)
    {
        m_gpio.toggle();
    }
return 0;
}

int scan_i2c_version_1(void){
    pwm_driver::HAL m_hal;

     if( m_hal.initialze() != GE_OK)
     {
     LOG_PRINT_ERROR("ERROR","FAIL","");
     return 1;
     }

     m_hal.scan_i2c();
     HAL_Delay(1000);
     return 1;
}
