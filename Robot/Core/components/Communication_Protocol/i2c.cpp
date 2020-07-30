/*
 * i2c.cpp
 *
 *  Created on: Jul 19, 2020
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
 *  \file       i2c.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/i2c.hpp"

//#define __DEBUG__

#ifdef __DEBUG__
static const char *LOG_TAG = "i2c;"
#endif

i2c::i2c() {
}

i2c::~i2c() {
}

/**
 * @brief
 *
 * @attention
 *
 *
 * @param[in]
 * @param[in]
 *
 * @param[out]
 * @param[out]
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t i2c::write(void) {
	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, ">> i2c::write >> ");
	#endif


	#ifdef __DEBUG__
	LOG_PRINT_INFO(LOG_TAG, "<< i2c::write << ");
	#endif

	return GE_FAIL;
}
