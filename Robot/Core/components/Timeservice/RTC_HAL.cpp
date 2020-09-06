/*
 * RTC_HAL.cpp
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
 *  \file       RTC_HAL.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/RTC_HAL.hpp"

//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "RTC_HAL";
#endif

RTC_HAL::RTC_HAL() {
}

RTC_HAL::~RTC_HAL() {
}
/**
 * @brief    initialize the hal
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t RTC_HAL::initialize(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> RTC_HAL::initialize >>");
    #endif

#ifdef __STM32__
    hrtc.Instance = RTC;
    hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    hrtc.Init.AsynchPrediv = 127;
    hrtc.Init.SynchPrediv = 255;
    hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
    hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
    if (HAL_RTC_Init(&hrtc) != HAL_OK)
    {
      exit(1);
    }
#endif


    m_initialized = true;
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< RTC_HAL::initialize << ");
    #endif

    return GE_OK;
}
/**
 * @brief return the current tick in ms
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
time_t RTC_HAL::getTime() {
#ifdef __STM32__
    return HAL_GetTick();
#else
    return 10;
#endif
}
