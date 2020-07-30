/*
 * PWM_Driver.hpp
 *
 *  Created on: Jul 30, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_PWM_DRIVER_INCLUDE_PWM_DRIVER_HPP_
#define COMPONENTS_PWM_DRIVER_INCLUDE_PWM_DRIVER_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  PWM_Driver.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, PWM_Driver.hpp, is designed as:
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


#include "HAL.hpp"

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/


class PWM_Driver{
public:
    PWM_Driver();
    ~PWM_Driver();
    general_err_t initialze(void);
    general_err_t enable_channel(const pwm_driver::pwm_channel_t & channel, const  pwm_driver::pwm_conf_t & conf);

private:
    pwm_driver::HAL m_hal;
    bool m_initialized = false;
};




#endif /* COMPONENTS_PWM_DRIVER_INCLUDE_PWM_DRIVER_HPP_ */
