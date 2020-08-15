/*
 * General_Error.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef BPS_INCLUDE_GENERAL_ERROR_HPP_
#define BPS_INCLUDE_GENERAL_ERROR_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  General_Error.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, General_Error.hpp, is designed as:
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
 |  	Link:[ ], May 22, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], May 22, 2020
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

#include "BASIC.hpp"
#include <string>

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

enum general_err_t {
    GE_OK = 0,
    GE_FAIL,
    GE_OUT_OF_RANGE,
    GE_OVERFLOW,
    GE_UNDERFLOW,
    GE_NULLPTR,
    GE_TIMEOUT,
    GE_NO_DATA,
    GE_UPPER_BOUNDERY,
    GE_LOWER_BOUNDERY,
    GE_NOT_INITIALIZED,
    GE_CLOSED,
	GE_OPEN,
	GE_EMPTY,
	GE_SEMAPHORE_NOT_TAKEN,
	GE_VIRTUAL_SENSOR,
	GE_DEACTIVE,
    GE_ACTIVE,
};

class General_Error {
public:
    static const char* errorToString(general_err_t errCode);
    static void printError(general_err_t errCode);
    static void printError(std::string LOGTAG,general_err_t errCode);

private:
};



#endif /* BPS_INCLUDE_GENERAL_ERROR_HPP_ */
