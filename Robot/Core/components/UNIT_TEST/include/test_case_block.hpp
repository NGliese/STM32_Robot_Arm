/*
 * test_case_block.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef UNIT_TEST_INCLUDE_TEST_CASE_BLOCK_HPP_
#define UNIT_TEST_INCLUDE_TEST_CASE_BLOCK_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  test_case_block.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, test_case_block.hpp, is designed as:
 |
 |
 |
 |
 |
 |
 |
 |  version       : 1.0
 |
 |  Return Value  :   return_type
 |
 +-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/


#include <cstdint>

/*------------------------------------------------------------------------------+
 |   		 					Typedef                  		                |
 +------------------------------------------------------------------------------*/

typedef struct{
    const uint8_t index;
    volatile uint16_t position;
    volatile float current;
}virtual_motor_t;

/* --------------------- VIRTUAL MOTOR SETUP ----------------------------------*/
typedef struct{
    virtual_motor_t grapper      = {0,0,0};
    virtual_motor_t wrist_rotator= {1,0,0};
    virtual_motor_t writst_bender= {2,0,0};
    virtual_motor_t albue_bender = {3,0,0};
    virtual_motor_t arm_bender   = {4,0,0};
    virtual_motor_t arm_rotator  = {5,0,0};
}Robot_Arm_t;

//extern int16_t m_robot_arm[6][2];
//extern int16_t m_robot_arm[6][2];


#endif /* UNIT_TEST_INCLUDE_TEST_CASE_BLOCK_HPP_ */
