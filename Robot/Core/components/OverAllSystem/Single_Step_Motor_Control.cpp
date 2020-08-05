/*
 * Single_Step_Motor_Control.cpp
 *
 *  Created on: Aug 4, 2020
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
 *  \file       Single_Step_Motor_Control.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Single_Step_Motor_Control.hpp"

PWM_Driver m_driver;

//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "Single_Step_Motor_Control";
#endif

Single_Step_Motor_Control::Single_Step_Motor_Control() {
}

Single_Step_Motor_Control::~Single_Step_Motor_Control() {

}
/**
 * @brief  initialize the system
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Single_Step_Motor_Control::initialize(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Single_Step_Motor_Control::initialize >>");
    #endif


    if( m_driver.initialze() != GE_OK)
     {
     LOG_PRINT_ERROR("ERROR","FAIL","");
     return GE_FAIL;
     }

    bender_config_t  conf;
    conf.pair.step_motor_index = 0;
    m_bender.initialize(conf);

    m_initialized = true;

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Single_Step_Motor_Control::initialize << ");
    #endif

    return GE_OK;
}
/**
 * @brief      run the system
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Single_Step_Motor_Control::run(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Single_Step_Motor_Control::run >>");
    #endif
    if(!m_initialized)
    {
        return GE_NOT_INITIALIZED;
    }

    general_err_t err = GE_OK;
    if(m_cnt > 120)
    {
        sign = -1;
    }
    if(m_cnt == 0)
    {
        sign = 1;
    }
    m_cnt+=sign;
   err =  m_bender.addEvent(m_cnt);
   if(err != GE_OK)
   {
       return err;
   }
    if( m_bender.runStatemachine() != Controller_flag_t::STATUS_OK )
   {
       return GE_FAIL;
   }


    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Single_Step_Motor_Control::run << ");
    #endif

    return GE_OK;
}

