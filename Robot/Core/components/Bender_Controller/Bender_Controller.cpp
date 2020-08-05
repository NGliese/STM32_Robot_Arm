/*
 * Bender_Controller.cpp
 *
 *  Created on: May 23, 2020
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
 *  \file       Bender_Controller.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Bender_Controller.hpp"


//#define DEBUG // default uncommeted

#ifdef DEBUG
static const char *LOG_TAG = "Bender_Controller";
#endif



Bender_Controller::Bender_Controller() {


}


Bender_Controller::Bender_Controller(const bender_config_t &conf) {
    initialize(conf);
}
Bender_Controller::~Bender_Controller() {

}
general_err_t Bender_Controller::initialize(const bender_config_t &conf) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Bender_Controller::initialize >>");
    #endif


    // set motor config
    step_motor_conf_t step_conf = conf.conf;
    step_conf.index = conf.pair.step_motor_index;

    // set config
    m_conf = conf;
    // create motor
    m_motor.initialize(step_conf);
    // create sensor
    m_sensor.initialize(conf.pair.step_motor_index);

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Bender_Controller::initialize << ");
    #endif

    return GE_FAIL;
}

/**
 * @brief get 2d coords of local bender
 *
 * @attention
 *
 *
 * @param[out]  coordinate_t *coords
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Bender_Controller::getEndPoint(
        coordinate_t *coords) {
    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, ">> Bender_Controller::getEndPoint >> ");
    #endif
    // Executable code:
    coords->x = m_conf.element_length * cos(m_motor.get_angular_position());
    coords->y = m_conf.element_length * sin(m_motor.get_angular_position());

    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, "<< Bender_Controller::getEndPoint << ");
    #endif

    return GE_OK;
}


