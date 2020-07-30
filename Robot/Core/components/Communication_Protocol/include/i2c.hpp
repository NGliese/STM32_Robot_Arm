/*
 * i2c.hpp
 *
 *  Created on: Jul 19, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_COMMUNICATION_PROTOCOL_INCLUDE_I2C_HPP_
#define COMPONENTS_COMMUNICATION_PROTOCOL_INCLUDE_I2C_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  i2c.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, i2c.hpp, is designed as:
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
 |  	Link:[ ], Jul 19, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Jul 19, 2020
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


/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/



class i2c {
public:
	i2c();
	~i2c();
general_err_t write(void);


private:
};



#endif /* COMPONENTS_COMMUNICATION_PROTOCOL_INCLUDE_I2C_HPP_ */
