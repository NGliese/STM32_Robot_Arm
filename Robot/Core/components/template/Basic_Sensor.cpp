/*
 * Basic_Sensor.cpp
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
 *  \file       Basic_Sensor.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Basic_Sensor.hpp"

#ifdef DEBUG
static const char *LOG_TAG = "Basic_Sensor";
#endif

#define DEFAULT_MAX (100)
#define DEFAULT_MIN (0)
#define DEFAULT_VALUE (0)
Basic_Sensor::Basic_Sensor() {

    // reset package values
    m_package.flag = DATA_NOT_READY;
    m_package.measurement = DEFAULT_VALUE;

    // reset config values
    m_basic_config.m_max_value = DEFAULT_MAX;
    m_basic_config.m_min_value = DEFAULT_MIN;
    m_basic_config.m_raw = DEFAULT_VALUE;

}

/**
 * @brief return a sensor package
 *
 * @param[out] package
 *
 * @return
 *    - GE_OK
 */
general_err_t Basic_Sensor::getMeasurement(
        sensor_package_t *package) {

#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, ">> Basic_Sensor::getMeasurement >> ");
#endif
    // return the package
    *package = m_package;
    // reset the package's dataflag:
    m_package.flag = DATA_NOT_READY;

#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, "<< Basic_Sensor::getMeasurement << ");
#endif

return GE_OK;




}
