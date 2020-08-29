/*
 * thermal_camera_test.cpp
 *
 *  Created on: May 28, 2020
 *      Author: espenv
 */


#include <cstdint>

#include "CppUTest/TestHarness.h"

#include "../../../Core/components/Current_Sensor/include/Current_Sensor.hpp"







TEST_GROUP(CURR_SENS_GRP)
{
    Current_Sensor m_sensor;
    current_conf_t conf;
	void setup(){
	    conf.basic_conf.m_max_value = 10;
	    conf.basic_conf.m_min_value = -10;
	    conf.pin = 2;
	    m_sensor.initialize(conf);

	}
	void teardown(){

	}
};


// test to see if init of image is correct
TEST(CURR_SENS_GRP, NOT_INIT)
{
    Current_Sensor sensor;
    CHECK_EQUAL(GE_NOT_INITIALIZED,sensor.Measure());

}

// test to see if init of image is correct
TEST(CURR_SENS_GRP, INIT)
{

    CHECK_EQUAL(GE_OK,m_sensor.Measure());

}

