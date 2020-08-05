/*
 * hal.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef STEP_MOTOR_INCLUDE_HAL_HPP_
#define STEP_MOTOR_INCLUDE_HAL_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  HAL.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
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
 |  	Link:[ ], May 22, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], May 22, 2020
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

#include "../../BPS/include/BASIC.hpp"
#include "../../BPS/include/General_Error.hpp"
#include <cstdint>

#include "../../PWM_Driver/include/PWM_Driver.hpp"

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/


namespace NS_Step_Motor{
    class HAL {
    public:
        HAL();
        ~HAL();
        general_err_t initialize(GPIO_PIN pin);
        general_err_t set_position(uint16_t pos);
        uint16_t get_position(void);
    private:
        general_err_t set_pwm(uint16_t duty_cycle);
        uint16_t m_myPosition;
        GPIO_PIN m_pin;
        pwm_driver::pwm_channel_t m_channel;
        pwm_driver::pwm_conf_t m_pwm_conf;

    };
}


#endif /* STEP_MOTOR_INCLUDE_HAL_HPP_ */
