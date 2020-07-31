/*
 * PCA9685_BPS.hpp
 *
 *  Created on: Jul 30, 2020
 *      Author: nikolaj
 */

#ifndef COMPONENTS_PWM_DRIVER_INCLUDE_PCA9685_BPS_HPP_
#define COMPONENTS_PWM_DRIVER_INCLUDE_PCA9685_BPS_HPP_


uint16_t m_address = 0x40; // pca9685 default address

// Register addresses from data sheet
#define PCA9685_MODE1_REG           (uint8_t)0x00
#define PCA9685_MODE2_REG           (uint8_t)0x01
#define PCA9685_SUBADR1_REG         (uint8_t)0x02
#define PCA9685_SUBADR2_REG         (uint8_t)0x03
#define PCA9685_SUBADR3_REG         (uint8_t)0x04
#define PCA9685_ALLCALL_REG         (uint8_t)0x05
#define PCA9685_LED0_REG            (uint8_t)0x06 // Start of LEDx regs, 4B per reg, 2B on phase, 2B off phase, little-endian
#define PCA9685_PRESCALE_REG        (uint8_t)0xFE
#define PCA9685_ALLLED_REG          (uint8_t)0xFA

// Mode1 register pin layout
#define PCA9685_MODE_RESTART        (uint8_t)0x80
#define PCA9685_MODE_EXTCLK         (uint8_t)0x40
#define PCA9685_MODE_AUTOINC        (uint8_t)0x20
#define PCA9685_MODE_SLEEP          (uint8_t)0x10
#define PCA9685_MODE_SUBADR1        (uint8_t)0x08
#define PCA9685_MODE_SUBADR2        (uint8_t)0x04
#define PCA9685_MODE_SUBADR3        (uint8_t)0x02
#define PCA9685_MODE_ALLCALL        (uint8_t)0x01

#define PCA9685_SW_RESET            (uint8_t)0x06 // Sent to address 0x00 to reset all devices on Wire line
#define PCA9685_PWM_FULL            (uint16_t)0x01000 // Special value for full on/full off LEDx modes

#define MIN_PWM_FREQUENCY (25)
#define MAX_PWM_FREQUENCY (1500)

#endif /* COMPONENTS_PWM_DRIVER_INCLUDE_PCA9685_BPS_HPP_ */
