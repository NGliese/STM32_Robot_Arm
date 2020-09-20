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

#ifdef __STM32__
#include "stm32f4xx_hal.h"
#endif

struct HAL_conf_t{
        float Vmax = 0;
        float Vmin = 0;
        uint16_t bitsize = 0; // stm32f4 has pr default 12 bits -> 2^(12)-1 = 4095
        uint16_t pin = 0;
        uint16_t numberOfConv = 1;
};

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/
namespace NS_Current_Sensor{
    class HAL {
    public:
        HAL();
        ~HAL();
        general_err_t initialize(const HAL_conf_t & conf);
        general_err_t measure(void);
        float getMeasurement();
        float convertToVolt(uint16_t adcVal);
        uint16_t convertToADC(float Val);
    private:
        uint16_t get_adc_value();
        bool m_inititalized = false;
        uint16_t m_raw = 0;
#ifdef UNIT_TEST_MODE
      virtual_motor_t * m_motor = nullptr;
#endif


        HAL_conf_t m_conf;
        float bitConverter = 0;
    };
}





#endif /* CURRENT_SENSOR_INCLUDE_HAL_HPP_ */
