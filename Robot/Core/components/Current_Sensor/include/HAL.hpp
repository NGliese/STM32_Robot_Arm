/*
 * HAL.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef CURRENT_SENSOR_INCLUDE_HAL_HPP_
#define CURRENT_SENSOR_INCLUDE_HAL_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  HAL.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
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

#ifdef UNIT_TEST_MODE
#include "../../UNIT_TEST/include/test_case_block.hpp"
#endif

#include <cstdint>


/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/
namespace NS_Current_Sensor{
    class HAL {
    public:
        HAL();
        ~HAL();
        general_err_t initialize(GPIO_PIN pin);
        float get_current();
    private:
        float get_adc_value();

#ifdef UNIT_TEST_MODE
      virtual_motor_t * m_motor;
#endif
        GPIO_PIN m_adc_pin;
    };
}






#endif /* CURRENT_SENSOR_INCLUDE_HAL_HPP_ */
