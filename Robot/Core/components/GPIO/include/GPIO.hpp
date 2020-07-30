/*
 * GPIO.hpp
 *
 *  Created on: Jul 21, 2020
 *      Author: nikolaj
 */




/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  GPIO.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, GPIO.hpp, is designed as:
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
 |  	Link:[ ], Jul 21, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Jul 21, 2020
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

// BASIC INCLUDES
#include "../../BPS/include/BASIC.hpp"
#include "../../BPS/include/General_Error.hpp"
//-----------------------------------------------

#include "HAL.hpp"

namespace basic{
/*------------------------------------------------------------------------------+
 |   		 					 Typedef                     		                |
 +------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class GPIO {
public:
	GPIO();
	~GPIO();
	general_err_t initialize(const gpio_hal::gpio_conf_t &conf);
	general_err_t set_high(void);
	general_err_t set_low(void);
	bool get_level(void);

private:
	bool m_initialize = false;
	gpio_hal::HAL m_hal;
};

}
