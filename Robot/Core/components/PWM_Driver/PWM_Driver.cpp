/*
 * PWM_Driver.cpp
 *
 *  Created on: Jul 30, 2020
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
 *  \file       PWM_Driver.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/PWM_Driver.hpp"

//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "PWM_Driver";
#endif




PWM_Driver::PWM_Driver() {
}

PWM_Driver::~PWM_Driver() {
}
/**
 * @brief      initialize the driver
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t PWM_Driver::initialze(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> PWM_Driver::initialze >>");
    #endif

    if(GE_OK != m_hal.initialze())
    {
        return GE_FAIL;
    }
    m_initialized = true;


    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< PWM_Driver::initialze << ");
    #endif

    return GE_OK;
}


/**
 * @brief initialize a channel for the pwm driver
 *
 *
 * @param[in]   const pwm_driver::pwm_channel_t &channel
 * @param[in]   const pwm_driver::pwm_conf_t &conf
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t PWM_Driver::enable_channel(
        const pwm_driver::pwm_channel_t &channel,
        const pwm_driver::pwm_conf_t &conf) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> PWM_Driver::initialize_channel >>");
    #endif

    if(!m_initialized)
    {
        return GE_NOT_INITIALIZED;
    }



    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< PWM_Driver::initialize_channel << ");
    #endif

    return  m_hal.enable_channel(channel, conf);
}
