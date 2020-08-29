/*
 * Bender_Controller.hpp
 *
 *  Created on: May 23, 2020
 *      Author: nikolaj
 */

#ifndef BENDER_CONTROLLER_INCLUDE_BENDER_CONTROLLER_HPP_
#define BENDER_CONTROLLER_INCLUDE_BENDER_CONTROLLER_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Bender_Controller.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, Bender_Controller.hpp, is designed as:
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
 |  	Link:[ ], May 23, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], May 23, 2020
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



#include "../../Step_Motor_Controller/include/Step_Motor_Controller.hpp"


/*----------------- DEFAULT INCLUDE -------------------------------------------*/
#include "../../BPS/include/BASIC.hpp"
#include "../../BPS/include/General_Error.hpp"
/*-----------------------------------------------------------------------------*/

#include <cmath>


/*------------------------------------------------------------------------------+
 |                               Typedef                                        |
 +------------------------------------------------------------------------------*/

typedef struct {
    motor_pair_t pair;
    uint16_t element_length = 0; // [mm] // default value
}bender_config_t;

typedef struct {
    int16_t x = 0; // default value
    int16_t y = 0; // default value
}coordinate_t;


/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/


class Bender_Controller : public Step_Motor_Controller {
public:
    Bender_Controller() ;
    Bender_Controller(const bender_config_t& conf) ;
    ~Bender_Controller();
    general_err_t initialize(const bender_config_t& conf);
    general_err_t getEndPoint(coordinate_t * coords);
private:
    bender_config_t m_conf;
};




#endif /* BENDER_CONTROLLER_INCLUDE_BENDER_CONTROLLER_HPP_ */
