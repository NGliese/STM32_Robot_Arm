/*
 * Logger.cpp
 *
 *  Created on: Aug 29, 2020
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
 *  \file       Logger.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/



#include "include/Logger.hpp"

// we always only want ONE uart
static stm32_hal::uart m_uart;



//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "Logger";
#endif


/**
 * @brief      write to the log
 *
 * @attention
 *
 *
 * @param[in] const std::string &str
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Logger::write(const std::string &str) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> Logger::write >>");
    #endif

    if(!m_uart.isInitialized())
    {
       if( m_uart.initialize() != GE_OK){
           return GE_FAIL;
       }
    }
    stm32_hal::uart_msg_t msg;

    msg.pData = (uint8_t*)str.c_str();
    msg.size = str.size();

    m_uart.write(msg);
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< Logger::write << ");
    #endif

    return GE_OK;
}

/**
 * @brief write a message to the console
 *
 * @format
 *      [ TIME ] [ info ] [ value ]
 *
 *
 * @param[in] const std::string &info
 * @param[in] const std::string &value
 *
 * @param[out]
 * @param[out]
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
#if 0
general_err_t Logger::write_info(const std::string &info,
        const std::string &value) {
#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, ">> Logger::write >>");
#endif

if(!m_uart.isInitialized())
{
   if( m_uart.initialize() != GE_OK){
       return GE_FAIL;
   }
}
stm32_hal::uart_msg_t msg;


auto time_now = time(NULL);


std::string full_msg = std::to_string(time_now) + " :: " + info + " -> " + value;

msg.pData = (uint8_t*)full_msg.c_str();
msg.size = full_msg.size();

m_uart.write(msg);
#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, "<< Logger::write << ");
#endif

return GE_OK;
}
#endif

/**
 * @brief write a message to the console
 *
 * @format
 *      [ TIME ] [ info ] [ value ]
 *
 *
 * @param[in] const std::string &info
 * @param[in] const std::string &value
 *
 * @param[out]
 * @param[out]
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Logger::write_info(std::string info,
        std::string value) {
#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, ">> Logger::write >>");
#endif

if(!m_uart.isInitialized())
{
   if( m_uart.initialize() != GE_OK){
       return GE_FAIL;
   }
}
stm32_hal::uart_msg_t msg;

time_t tim = m_timer.getTimeNow();


std::string full_msg = std::to_string((int)tim)  + " :: "
        + info + " -> " + value +"\r\n\0";

msg.pData = (uint8_t*)full_msg.c_str();
msg.size = full_msg.size();

m_uart.write(msg);
#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, "<< Logger::write << ");
#endif

return GE_OK;
}
