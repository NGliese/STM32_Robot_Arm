/*
 * Step_Motor_Controller.cpp
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
 *  \file       Step_Motor_Controller.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Step_Motor_Controller.hpp"


//#define DEBUG // default uncommeted

#ifdef DEBUG
static const char *LOG_TAG = "Step_Motor_Controller";
#endif


#define FAILURE_BOUNDERY (10)



Step_Motor_Controller::Step_Motor_Controller() {

}

Step_Motor_Controller::Step_Motor_Controller(motor_pair_t* pair) {

    m_motor_pair = *pair;



    // create motor
    m_motor.initialize(m_motor_pair.motor_conf);
    // create sensor
    m_sensor.initialize(m_motor_pair.current_conf);
}

Step_Motor_Controller::~Step_Motor_Controller() {

}

/**
 * @brief  handle event -> this case change position of motor
 *
 * @attention
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Step_Motor_Controller::handleEvent(void) {
    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, ">> Step_Motor_Controller::handleEvent >> ");
    #endif


    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, "<< Step_Motor_Controller::handleEvent << ");
    #endif

    return m_motor.set_position(m_value);
}
/**
 * @brief   get the status of the motor and current sensor
 *
 * @attention
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
Controller_flag_t Step_Motor_Controller::getStatus(void) {
    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, ">> Step_Motor_Controller::getStatus >> ");
    #endif

    Controller_flag_t status;
    m_sensor.measure();
    m_sensor.getMeasurement(&m_package);
    // Evaluate the package
    if(m_package.measurement < FAILURE_BOUNDERY){
    status = STATUS_OK;
    }else{
        status = STATUS_FAIL;
    }
    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, "<< Step_Motor_Controller::getStatus << ");
    #endif

    return status;
}

/**
 * @brief  return position of motor
 *
 * @param[out] [uint16_t] position
 *
 * @return
 *    - N/A
 */
uint16_t Step_Motor_Controller::getPosition(void) {
    return m_motor.get_position();
}

/**
 * @brief   Stop the motor
 *
 * @attention
 *
 *
 *
 * @return
 *    - GE_OK
 */
general_err_t Step_Motor_Controller::stop(void) {
    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, ">> Step_Motor_Controller::stop >> ");
    #endif
    // Executable code:


    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, "<< Step_Motor_Controller::stop << ");
    #endif

    return GE_OK;
}

