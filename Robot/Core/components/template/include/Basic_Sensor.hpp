/*
 * Basic_Sensor.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef TEMPLATE_INCLUDE_BASIC_SENSOR_HPP_
#define TEMPLATE_INCLUDE_BASIC_SENSOR_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Basic_Sensor.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, Basic_Sensor.hpp, is designed as:
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



#include "../../BPS/include/BASIC.hpp"
#include "../../BPS/include/General_Error.hpp"

#include <cstdint>


/*------------------------------------------------------------------------------+
 |                              TYPEDEF                                         |
 +------------------------------------------------------------------------------*/

typedef enum{
    DATA_READY = 0,
    DATA_NOT_READY,
    DATA_NOT_VALID,
    DATA_NOT_UPDATED
}DATA_FLAG_t;

typedef struct{
    DATA_FLAG_t flag;
    float measurement;
}sensor_package_t;

// bounderies of measurement
typedef struct{
 int16_t m_min_value = -10; // default value
 int16_t m_max_value = 10;  // default value
 float m_raw = 0;           // default value
}basic_sensor_config_t;
/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class Basic_Sensor {
public:
    Basic_Sensor();
    virtual ~Basic_Sensor() {};
    virtual general_err_t Measure() = 0; // make pure virtual
    general_err_t getMeasurement(sensor_package_t * package);
protected:

    basic_sensor_config_t m_basic_config;
    sensor_package_t m_package;
private:

};




#endif /* TEMPLATE_INCLUDE_BASIC_SENSOR_HPP_ */
