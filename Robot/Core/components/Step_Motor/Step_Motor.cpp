/*
 * Step_Motor.cpp
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
 *  \file       Step_Motor.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Step_Motor.hpp"
//#define DEBUG (1)

#ifdef DEBUG
static const char *LOG_TAG = "Step_Motor";
#endif

#define PI (3.14)

Step_Motor::Step_Motor() {

}

Step_Motor::~Step_Motor() {

}

/**
 * @brief set the position of the step motor
 *
 *
 * @param[in] deg
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Step_Motor::set_position(const uint16_t deg) {


#ifdef DEBUG
LOG_PRINT_INFO(LOG_TAG, ">> Step_Motor::set_position >> ");
#endif
    if(deg > m_myConfig.max)
    {
        return GE_UPPER_BOUNDERY;
    }
    if(deg < m_myConfig.min)
    {
        return GE_LOWER_BOUNDERY;
    }
    // set position
    m_myCurrentPosition = deg;
    // ToDO HAL-CALL


#ifdef DEBUG
LOG_PRINT_INFO(LOG_TAG, "<< Step_Motor::set_position << ");
#endif
return  m_hal.set_position(m_myCurrentPosition);;
}

/**
 * @brief return current position
 *
 * @param[out] current position
 *
 * @return
 *    - N/A
 */
uint16_t Step_Motor::get_position(void) {
    return (m_myCurrentPosition = m_hal.get_position());
}
/**
 * @brief set motor to reset settings
 *
 *
 * @return
 *    - GE_OK
 */
general_err_t Step_Motor::reset(void) {

    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, ">> Step_Motor::reset >> ");
    #endif
    // set default position
    set_position(m_myConfig.default_position);

    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, "<< Step_Motor::reset << ");
    #endif

    return GE_OK;
}
/**
 * @brief get the angular motor position, in radian
 *
 * @ATTENTION This function calculates the
 *            angular position from degree to radians
 *
 * @return
 *    - N/A
 *    -
 *    -
 */
float Step_Motor::get_angular_position(void) {
    return ((float) get_position() * PI/180.0);
}

general_err_t Step_Motor::initialize(const step_motor_conf_t &conf) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Step_Motor::initialize >>");
    #endif

    m_myConfig = conf;
    m_hal.initialize(m_myConfig.index);
    // set the default position of the motor
    m_myCurrentPosition = m_myConfig.default_position;
    m_hal.set_position(m_myCurrentPosition);

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Step_Motor::initialize << ");
    #endif

    return GE_OK;
}
