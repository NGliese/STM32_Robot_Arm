/*
 * Task_Test.cpp
 *
 *  Created on: Aug 14, 2020
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
 *  \file       Task_Test.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Task_Test.hpp"

//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "Task_Test";
#endif

Task_Test::Task_Test() {
}

Task_Test::~Task_Test() {
}
/**
 * @brief     run the task
 *
 * @attention
 *
 * @Basic usage:
 * USER CODE END Header_StartDefaultTask
 * void run(void)
 * {
 *
 * Infinite loop
 * for(;;)
 * {
 *   // FUNCTION //
 *
 *   // delay
 *   osDelay(1);
 *  }
 * }
 *
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
void Task_Test::run(void) {


    for(;;)
    {
    // just write to the terminal
    std::cout << " hello from : " << m_conf.name << "\r\n";
    delay_ms(100);
    }

}
