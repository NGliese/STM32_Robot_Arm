/*
 * thermal_camera_test.cpp
 *
 *  Created on: May 28, 2020
 *      Author: espenv
 */


#include <cstdint>

#include "CppUTest/TestHarness.h"

//#include "../../../Core/components/BPS/include/BASIC.hpp"

#include "../../../Core/components/OverAllSystem/include/Single_Step_Motor_Control.hpp"





TEST_GROUP(SYS1_GRP)
{
    Single_Step_Motor_Control m_sys;
	void setup(){
	    m_sys.initialize();

	}
	void teardown(){

	}
};


// test to see if init of image is correct
TEST(SYS1_GRP, INIT)
{
    Single_Step_Motor_Control sys;
CHECK_EQUAL(GE_OK,sys.initialize());

}

// test to see if init of image is correct
TEST(SYS1_GRP, NOT_INIT)
{
    Single_Step_Motor_Control sys;
CHECK_EQUAL(GE_NOT_INITIALIZED,sys.run());

}

// test to see if init of image is correct
TEST(SYS1_GRP, RUN)
{
CHECK_EQUAL(GE_OK,m_sys.run());

}
