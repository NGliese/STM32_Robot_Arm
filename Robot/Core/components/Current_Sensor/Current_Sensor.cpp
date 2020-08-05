/*
 * Current_Sensor.cpp
 *
 *  Created on: May 22, 2020
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
 *  \file       Current_Sensor.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Current_Sensor.hpp"

#ifdef DEBUG
static const char *LOG_TAG = "Current_Sensor";
#endif

Current_Sensor::Current_Sensor() {
    m_config.m_max_value = 15;
    m_config.m_min_value = 0;
}

Current_Sensor::~Current_Sensor() {

}

general_err_t Current_Sensor::initialize(GPIO_PIN pin) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Current_Sensor::initialize >>");
    #endif
    m_hal.initialize(pin);


    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Current_Sensor::initialize << ");
    #endif

    return GE_OK;

}
/**
 * @brief      measure the current
 *
 * @attention
 *
 *
 * @param[in]
 * @param[in]
 *
 * @param[out]
 * @param[out]
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Current_Sensor::Measure() {

#ifdef DEBUG
LOG_PRINT_INFO(LOG_TAG, ">> Current_Sensor::Measure >> ");
#endif
// Executable code:
float val = m_hal.get_current();

if(m_config.m_max_value > val and m_config.m_min_value < val)
{
    m_package.measurement = val;
    m_package.flag = DATA_READY;
}

#ifdef DEBUG
LOG_PRINT_INFO(LOG_TAG, "<< Current_Sensor::Measure << ");
#endif

return GE_OK;

}

