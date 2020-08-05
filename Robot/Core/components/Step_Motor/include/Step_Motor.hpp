/*
 * Step_Motor.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef STEP_MOTOR_INCLUDE_STEP_MOTOR_HPP_
#define STEP_MOTOR_INCLUDE_STEP_MOTOR_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Step_Motor.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, Step_Motor.hpp, is designed as:
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

#include "HAL.hpp"

#include <cstdint>

/*------------------------------------------------------------------------------+
 |                              TYPEDEF                                         |
 +------------------------------------------------------------------------------*/



typedef struct{
    uint16_t default_position = 0;
    uint16_t max = 120; // DEFAULT VALUE
    uint16_t min = 0;   // DEFALUT VALUE
    uint8_t index = 1;
}step_motor_conf_t;

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/



class Step_Motor {
public:
    Step_Motor();
    ~Step_Motor();
    general_err_t initialize(const step_motor_conf_t &conf);
    general_err_t set_position(const uint16_t deg);
    float    get_angular_position(void);
    uint16_t get_position(void);
    general_err_t reset(void);

private:
    NS_Step_Motor::HAL  m_hal;

    step_motor_conf_t m_myConfig;
    uint16_t m_myCurrentPosition;
};




#endif /* STEP_MOTOR_INCLUDE_STEP_MOTOR_HPP_ */
