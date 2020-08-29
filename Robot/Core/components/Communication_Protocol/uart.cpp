/*
 * uart.cpp
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
 *  \file       uart.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/uart.hpp"

using namespace stm32_hal;


//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "uart";
#endif





uart::uart() {
}

uart::~uart() {
}
/**
 * @brief initialize the block
 *
 * @attention  This is based on standard stm32 hal init
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t uart::initialize(void) {

     #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> uart::initialize >>");
    #endif

#ifdef __STM32__
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        exit(1);
    }
#else
    std::cout << " INITIALIZED - UART "<< "\n";
#endif

    m_initialize = true;

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< uart::initialize << ");
    #endif

    return GE_OK;

}
/**
 * @brief  write a msg through uart
 *
 * @attention
 *
 *
 * @param[in] const uart_msg_t &msg
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t uart::write(const uart_msg_t &msg) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> uart::write >>");
    #endif

#ifdef __STM32__
    HAL_UART_Transmit(&huart2,msg.pData,msg.size,HAL_MAX_DELAY);
#else
    std::cout << msg.pData << "\n";
#endif

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< uart::write << ");
    #endif

    return GE_FAIL;
}


