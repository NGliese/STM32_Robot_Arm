/*
 * Basic_Controller.cpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */




/***********************************************************************************************+
 *  \brief       -- XX -- Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       Basic_Controller.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/Basic_Controller.hpp"


//#define DEBUG // default uncommeted

#ifdef DEBUG
static const char *LOG_TAG = "Basic_Controller";
#endif

#define MAX_ALLOWED_RUNS (5)

Basic_Controller::Basic_Controller() {
    m_current_state=state_get_status;
}
/**
 * @brief set a value for the next event
 *
 * @attention
 *
 *
 * @param[in] value
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t Basic_Controller::addEvent(float value) {
    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, ">> Basic_Controller::addEvent >> ");
    #endif
    // Executable code:

    m_value = value;
    m_event = EVENT_RUN;

    #ifdef DEBUG
    LOG_PRINT_INFO(LOG_TAG, "<< Basic_Controller::addEvent << ");
    #endif

    return GE_OK;
}
/**
 * @brief run the statemachine
 *
 * @attention
 *
 *
 * @return
 *    - STATUS_OK
 *    - STATUS_FAIL
 *    -
 */
Controller_flag_t Basic_Controller::runStatemachine(void) {

    for(;;)
    {
        if(++m_index_counter > MAX_ALLOWED_RUNS)
        {   // something must have went wrong
            return STATUS_FAIL;
        }

        switch (m_current_state) {
            case state_get_status:
                // test system status
                if(getStatus() != STATUS_OK)
                {   // something is wrong
                    m_current_state = state_error;

                }else
                {   // we are good
                    m_current_state = state_new_action;
                }
                break;
            case state_new_action:
                // look for events
                if(m_event == EVENT_RUN)
                {
                    // event has been read,
                    // time to clear it
                    m_event = EVENT_NONE;
                    // change state
                    m_current_state = state_do_action;
                }
                break;
            case state_do_action:
                // handle event
                handleEvent();
                // change state
                m_current_state = state_end;
                break;
            case state_end:
                // change state
                m_current_state = state_get_status;
                // we have finished the statmachine
                // and everything is working
                m_index_counter = 0;
                return STATUS_OK;
                break;
            case state_error:
                // stop endlessly
                stop();
                break;
            default:
                m_current_state = state_error;
                break;
        }
    }

}
