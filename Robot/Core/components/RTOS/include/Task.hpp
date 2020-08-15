/*
 * Task.hpp
 *
 *  Created on: Aug 14, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_RTOS_INCLUDE_TASK_HPP_
#define COMPONENTS_RTOS_INCLUDE_TASK_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Task.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, Task.hpp, is designed as:
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

#define _thread_delay( delay_ms ) ( printf("delay : [%d] \n",delay_ms))

#define _priority int
#define _thread_handler int


#ifdef __STM32__
    #ifdef __FREERTOS__
#undef _thread_delay
#undef _priority
#undef _thread_handler
        // define the paths to the freeRTOS libary
        #include "../../../Middlewares/Third_Party/FreeRTOS/Source/include/FreeRTOS.h"
        #include "../../../Middlewares/Third_Party/FreeRTOS/Source/include/task.h"
        #include "../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.h"
#define _thread_delay( delay_ms ) ( osDelay(delay_ms) )
#define _priority uint16_t
#define _thread_handler TaskHandle_t
    #endif
#endif

/*------------------------------------------------------------------------------+
 |   		 					 Typedef                  		                |
 +------------------------------------------------------------------------------*/

typedef struct{
std::string name;
_priority priority;
uint16_t stack_size;
}task_conf_t;

/*------------------------------------------------------------------------------+
 |                               Class                                          |
 +------------------------------------------------------------------------------*/


class Task {
public:
        Task();
    virtual ~Task() {};
    general_err_t initialize(const task_conf_t & conf);
    virtual void run(void) {};

    general_err_t start(void);
    general_err_t stop(void);
    general_err_t pause(void);
    general_err_t resume(void);
    inline bool isActive(void) {return m_isActive;}
    void delay_ms(uint16_t delay_time);

    static void startSchedular(void);
protected :
    task_conf_t m_conf;
private:
    static void runTask(void *);
    bool m_initialized = false;
    bool m_isActive = false;


    _thread_handler m_handler;
    // static variable to keep track of the scedular status
    static volatile bool m_schedularActive ;

};



#endif /* COMPONENTS_RTOS_INCLUDE_TASK_HPP_ */
