/*
 * Timeservice.cpp
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
 *  \file       Timeservice.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Timeservice.hpp"


static RTC_HAL m_hal;

//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "Timeservice";
#endif

/**
 * @brief  return the time in tics
 *
 * @attention
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
time_t Timeservice::getTimeNow(void) {
    if(!m_hal.isInitialized())
    {
       if( m_hal.initialize() != GE_OK){
           return GE_FAIL;
       }
    }
return   m_hal.getTime();
}

Timeservice::Timeservice() {
}

Timeservice::~Timeservice() {
}
