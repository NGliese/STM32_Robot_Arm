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
#endif
extern PWM_Driver m_driver;
NS_Step_Motor::HAL::HAL() {


}

NS_Step_Motor::HAL::~HAL() {
}
/**
 * @brief set the position of the motor
 *
 * @attention
 *
 *
 * @param[in] position
 *
 * @return
 *    - 0
 */
general_err_t NS_Step_Motor::HAL::set_position(uint16_t pos) {

    m_myPosition = pos;
    // ToDo calculate PWM signal
    uint16_t pwm_signal = m_driver.get_max_duty() * ( (float) pos / 120.0f ); // duty = duty_max * ( pos / max_pos )
    return set_pwm(pwm_signal);
}

uint16_t NS_Step_Motor::HAL::get_position(void) {

    return m_myPosition;
}

/**
 * @brief initialize HAL
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t NS_Step_Motor::HAL::initialize(GPIO_PIN pin) {

#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, ">> NS_Step_Motor::HAL::initialize >>");
#endif
    m_pin = pin;
    m_channel.channel_number = pin;
    m_pwm_conf.duty_cycle    = 0;
    m_pwm_conf.frequency     = 500;
#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, "<< NS_Step_Motor::HAL::initialize << ");
#endif


    return GE_OK;
}

/**
 * @brief set duty cycle
 *
 * @attention
 *
 *
 * @param[in] duty_cycle
 *
 * @return
 *    - GE_OK
 */
general_err_t NS_Step_Motor::HAL::set_pwm(uint16_t duty_cycle) {

#ifdef UNIT_TEST_MODE
    m_robot_arm[m_pin][0] = duty_cycle;
#endif
    // ToDo IMPLEMENT HARDWARE HANDLE
    m_pwm_conf.duty_cycle = duty_cycle;
    m_driver.enable_channel(m_channel, m_pwm_conf);
    return GE_OK;
}
