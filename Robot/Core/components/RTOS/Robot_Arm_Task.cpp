/*
 * Robot_Arm_Task.cpp
 *
 *  Created on: Sep 6, 2020
 *      Author: nikolaj
 */




/***********************************************************************************************+
 *  \brief       -- XX -- Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       Robot_Arm_Task.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Robot_Arm_Task.hpp"

//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "Robot_Arm_Task";
#endif

Robot_Arm_Task::Robot_Arm_Task() {
}

Robot_Arm_Task::~Robot_Arm_Task() {
}
/*
 * @brief run the task
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
void Robot_Arm_Task::run(void) {
    for(;;)
     {
     // just write to the terminal
     m_log.write_info("hello from " ,  m_conf.name );
     delay_ms(1000);
    // vTaskDelay(10);
     }
}
