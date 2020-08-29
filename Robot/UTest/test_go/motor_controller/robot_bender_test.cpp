/*
 * robot_bender_test.cpp
 *
 *  Created on: May 23, 2020
 *      Author: nikolaj
 */



#include "../../../Core/components/Bender_Controller/include/Bender_Controller.hpp"
#include "CppUTest/TestHarness.h"


#include <cmath>


int16_t m_robot_arm[6][2] ={
        {0,0}, {0,0} ,{0,0} ,{0,0},{0,0},{0,0}
};

// helper function
static coordinate_t calc_pos(uint16_t length, uint16_t pos);


static  coordinate_t calc_pos(uint16_t length, uint16_t pos)
{
    coordinate_t coords;
    coords.x = length* cos( ((float)pos) *3.14/180.0 );
    coords.y = length* sin( ((float)pos) *3.14/180.0 );
    return coords;
}


TEST_GROUP(ROBOTARM_BENDER_GRP)
{
};
// test initialization
TEST(ROBOTARM_BENDER_GRP, init)
{
    bender_config_t conf;
    // set bender config
    conf.element_length = 50;

    // set pair config
    conf.pair.current_conf = {{10,-10,0},0 };
    conf.pair.motor_conf = {75,120,0,1};
    // create bender
    Bender_Controller m_robot_bender(conf);
    // create coords
    coordinate_t coords, expected_coords;

    expected_coords = calc_pos(conf.element_length,conf.pair.motor_conf.default_position );


    m_robot_bender.getEndPoint(&coords);

    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);


}

// test multi initializiotn
TEST(ROBOTARM_BENDER_GRP, multi_test)
{
    bender_config_t conf1,conf2,conf3;
    conf1.element_length = 50;

    conf1.pair.current_conf = {{10,-10,0},0 };
    conf1.pair.motor_conf = {75,120,0,1};
    conf2 = conf3 = conf1;
    conf2.pair.motor_conf.default_position = 50;
    conf3.pair.motor_conf.default_position = 150;
    Bender_Controller m_wrist(conf1),m_albue(conf2),m_arm(conf3);
    coordinate_t coords, expected_coords;

    expected_coords = calc_pos(conf1.element_length,conf1.pair.motor_conf.default_position );
    m_wrist.getEndPoint(&coords);

    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);

    expected_coords = calc_pos(conf2.element_length,conf2.pair.motor_conf.default_position );
    m_albue.getEndPoint(&coords);

    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);

    expected_coords = calc_pos(conf3.element_length,conf3.pair.motor_conf.default_position );
    m_arm.getEndPoint(&coords);

    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);
}

// test set position
TEST(ROBOTARM_BENDER_GRP, Move_Wrist_Bender)
{
    // config the robot
    bender_config_t conf;
    conf.element_length = 50;

    conf.pair.current_conf = {{10,-10,0},0 };
    conf.pair.motor_conf = {75,120,0,1};
    Bender_Controller m_robot_bender(conf);
    coordinate_t coords, expected_coords;
    // calculate the expected position
    expected_coords = calc_pos(conf.element_length,conf.pair.motor_conf.default_position );
    // get the position
    m_robot_bender.getEndPoint(&coords);
    // evaluate
    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);
    // set a new position
    uint16_t newPos = 48;
    m_robot_bender.addEvent(newPos);
    // run the statemachine
    CHECK_EQUAL(STATUS_OK,m_robot_bender.runStatemachine()) ;
    // calulcate expected coords
    expected_coords = calc_pos(conf.element_length,newPos );
    // get position
    m_robot_bender.getEndPoint(&coords);
    // evaluate
    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);
}


// test set position
TEST(ROBOTARM_BENDER_GRP, Move_Wrist__Many_Bender)
{
    // config the robot
    bender_config_t conf;
    conf.element_length = 50;

    conf.pair.current_conf = {{10,-10,0},0 };
    conf.pair.motor_conf = {75,120,0,1};
    Bender_Controller m_robot_bender(conf);
    coordinate_t coords, expected_coords;
    // calculate the expected position
    expected_coords = calc_pos(conf.element_length,conf.pair.motor_conf.default_position );
    // get the position
    m_robot_bender.getEndPoint(&coords);
    // evaluate
    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);
    // set a new position
    uint16_t newPos = 48;
    m_robot_bender.addEvent(newPos);
    // run the statemachine
    CHECK_EQUAL(STATUS_OK,m_robot_bender.runStatemachine()) ;
    // calulcate expected coords
    expected_coords = calc_pos(conf.element_length,newPos );
    // get position
    m_robot_bender.getEndPoint(&coords);
    // evaluate
    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);

    newPos = 5;
    m_robot_bender.addEvent(newPos);
    // run the statemachine
    CHECK_EQUAL(STATUS_OK,m_robot_bender.runStatemachine()) ;
    // calulcate expected coords
    expected_coords = calc_pos(conf.element_length,newPos );
    // get position
    m_robot_bender.getEndPoint(&coords);
    // evaluate
    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);


    newPos = 97;
    m_robot_bender.addEvent(newPos);
    // run the statemachine
    CHECK_EQUAL(STATUS_OK,m_robot_bender.runStatemachine()) ;
    // calulcate expected coords
    expected_coords = calc_pos(conf.element_length,newPos );
    // get position
    m_robot_bender.getEndPoint(&coords);
    // evaluate
    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);

    newPos = 119;
    m_robot_bender.addEvent(newPos);
    // run the statemachine
    CHECK_EQUAL(STATUS_OK,m_robot_bender.runStatemachine()) ;
    // calulcate expected coords
    expected_coords = calc_pos(conf.element_length,newPos );
    // get position
    m_robot_bender.getEndPoint(&coords);
    // evaluate
    CHECK_EQUAL(expected_coords.x,coords.x);
    CHECK_EQUAL(expected_coords.y,coords.y);



}

