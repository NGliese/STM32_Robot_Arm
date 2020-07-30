/*
 * HAL.hpp
 *
 *  Created on: Jul 22, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_GPIO_INCLUDE_HAL_HPP_
#define COMPONENTS_GPIO_INCLUDE_HAL_HPP_


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
 |  	Link:[ ], Jul 22, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Jul 22, 2020
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



#ifdef __STM32__
#include "stm32f4xx_hal.h"
#endif




namespace gpio_hal{
/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/
typedef struct{
 uint32_t Pin;       /*!< Specifies the GPIO pins to be configured.
						   This parameter can be any value of @ref GPIO_pins_define */

 uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
						   This parameter can be a value of @ref GPIO_mode_define */

 uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
						   This parameter can be a value of @ref GPIO_pull_define */

 uint32_t Speed;     /*!< Specifies the speed for the selected pins.
						   This parameter can be a value of @ref GPIO_speed_define */

 uint32_t Alternate;  /*!< Peripheral to be connected to the selected pins.
							This parameter can be a value of @ref GPIO_Alternate_function_selection */
}gpio_conf_t;

#ifdef __STM32__
const gpio_conf_t default_output={
    .Pin  =  GPIO_PIN_0,
    .Mode = GPIO_MODE_OUTPUT_PP,
    .Pull = GPIO_PULLUP,
    .Speed= GPIO_SPEED_FREQ_MEDIUM,
    .Alternate = 0
};
#endif

class HAL {
public:
	HAL();
	~HAL();
	general_err_t initialize(GPIO_TypeDef  *GPIOx,const gpio_conf_t& conf);
	general_err_t set_pin(const bool& val);
	bool get_pin_val(void);

private:
#ifdef __STM32__
	GPIO_InitTypeDef convertConfig(void); // we need this function to alter between our HAL and stm32 HAL
#endif
	bool m_initialized = false;
	GPIO_TypeDef * m_port;
	gpio_conf_t m_conf;
};
}


#endif /* COMPONENTS_GPIO_INCLUDE_HAL_HPP_ */
