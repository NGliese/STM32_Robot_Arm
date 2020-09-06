/*
 * HAL.hpp
 *
 *  Created on: Sep 6, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_TIMESERVICE_INCLUDE_RTC_HAL_HPP_
#define COMPONENTS_TIMESERVICE_INCLUDE_RTC_HAL_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  HAL.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, HAL.hpp, is designed as:
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
 |  	Link:[ ], Sep 6, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Sep 6, 2020
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


#include <ctime>

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/



class RTC_HAL {
public:
     RTC_HAL();
     ~RTC_HAL();
     general_err_t initialize(void);
     inline bool isInitialized(void) {return m_initialized;};
     time_t getTime();
private:
     bool m_initialized = false;
#ifdef __STM32__
     RTC_HandleTypeDef hrtc;
#endif
};



#endif /* COMPONENTS_TIMESERVICE_INCLUDE_RTC_HAL_HPP_ */
