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
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/HAL.hpp"

//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "HAL";
#endif

pwm_driver::HAL::HAL() {
}

pwm_driver::HAL::~HAL() {
}
/**
 * @brief initialize a channel for the pwm driver
 *
 * @attention
 *
 *
 * @param[in]   const pwm_driver::pwm_channel_t &channel
 * @param[in]   const pwm_driver::pwm_conf_t &conf
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t pwm_driver::HAL::enable_channel(const pwm_channel_t &channel,
        const pwm_conf_t conf) {
#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::initialize_channel >>");
#endif



#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::initialize_channel << ");
#endif

return GE_FAIL;
}
