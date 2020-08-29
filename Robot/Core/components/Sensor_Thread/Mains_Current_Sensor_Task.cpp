/*
 * Mains_Current_Sensor_Task.cpp
 *
 *  Created on: Aug 16, 2020
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
 *  \file       Mains_Current_Sensor_Task.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Mains_Current_Sensor_Task.hpp"

//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "Mains_Current_Sensor_Task";
#endif

Mains_Current_Sensor_Task::Mains_Current_Sensor_Task() {
}

Mains_Current_Sensor_Task::~Mains_Current_Sensor_Task() {
}
/**
 * @brief  initialize the sensor task
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Mains_Current_Sensor_Task::initialize(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Mains_Current_Sensor_Task::initialize >>");
    #endif



    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Mains_Current_Sensor_Task::initialize << ");
    #endif

    return GE_FAIL;
}
/**
 * @brief  run the task
 *
 * @attention  MUST NEVER EXIT
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
void Mains_Current_Sensor_Task::run(void) {

#ifdef __FREERTOS__
    for(;;);
#endif
}
