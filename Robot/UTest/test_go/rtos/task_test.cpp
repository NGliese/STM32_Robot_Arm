/*
 * thermal_camera_test.cpp
 *
 *  Created on: May 28, 2020
 *      Author: espenv
 */


#include <cstdint>

#include "CppUTest/TestHarness.h"

#include "../../../Core/components/RTOS/include/Task_Test.hpp"




// we are testing the task indirecty by creating a class inheritatin the task


TEST_GROUP(TASK_GRP)
{
    Task_Test m_task;
    task_conf_t m_conf;

	void setup(){
	    m_task.initialize(m_conf);
	}
	void teardown(){
	    m_task.stopSchedular();
	}
};


// test to see if init of image is correct
TEST(TASK_GRP, NOT_INIT)
{
    Task_Test task;
CHECK_EQUAL(GE_NOT_INITIALIZED,task.start());

}

// test to see if init of image is correct
TEST(TASK_GRP, NOT_INIT2)
{
    Task_Test task;
CHECK_EQUAL(GE_NOT_INITIALIZED,task.stop());

}
// test to see if init of image is correct
TEST(TASK_GRP,INIT)
{

    CHECK_EQUAL(GE_OK,m_task.start());

}
// test to see if init of image is correct
TEST(TASK_GRP,ACTIVE_ACTIVE)
{
    m_task.start();
    CHECK_EQUAL(GE_ACTIVE,m_task.start());

}
// test to see if init of image is correct
TEST(TASK_GRP,INIT2)
{

    CHECK_EQUAL(GE_DEACTIVE,m_task.stop());

}
// test to see if init of image is correct
TEST(TASK_GRP,TurnOnThread)
{

    m_task.start();
    // check that the thread is active
    CHECK(m_task.isTaskActive());

}
// test to see if init of image is correct
TEST(TASK_GRP,TurnOnTurnOffThread)
{

    m_task.start();
    m_task.stop();
    // check that the thread is active
    CHECK(!m_task.isTaskActive());

}

// test to see if init of image is correct
TEST(TASK_GRP,start_schedular)
{
    // check that the thread is active
    CHECK(!m_task.isSchedularActive());
    Task::startSchedular();
    CHECK(m_task.isSchedularActive());
}

// test to see if init of image is correct
TEST(TASK_GRP,start_schedular2)
{
    Task_Test task2;
    // check that the thread is active
    CHECK(!m_task.isSchedularActive());
    Task::startSchedular();
    CHECK(task2.isSchedularActive());
}

// test to see if init of image is correct
TEST(TASK_GRP,start_schedular_stop)
{
    Task_Test task2;
    // check that the thread is active
    CHECK(!m_task.isSchedularActive());
    Task::startSchedular();

    Task::stopSchedular();
    CHECK(!task2.isSchedularActive());
}
