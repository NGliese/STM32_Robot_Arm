/*
 * HAL.hpp
 *
 *  Created on: Jul 30, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_PWM_DRIVER_INCLUDE_HAL_HPP_
#define COMPONENTS_PWM_DRIVER_INCLUDE_HAL_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  HAL.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, HAL.hpp, is designed as:
 |
 |
 |
 |
 |
 |
 |
 |  version       : 1.0
 |
 |  Return Value  :   return_type
 |
 +-----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------+
 |   		 					Datasheet Awareness              		        |
 +------------------------------------------------------------------------------+
 |
 |
 |  Datasheet Awareness 1):
 |  	Link:[ ], Jul 30, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Jul 30, 2020
 |
 |		Brief:
 |
 |
 |
 |
 |
  +-----------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/

/*---------------- BASIC INCLUDES------------*/
#include "../../BPS/include/BASIC.hpp"
#include "../../BPS/include/General_Error.hpp"
/*-------------------------------------------*/

#include <iostream>
#include <sstream>

#ifdef __STM32__
#include "stm32f4xx_hal.h"
#endif


namespace pwm_driver{
typedef struct{
        uint16_t channel_number = 0;
}pwm_channel_t;

typedef struct{
    uint32_t frequency = 0;
    uint16_t duty_cycle = 0; // goes between 0 and 1000 [0-100%]
}pwm_conf_t;

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class HAL {
public:
    HAL();
    ~HAL();
    general_err_t initialze(void);
    general_err_t enable_channel(const pwm_channel_t & channel, const pwm_conf_t & conf);
    general_err_t test_i2c(const std::string & str);
    general_err_t scan_i2c(void);
    general_err_t resetDevice(void);
#ifdef UNIT_TEST_MODE
    general_err_t setPWMConfig(const pwm_conf_t & conf);
    general_err_t setPWMFrequency( uint32_t frequency);
    general_err_t setPWMDutyCycle(const pwm_channel_t &channel,  uint16_t duty );
    general_err_t wakeUpDriver(void);
    uint8_t readRegister(const uint8_t & reg);
    uint8_t writeRegister(const uint8_t & reg, const uint8_t & data);
#endif


    uint8_t lowByte(uint16_t byte);
    uint8_t highByte(uint16_t byte);
private:

#ifdef __STM32__
    I2C_HandleTypeDef hI2C ;
    general_err_t setPWMConfig(const pwm_conf_t & conf);
    general_err_t setPWMFrequency( uint32_t frequency);
    general_err_t setPWMDutyCycle(const pwm_channel_t &channel, uint16_t duty );
    general_err_t wakeUpDriver(void);
    uint8_t readRegister(const uint8_t & reg);
    uint8_t writeRegister(const uint8_t & reg, const uint8_t & data);
#endif
    bool m_initialized = false;

};


}

#endif /* COMPONENTS_PWM_DRIVER_INCLUDE_HAL_HPP_ */
