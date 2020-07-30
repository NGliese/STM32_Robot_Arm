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



namespace pwm_driver{
typedef struct{
        uint16_t channel_number = 0;
}pwm_channel_t;

typedef struct{
    uint32_t frequency = 0;
    uint8_t duty_cycle = 0; // goes between 0 and 100
}pwm_conf_t;

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class HAL {
public:
    HAL();
    ~HAL();
    general_err_t enable_channel(const pwm_channel_t & channel, const pwm_conf_t conf);

private:
};


}

#endif /* COMPONENTS_PWM_DRIVER_INCLUDE_HAL_HPP_ */
