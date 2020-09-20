/*
 * main2.cpp
 *
 *  Created on: Jul 30, 2020
 *      Author: nikolaj
 */



#include "main2.h"

#include "../components/BPS/include/BASIC.hpp"
#include "../components/BPS/include/General_Error.hpp"

#include "../components/GPIO/include/GPIO.hpp"

#include "../components/PWM_Driver/include/HAL.hpp"
#include "../components/PWM_Driver/include/PWM_Driver.hpp"

#include "../components/OverAllSystem/include/Single_Step_Motor_Control.hpp"

#include "../components/RTOS/include/Task_Test.hpp"

#include "../components/Current_Sensor/include/Current_Sensor.hpp"

#include "../components/Logging/include/Logger.hpp"


#include "../components/RTOS/include/Fault_Monitor_Task.hpp"
#include "../components/RTOS/include/Robot_Arm_Task.hpp"

#ifdef __STM32__
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#endif


#ifdef __STM32__

int gpio_version_1(void);
int test_i2c_version_1(void);
int scan_i2c_version_1(void);

int set_pwm_enable_version_1(void);

int sys1_version_1(void);

int sys1_version_2(void); // test threads included

int sys1_version_3(void); // real threads included

int current_sensor_version1(void);



int main2(void)
{
  //  gpio_version_1();
  //  scan_i2c_version_1();
  //  test_i2c_version_1();
  //  set_pwm_enable_version_1();
  //  sys1_version_1();
  //  sys1_version_2();
   // sys1_version_3();
    current_sensor_version1();
    // we should never get here
  for(;;);

#if 0
    /* USER CODE END WHILE */
      // start conv
      HAL_ADC_Start(&hadc1);
      // wait for finish
      HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
      // get value
      uint16_t raw = HAL_ADC_GetValue(&hadc1);
#endif
return 0;
}
int current_sensor_version1(void)
{
    Current_Sensor m_sensor;
    sensor_package_t pkg;
    current_conf_t conf;
    conf.basic_conf.m_max_value = 5;
    conf.basic_conf.m_min_value = 0;
    conf.hal_conf.Vmax = 3.300;
    conf.hal_conf.Vmin = 0;
    conf.hal_conf.bitsize = 4095;
    conf.hal_conf.numberOfConv = 20;
    m_sensor.initialize(conf);
    Logger m_log;
    for(;;){
        m_sensor.measure();
        m_sensor.getMeasurement(&pkg);
        int val =  (pkg.measurement)*1000;
        m_log.write_info("main -> measurment ", std::to_string(val ));
        HAL_Delay(20);
    }
    return 0;
}

// threads included
int sys1_version_3(void)
{

    Logger m_log;
    Fault_Monitor_Task m_faul_task;
    Robot_Arm_Task m_robot_task;
    task_conf_t conf;
    conf.name = "Fault Task";
    conf.priority = 5;
    conf.stack_size = 512;
    m_log.write_info("main", "init task");
    m_faul_task.initialize(conf);

    conf.name = "Robot Task";
    conf.priority = 2;
    m_robot_task.initialize(conf);

    m_log.write_info("main", "start task");
    m_faul_task.start();
    m_robot_task.start();
    m_log.write_info("main", "start schedular");

   // vTaskStartScheduler();
    Task::startSchedular();

    for(;;);

}

// threads included
int sys1_version_2(void)
{

    Logger m_log;
    Task_Test m_task;
    task_conf_t conf;
    conf.name = "Test task 1";
    conf.priority = 2;
    conf.stack_size = 100;
    m_log.write_info("main", "init task");
    m_task.initialize(conf);
    m_log.write_info("main", "start task");
    m_task.start();
    m_log.write_info("main", "start schedular");

   // vTaskStartScheduler();
    Task::startSchedular();

    for(;;);

}



int sys1_version_1(void){
    Single_Step_Motor_Control m_sys;

    if(m_sys.initialize() != GE_OK){
        return 1;
    }
    Logger m_log;
    for(;;)
    {
        m_sys.run();
       // std::cout << " Hello world! " << "\n";
        //std::string str = " hello world!\n";
        m_log.write_info("Issues with xx", "150");
      //  HAL_UART_Transmit(&huart2,(uint8_t*)(str.c_str()),str.size(),HAL_MAX_DELAY);
        HAL_Delay(200);
    }
}

int set_pwm_enable_version_1(void)
{
    PWM_Driver driver;
    if( driver.initialze() != GE_OK)
    {
    LOG_PRINT_ERROR("ERROR","FAIL","");
    return 1;
    }
    pwm_driver::pwm_channel_t channel;
    pwm_driver::pwm_conf_t conf;
    conf.frequency = 250;
    conf.duty_cycle = 499;

    channel.channel_number = 4;
    driver.enable_channel(channel, conf);

    while(1);

    return 0;

}
int test_i2c_version_1(void){
    pwm_driver::HAL m_hal;

   if( m_hal.initialze() != GE_OK)
   {
   LOG_PRINT_ERROR("ERROR","FAIL","");
   return 1;
   }
   for(size_t i = 0; i < 100; i++)
   {
   m_hal.test_i2c("Hello World");
   HAL_Delay(1000);

   }
   return 1;
}
// test a gpio pin toggle
int gpio_version_1(void)
{
    basic::GPIO m_gpio;

    gpio_hal::gpio_conf_t conf = gpio_hal::default_output;
    conf.Pin = GPIO_PIN_15;

    m_gpio.initialize(GPIOD, conf);

    for(size_t i = 0; i < 100; i++)
    {
        m_gpio.toggle();
    }
return 0;
}

int scan_i2c_version_1(void){
    pwm_driver::HAL m_hal;

     if( m_hal.initialze() != GE_OK)
     {
     LOG_PRINT_ERROR("ERROR","FAIL","");
     return 1;
     }

     m_hal.scan_i2c();
     HAL_Delay(1000);
     return 1;
}
#else
int main2(void)
{
    return 0;
}
}
#endif
