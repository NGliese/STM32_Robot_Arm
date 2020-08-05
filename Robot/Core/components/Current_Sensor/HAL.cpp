/*
 * HAL.cpp
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
 *  \file       HAL.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/HAL.hpp"

#ifdef DEBUG
static const char *LOG_TAG = "HAL";
#endif

#ifdef UNIT_TEST_MODE
extern int16_t m_robot_arm[6][2];


#else

#endif

NS_Current_Sensor::HAL::HAL() {


}

NS_Current_Sensor::HAL::~HAL() {
}
/**
 * @brief initialize adc
 *
 *
 * @return
 *    - GE_OK
 */
general_err_t NS_Current_Sensor::HAL::initialize(GPIO_PIN pin) {
    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, ">> enclosing_method >> ");
    #endif
    // Executable code:
    // set ADC pin
       m_adc_pin = pin;

    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, "<< enclosing_method << ");
    #endif

    return GE_OK;
}
/**
 * @brief get the current measurement
 *
 *
 * @param[out] current measurement
 *
 * @return
 *    - N/A
 */
float NS_Current_Sensor::HAL::get_current() {
    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, ">> NS_Current_Sensor::HAL::get_current >> ");
    #endif
    // Executable code:
    // ToDo Measure the current
    float val = get_adc_value();
    // do some convertion
    val*=2;
    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, "<< NS_Current_Sensor::HAL::get_current << ");
    #endif


    return val;
}
/**
 * @brief
 *
 * @attention
 *

 * @param[out]

 */
float NS_Current_Sensor::HAL::get_adc_value() {

#ifdef DEBUG
LOG_PRINT_INFO(LOG_TAG, ">> NS_Current_Sensor::HAL::get_adc_value >> ");
#endif
// Executable code:
#ifdef UNIT_TEST_MODE
return m_robot_arm[m_adc_pin][1];
#else

#endif

#ifdef DEBUG
LOG_PRINT_INFO(LOG_TAG, "<< NS_Current_Sensor::HAL::get_adc_value << ");
#endif

return GE_OK;

}
