/*
 * thermal_camera_test.cpp
 *
 *  Created on: May 28, 2020
 *      Author: espenv
 */


#include <cstdint>

#include "CppUTest/TestHarness.h"

//#include "../../../Core/components/BPS/include/BASIC.hpp"

#include "../../../Core/components/Sensor_Thread/include/Mains_Current_Sensor_Task.hpp"





TEST_GROUP(CURR_TASK_GRP)
{
    Mains_Current_Sensor_Task m_task;
    task_conf_t conf;
	void setup(){

	}
	void teardown(){

	}
};


// test to see if init of image is correct
TEST(CURR_TASK_GRP, NOTINIT)
{

CHECK_EQUAL(GE_NOT_INITIALIZED,m_task.start());

}

