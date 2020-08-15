/*
 * Task_Test.hpp
 *
 *  Created on: Aug 14, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_RTOS_INCLUDE_TASK_TEST_HPP_
#define COMPONENTS_RTOS_INCLUDE_TASK_TEST_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Task_Test.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, Task_Test.hpp, is designed as:
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
 |  	Link:[ ], Aug 14, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Aug 14, 2020
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

#include "Task.hpp"


#include <iostream>
/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/



class Task_Test :public Task {
public:
        Task_Test();
        ~Task_Test();
        void run(void) override;

private:
};


#endif /* COMPONENTS_RTOS_INCLUDE_TASK_TEST_HPP_ */
