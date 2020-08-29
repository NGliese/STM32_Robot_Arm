/*
 * Mains_Current_Sensor_Task.hpp
 *
 *  Created on: Aug 16, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_SENSOR_THREAD_INCLUDE_MAINS_CURRENT_SENSOR_TASK_HPP_
#define COMPONENTS_SENSOR_THREAD_INCLUDE_MAINS_CURRENT_SENSOR_TASK_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Mains_Current_Sensor_Task.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, Mains_Current_Sensor_Task.hpp, is designed as:
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
 |  	Link:[ ], Aug 16, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Aug 16, 2020
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

#include "../../RTOS/include/Task.hpp"


/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class Mains_Current_Sensor_Task : public Task {
public:
        Mains_Current_Sensor_Task();
        ~Mains_Current_Sensor_Task();
        general_err_t initialize(void);
        void run(void) override;

private:
};





#endif /* COMPONENTS_SENSOR_THREAD_INCLUDE_MAINS_CURRENT_SENSOR_TASK_HPP_ */
