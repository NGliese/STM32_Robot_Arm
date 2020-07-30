/*
 * General_Error.cpp
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
 *  \file       General_Error.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "include/General_Error.hpp"


#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "General_Error";
#endif

const char* General_Error::errorToString(general_err_t errCode) {
    switch (errCode) {
    case GE_OK:
        return ("OK");
    case GE_FAIL:
        return ("FAIL");
    case GE_OUT_OF_RANGE:
        return ("GE_OUT_OF_RANGE");
    case GE_OVERFLOW:
        return ("GE_OVERFLOW");
    case GE_UNDERFLOW:
        return ("GE_UNDERFLOW");
    case GE_NULLPTR:
        return ("GE_NULLPTR");
    case GE_TIMEOUT:
        return ("GE_TIMEOUT");
    case GE_NO_DATA:
        return ("GE_NO_DATA");
    case GE_UPPER_BOUNDERY:
        return ("GE_UPPER_BOUNDERY");
    case GE_LOWER_BOUNDERY:
        return ("GE_LOWER_BOUNDERY");
    case GE_NOT_INITIALIZED:
        return ("GE_NOT_INITIALIZED");
    case GE_CLOSED:
        return ("GE_CLOSED");
    case GE_EMPTY:
    	return ("GE_EMPTY");
    case GE_SEMAPHORE_NOT_TAKEN:
    	return ("GE_SEMAPHORE_NOT_TAKEN");
    case GE_VIRTUAL_SENSOR:
    	return ("GE_VIRTUAL_SENSOR");
    case GE_OPEN:
    	return ("GE_OPEN");
        default:
            return ("UNKNOWN ERROR CODE");
    }
}

void General_Error::printError(general_err_t errCode) {
    if(errCode == GE_OK)
    {
        return;
    }
    LOG_PRINT_ERROR(LOG_TAG,"ERROR :: %s",errorToString(errCode) );
    return;
}

void General_Error::printError(std::string LOGTAG, general_err_t errCode) {
    if(errCode == GE_OK)
    {
        return;
    }
    LOG_PRINT_ERROR(LOGTAG.c_str(),"ERROR :: %s",errorToString(errCode) );
    return;
}
