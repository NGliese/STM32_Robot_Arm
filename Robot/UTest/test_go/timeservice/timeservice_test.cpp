/*
 * thermal_camera_test.cpp
 *
 *  Created on: May 28, 2020
 *      Author: espenv
 */


#include <cstdint>

#include "CppUTest/TestHarness.h"

#include "../../../Core/components/Timeservice/include/Timeservice.hpp"







TEST_GROUP(TIMSERV_GRP)
{
    Timeservice m_timer;
	void setup(){

	}
	void teardown(){

	}
};


// test to see if init of image is correct
TEST(TIMSERV_GRP, INIT)
{

LONGS_EQUAL(10,m_timer.getTimeNow());

}

