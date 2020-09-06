/*
 * Logger.hpp
 *
 *  Created on: Aug 29, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_LOGGING_INCLUDE_LOGGER_HPP_
#define COMPONENTS_LOGGING_INCLUDE_LOGGER_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Logger.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@hotmail.com>
 |
 |  Description  :  This class, Logger.hpp, is designed as:
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


#include "../../Communication_Protocol/include/uart.hpp"
#include "../../Timeservice/include/Timeservice.hpp"
#include <sys/time.h>
#include <ctime>

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/



class Logger {
public:
    Logger(){};
    ~Logger(){};
    general_err_t write_info( std::string info,  std::string value);
  //  general_err_t write_info(const std::string& info, const std::string& value);
    general_err_t write(const std::string& str);
private:
    Timeservice m_timer;

};


#endif /* COMPONENTS_LOGGING_INCLUDE_LOGGER_HPP_ */
