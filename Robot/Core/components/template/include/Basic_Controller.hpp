/*
 * Basic_Controller.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef TEMPLATE_INCLUDE_BASIC_CONTROLLER_HPP_
#define TEMPLATE_INCLUDE_BASIC_CONTROLLER_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Basic_Controller.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, Basic_Controller.hpp, is designed as:
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
 |                              FLOW DIAGRAM                                    |
 +------------------------------------------------------------------------------*/


/*                                                                       yes
 *                                    Status = OK                     |------ [handle_event]--|
 *                                   |-------------- [new event?]-----|                       |---[END]
 *          [Start] -- [Get_Status]--|                                |-----------------------|
 *                                   |Status = fail
 *                                   |-------------- [ERROR]
 */



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
    EVENT_NONE = 0,
    EVENT_RUN
}Controller_event_t;

typedef enum{
    STATUS_OK = 0,
    STATUS_FAIL
}Controller_flag_t;



/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class Basic_Controller {
public:
    Basic_Controller();
    virtual ~Basic_Controller() {};
    general_err_t addEvent(float value);
    Controller_flag_t runStatemachine(void);
protected:
    virtual general_err_t handleEvent(void) = 0; // make pure virtual
    virtual Controller_flag_t getStatus(void) = 0; // make pure virtual
    virtual general_err_t stop(void) = 0; // make pure virtual
    float m_value;
private:
    Controller_event_t m_event = EVENT_NONE;
    typedef enum{
        state_get_status=0,
        state_new_action,
        state_do_action,
        state_end,
        state_error
    }statemachine_states;
    uint8_t m_index_counter = 0;
    statemachine_states m_current_state;
};




#endif /* TEMPLATE_INCLUDE_BASIC_CONTROLLER_HPP_ */
