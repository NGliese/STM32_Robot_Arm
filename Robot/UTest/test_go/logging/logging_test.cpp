/*
 * thermal_camera_test.cpp
 *
 *  Created on: May 28, 2020
 *      Author: espenv
 */


#include <cstdint>

#include "CppUTest/TestHarness.h"

#include "../../../Core/components/Logging/include/Logger.hpp"







TEST_GROUP(LOG_GRP)
{
	void setup(){

	}
	void teardown(){

	}
};


// test to see if init of image is correct
TEST(LOG_GRP, INIT)
{
    Logger m_log;

CHECK_EQUAL(GE_OK,m_log.write("hello world"));

}

// test to see if init of image is correct
TEST(LOG_GRP, INIT2)
{
    Logger m_log2;

CHECK_EQUAL(GE_OK,m_log2.write("hello world"));

}

// test to see if init of image is correct
TEST(LOG_GRP, INIT3)
{
    for(size_t i = 0; i < 10; i++)
    {
    Logger m_log;
    CHECK_EQUAL(GE_OK,m_log.write("hello world: "+std::to_string(i)));
    }

}

// test to see if init of image is correct
TEST(LOG_GRP, INIT4)
{

    Logger m_log;
    CHECK_EQUAL(GE_OK,m_log.write_info("current sensor","1522"));


}
