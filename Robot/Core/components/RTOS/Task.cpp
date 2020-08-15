/*
 * Task.cpp
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
 *  \file       Task.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Task.hpp"

//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "Task";
#endif
Task::Task() {
}

/**
 * @brief  initialize the task
 *
 *
 * @param[in] const task_conf_t &conf
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Task::initialize(const task_conf_t &conf) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Task::initialize >>");
    #endif

    m_conf = conf;
    m_initialized = true;

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Task::initialize << ");
    #endif

    return GE_OK;
}
/**
 * @brief   start  the task
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Task::start(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Task::start >>");
    #endif
    if(!m_initialized)
    {
        return GE_NOT_INITIALIZED;
    }
    if(m_isActive)
    {
        return GE_ACTIVE;
    }

#ifdef __FREERTOS__
    // parse in this as a parameter for the runTask, to be able to run the task.
   BaseType_t err =  xTaskCreate(runTask, m_conf.name.c_str(), m_conf.stack_size, this , m_conf.priority , &m_handler);
   if(err == pdPASS){
    // we are all set
    m_isActive = true;
   }

#endif

   // we are all set
   m_isActive = true;

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Task::start << ");
    #endif

    return GE_OK;
}
/**
 * @brief   stop the task
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Task::stop(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Task::stop >>");
    #endif
    if(!m_initialized)
    {
        return GE_NOT_INITIALIZED;
    }
    if(!m_isActive)
    {
        return GE_DEACTIVE;
    }

#ifdef __FREERTOS__
    // delete the thread, NULL indicates this
    vTaskDelete(NULL);
#endif

    // We are all good
    m_isActive = false;

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Task::stop << ");
    #endif

    return GE_OK;
}
/**
 * @brief   pause the task
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Task::pause(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Task::pause >>");
    #endif



    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Task::pause << ");
    #endif

    return GE_FAIL;
}



/**
 * @brief   resume the task
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Task::resume(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Task::resume >>");
    #endif



    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Task::resume << ");
    #endif

    return GE_FAIL;
}
/**
 * Static class member that actually runs the target task.
 *
 * The code here will run on the task thread.
 * @param [in] pTaskInstance The task to run.
 */
void Task::runTask(void* pvTask) {
    // point to the task
    Task * pTask = (Task*) pvTask;
    // run the task
    pTask->run();

}
/**
 * @brief delay for n- milliseconds
 *
 *
 *
 * @param[in] uint16 delay_time

 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
void Task::delay_ms(uint16_t delay_time) {

// taken from freeRTOS book, no need to unit test
#ifdef __FREERTOS__
    vTaskDelay(pdMS_TO_TICKS(delay_time));
#endif

}

void Task::startSchedular(void) {

#ifdef __FREERTOS__
    vTaskStartScheduler();
#endif

}
