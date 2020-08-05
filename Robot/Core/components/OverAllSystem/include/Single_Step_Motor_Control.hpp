/*
 * Single_Step_Motor_Control.hpp
 *
 *  Created on: Aug 4, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_OVERALLSYSTEM_INCLUDE_SINGLE_STEP_MOTOR_CONTROL_HPP_
#define COMPONENTS_OVERALLSYSTEM_INCLUDE_SINGLE_STEP_MOTOR_CONTROL_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Single_Step_Motor_Control.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, Single_Step_Motor_Control.hpp, is designed as:
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
 |  	Link:[ ], Aug 4, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Aug 4, 2020
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


#include "../../Bender_Controller/include/Bender_Controller.hpp"
#include "../../PWM_Driver/include/PWM_Driver.hpp"



/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/


class Single_Step_Motor_Control {
public:
        Single_Step_Motor_Control();
        ~Single_Step_Motor_Control();
        general_err_t initialize(void);
        general_err_t run(void);

private:
        bool m_initialized=false;
        Bender_Controller  m_bender;
        uint8_t m_cnt = 0;
        int sign = 1;
};



#endif /* COMPONENTS_OVERALLSYSTEM_INCLUDE_SINGLE_STEP_MOTOR_CONTROL_HPP_ */
