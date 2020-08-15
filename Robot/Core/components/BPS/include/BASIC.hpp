/*
 * BASIC.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */

#ifndef BPS_INCLUDE_BASIC_HPP_
#define BPS_INCLUDE_BASIC_HPP_


#define DEBUG_PRINT_F(LOG_TAG, expr) (printf(#LOG_TAG " >> " #expr " = %f\n",expr) ) // debug print float
#define DEBUG_PRINT_D(LOG_TAG, expr) (printf(#LOG_TAG " >> " #expr " = %lu\n",expr) ) // debug print digtic
#define DEBUG_PRINT_S(LOG_TAG, expr) (printf(#LOG_TAG " >> " #expr " = %s\n",expr) ) // debug print str

#include <stdio.h>
//#define __ESP32__ (1)
#define UNIT_TEST_MODE (1)

#ifndef UNIT_TEST_MODE
#define __STM32__ (1)
#define __FREERTOS__ (1)
#define SAVE_TO_USB (1)
#endif


//#endif
#if __STM32__
#define LOG_PRINT_INFO(LOG_TAG,str)  (printf( "%s:: %s \n",LOG_TAG,str))
#define LOG_PRINT_ERROR(LOG_TAG,str,str2)  (printf("%s:: [ERROR] -> %s [%s] \n",LOG_TAG ,str,str2))
#endif

#if UNIT_TEST_MODE
#define LOG_PRINT_INFO(LOG_TAG,str)  (printf( "%s:: %s \n",LOG_TAG,str))
#define LOG_PRINT_ERROR(LOG_TAG,str,str2)  (printf("%s:: [ERROR] -> %s [%s] \n",LOG_TAG ,str,str2))
#define GPIO_TypeDef int

#endif


#ifdef __ESP32__
#define		GPIO_PIN (gpio_num_t)
#else
#define GPIO_PIN uint16_t
#endif

#endif /* BPS_INCLUDE_BASIC_HPP_ */
