/*
 * Step_Motor_Controller.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef STEP_MOTOR_CONTROLLER_INCLUDE_STEP_MOTOR_CONTROLLER_HPP_
#define STEP_MOTOR_CONTROLLER_INCLUDE_STEP_MOTOR_CONTROLLER_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Step_Motor_Controller.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, Step_Motor_Controller.hpp, is designed as:
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

#include "../../template/include/Basic_Controller.hpp"

#include "../../Step_Motor/include/Step_Motor.hpp"
#include "../../Current_Sensor/include/Current_Sensor.hpp"


/*---------------- BASIC INCLUDES------------*/
#include "../../BPS/include/BASIC.hpp"
#include "../../BPS/include/General_Error.hpp"
/*-------------------------------------------*/

#include <cstdio>

/*------------------------------------------------------------------------------+
 |                             typedef                                          |
 +------------------------------------------------------------------------------*/

typedef struct{
    GPIO_PIN step_motor_index = 0;
    uint8_t current_sensor_index = 0;
}motor_pair_t;

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class Step_Motor_Controller : public Basic_Controller{
public:
    Step_Motor_Controller();
    Step_Motor_Controller(motor_pair_t* pair);
    ~Step_Motor_Controller();
    uint16_t getPosition(void);

protected:
    Step_Motor  m_motor;
    Current_Sensor  m_sensor;
private:

    general_err_t handleEvent(void);
    Controller_flag_t getStatus(void);
    general_err_t stop(void);
    motor_pair_t m_motor_pair;
    sensor_package_t m_package;
};




#endif /* STEP_MOTOR_CONTROLLER_INCLUDE_STEP_MOTOR_CONTROLLER_HPP_ */
