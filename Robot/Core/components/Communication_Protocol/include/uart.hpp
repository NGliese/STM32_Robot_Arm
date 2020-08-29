/*
 * uart.hpp
 *
 *  Created on: Aug 29, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_COMMUNICATION_PROTOCOL_INCLUDE_UART_HPP_
#define COMPONENTS_COMMUNICATION_PROTOCOL_INCLUDE_UART_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  uart.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, uart.hpp, is designed as:
 |
 |
 |
 |
 |
 |
 |
 |  version       : 1.0
 |
 |  Return Value  :   return_type
 |
 +-----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------+
 |   		 					Datasheet Awareness              		        |
 +------------------------------------------------------------------------------+
 |
 |
 |  Datasheet Awareness 1):
 |  	Link:[ ], Aug 29, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Aug 29, 2020
 |
 |		Brief:
 |
 |
 |
 |
 |
  +-----------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/

/*---------------- BASIC INCLUDES------------*/
#include "../../BPS/include/BASIC.hpp"
#include "../../BPS/include/General_Error.hpp"
/*-------------------------------------------*/

#include <iostream>

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

namespace stm32_hal{

struct uart_msg_t{
        uint8_t * pData;
        uint16_t size;
};

class uart {
public:
        uart();
        ~uart();
        general_err_t initialize(void);
        general_err_t write(const uart_msg_t & msg);
        inline bool isInitialized(void) {return m_initialize;};
private:
#ifdef __STM32__
        UART_HandleTypeDef huart2;
#endif
         bool  m_initialize = false;
};
}




#endif /* COMPONENTS_COMMUNICATION_PROTOCOL_INCLUDE_UART_HPP_ */
