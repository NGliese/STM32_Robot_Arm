/*
 * Robot_Arm_Task.hpp
 *
 *  Created on: Sep 6, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_RTOS_INCLUDE_ROBOT_ARM_TASK_HPP_
#define COMPONENTS_RTOS_INCLUDE_ROBOT_ARM_TASK_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Robot_Arm_Task.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, Robot_Arm_Task.hpp, is designed as:
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
 |  	Link:[ ], Sep 6, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Sep 6, 2020
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

#include "../../Logging/include/Logger.hpp"
#include "Task.hpp"



/*------------------------------------------------------------------------------+
 |                               Class                                          |
 +------------------------------------------------------------------------------*/



class Robot_Arm_Task : public Task {
public:
        Robot_Arm_Task();
        ~Robot_Arm_Task();
        void run(void) override;
private:
        Logger m_log;
};


#endif /* COMPONENTS_RTOS_INCLUDE_ROBOT_ARM_TASK_HPP_ */
