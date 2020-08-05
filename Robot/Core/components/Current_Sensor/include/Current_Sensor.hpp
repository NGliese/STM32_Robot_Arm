/*
 * Current_Sensor.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef CURRENT_SENSOR_INCLUDE_CURRENT_SENSOR_HPP_
#define CURRENT_SENSOR_INCLUDE_CURRENT_SENSOR_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Current_Sensor.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, Current_Sensor.hpp, is designed as:
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


#include "../../template/include/Basic_Sensor.hpp"
#include "HAL.hpp"
/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class Current_Sensor : public Basic_Sensor{
public:
    Current_Sensor();
    ~Current_Sensor();
    general_err_t initialize(GPIO_PIN pin);
    general_err_t Measure() override;
private:
    NS_Current_Sensor::HAL  m_hal;
};




#endif /* CURRENT_SENSOR_INCLUDE_CURRENT_SENSOR_HPP_ */
