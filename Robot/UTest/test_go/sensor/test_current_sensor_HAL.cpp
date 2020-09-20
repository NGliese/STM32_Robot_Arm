/*
 * thermal_camera_test.cpp
 *
 *  Created on: May 28, 2020
 *      Author: espenv
 */


#include <cstdint>

#include "CppUTest/TestHarness.h"

#include "../../../Core/components/Current_Sensor/include/HAL.hpp"


TEST_GROUP(CURR_SENS__HAL_GRP)
{
    NS_Current_Sensor::HAL m_hal;
    HAL_conf_t conf;
	void setup(){
	    conf.Vmax = 5;
	    conf.Vmin = 0;
	    conf.bitsize = 4095;
	    m_hal.initialize(conf);

	}
	void teardown(){

	}
};


// test to see if init of image is correct
TEST(CURR_SENS__HAL_GRP, NOT_INIT)
{
    NS_Current_Sensor::HAL hal;
    CHECK_EQUAL(GE_NOT_INITIALIZED,hal.measure());

}



// test to see if init of image is correct
TEST(CURR_SENS__HAL_GRP, INIT)
{
    CHECK_EQUAL(GE_OK,m_hal.measure());

}



// test to see if init of image is correct
TEST(CURR_SENS__HAL_GRP, Conv)
{
    DOUBLES_EQUAL(2.5,m_hal.convertToVolt( 4095/2 ) ,3 );

    DOUBLES_EQUAL(0,m_hal.convertToVolt( 0 ) ,3 );

    DOUBLES_EQUAL(5,m_hal.convertToVolt( 4095 ) ,3 );

}


// test to see if init of image is correct
TEST(CURR_SENS__HAL_GRP, Conv_fail)
{
    DOUBLES_EQUAL((-1.234),m_hal.convertToVolt( 4096 ) ,3 );


}


// test to see if init of image is correct
TEST(CURR_SENS__HAL_GRP, Conv2)
{
    LONGS_EQUAL(4095/2,m_hal.convertToADC( 2.5 ) );

    LONGS_EQUAL(0,m_hal.convertToADC( 0 ) );
    // precision is lost here with 1 bit, it is ok
    LONGS_EQUAL(4094,m_hal.convertToADC( 5.0 ));
}
