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

}

Current_Sensor::~Current_Sensor() {

}

general_err_t Current_Sensor::initialize(const current_conf_t &conf) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Current_Sensor::initialize >>");
    #endif
    m_conf = conf;
    m_hal.initialize(m_conf.hal_conf);

    m_initialized = true;

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
general_err_t Current_Sensor::measure() {

#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, ">> Current_Sensor::Measure >> ");
#endif
    if(!m_initialized)
    {
        return GE_NOT_INITIALIZED;
    }
    general_err_t err = GE_OK;
    err = m_hal.measure();

    if(err != GE_OK)
    {
       return err;
    }

    // Executable code:
    float val = m_hal.getMeasurement();

    if(m_basic_config.m_max_value > val and m_basic_config.m_min_value < val)
    {
    m_package.measurement = val;
    m_package.flag = DATA_READY;
    }

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Current_Sensor::Measure << ");
    #endif

    return GE_OK;

}

