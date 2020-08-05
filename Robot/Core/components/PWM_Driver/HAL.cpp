/***********************************************************************************************+
 *  \brief       -- XX -- Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       HAL.cpp
 *  \author     N.G Pedersen <nikolajgliese@hotmail.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/HAL.hpp"
#include "include/PCA9685_BPS.hpp"
#define I2C_WRITE_BIT (0)
#define I2C_READ_BIT  (1)
//#define __DEBUG__ (1)
#ifdef __DEBUG__
static const char *LOG_TAG = "HAL";
#endif

pwm_driver::HAL::HAL() {
}

pwm_driver::HAL::~HAL() {
}
/**
 * @brief  Initialize the block
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t pwm_driver::HAL::initialze(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::initialze >>");
    #endif




#ifdef __STM32__

    // configurate the GPIO pin
    GPIO_InitTypeDef GPIO_InitStruct;
    // PIN_6 is I2C1_SCL
    // PIN 9 is I2C1_SDA
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    __GPIOB_CLK_ENABLE();
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    // initialize i2c
    hI2C = I2C_HandleTypeDef();
    hI2C.Instance = I2C1;
    hI2C.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hI2C.Init.ClockSpeed = 200000; // 10240;
    hI2C.Init.DutyCycle = I2C_DUTYCYCLE_2;
    // enable clk1
    __I2C1_CLK_ENABLE();

   if (HAL_I2C_Init(&hI2C) != HAL_OK)
   {
       return GE_FAIL;
   }

   if(GE_OK != resetDevice())
   {
   return GE_FAIL;
   }
   pwm_conf_t conf;
   conf.frequency = 500;
   // set the pwm config
   if(GE_OK != setPWMConfig(conf))
   {
       return GE_FAIL;
   }

   #endif


    m_initialized = true;

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::initialze << ");
    #endif

    return GE_OK;
}
/**
 * @brief initialize a channel for the pwm driver
 *
 * @attention
 *
 *
 * @param[in]   const pwm_driver::pwm_channel_t &channel
 * @param[in]   const pwm_driver::pwm_conf_t &conf
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t pwm_driver::HAL::enable_channel(const pwm_channel_t &channel,
        const pwm_conf_t & conf) {
#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::initialize_channel >>");
#endif
    if(!m_initialized)
    {
        return GE_NOT_INITIALIZED;
    }

   if(GE_OK != setPWMDutyCycle(channel,conf.duty_cycle))
   {
       return GE_FAIL;
   }
   wakeUpDriver();

#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::initialize_channel << ");
#endif

return GE_OK;
}
/**
 * @brief  test the i2c connection by sending over a string
 *
 * @param[in] const std::string &str
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */

general_err_t pwm_driver::HAL::test_i2c(const std::string &str) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::test_i2c >>");
    #endif

#ifdef __STM32__
    if (HAL_I2C_Master_Transmit(&hI2C, (m_address << 1) | I2C_WRITE_BIT, (uint8_t *)"1234", 4, 10000) != HAL_OK)
    {
        return GE_FAIL;
    }
#endif

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::test_i2c << ");
    #endif

    return GE_OK;
}
/**
 * @brief scan the i2c network
 *
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t pwm_driver::HAL::scan_i2c(void) {
#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::scan_i2c >>");
#endif

#ifdef __STM32__
for (uint8_t i = 1; i < 0xff; i++)
{
    if (HAL_I2C_Master_Transmit(&hI2C, i, (uint8_t *)"0", 1, 10000) == HAL_OK)
    {
        std::cout << "Found devie : " << std::hex << i << '\n';
    }
}
#endif

#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::scan_i2c << ");
#endif

return GE_OK;
}
/**
 * @brief config the pwm driver
 *
 *
 * @param[in] const pwm_conf_t &conf
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t pwm_driver::HAL::setPWMConfig(const pwm_conf_t &conf) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::setPWMConfig >>");
    #endif

    if(GE_OK != setPWMFrequency(conf.frequency))
    {
        return GE_FAIL;
    }

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::setPWMConfig << ");
    #endif

    return GE_OK;
}
/**
 * @brief set frequency
 *
 * @attention frequency span is between 25 Hz and 1500 Hz
 *
 *
 * @param[in] uint32_t frequency
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */

general_err_t pwm_driver::HAL::setPWMFrequency(uint32_t frequency) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::setPWMFrequency >>");
    #endif
    if( (frequency < MIN_PWM_FREQUENCY) or (frequency > MAX_PWM_FREQUENCY) )
    {
        return GE_FAIL;
    }
    // This equation comes from section 7.3.5 of the datasheet, but the rounding has been
    // removed because it isn't needed. Lowest freq is 23.84, highest is 1525.88.
    int preScalerVal = (25000000 / (4096 * frequency)) - 1;
    if (preScalerVal > 255) preScalerVal = 255;
    if (preScalerVal < 3) preScalerVal = 3;


#ifdef __STM32__
#if 0
    uint8_t mode1Reg = readRegister(PCA9685_MODE1_REG) ;
    writeRegister(PCA9685_MODE1_REG, (mode1Reg = (mode1Reg & ~PCA9685_MODE_RESTART) | PCA9685_MODE_SLEEP));
    writeRegister(PCA9685_PRESCALE_REG, (uint8_t)preScalerVal);
    // It takes 500us max for the oscillator to be up and running once SLEEP bit has been set to logic 0.
    writeRegister(PCA9685_MODE1_REG, (mode1Reg = (mode1Reg & ~PCA9685_MODE_SLEEP) | PCA9685_MODE_RESTART));
#endif




    uint8_t oldmode = readRegister(PCA9685_MODE1_REG);
    uint8_t newmode = (oldmode & ~PCA9685_MODE_RESTART) | PCA9685_MODE_SLEEP; // sleep
    writeRegister(PCA9685_MODE1_REG, newmode);                             // go to sleep
    writeRegister(PCA9685_PRESCALE_REG, (uint8_t)preScalerVal); // set the prescaler
    writeRegister(PCA9685_MODE1_REG, oldmode);
    HAL_Delay(500);
    // This sets the MODE1 register to turn on auto increment.
    writeRegister(PCA9685_MODE1_REG, oldmode | PCA9685_MODE_RESTART | PCA9685_MODE_AUTOINC);


#endif


    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::setPWMFrequency << ");
    #endif

    return GE_OK;
}



/**
 * @brief  set dutycycle
 *
 * @attention the duty cycle span is between 0 and 100
 *
 *
 * @param[in] uint8_t duty
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */

general_err_t pwm_driver::HAL::setPWMDutyCycle(const pwm_channel_t &channel,uint16_t duty) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::setPWMDutyCycle >>");
    #endif

    if(duty > 1000)
    {
        duty = 1000;
    }
    // access pwm address
    uint8_t regAddress = PCA9685_LED0_REG + (channel.channel_number * 0x04);
    uint16_t phaseBegin  = 0;
    uint16_t phaseEnd = 4095/(1000.0 / (float)duty);


    // write the given duty cycle to the given driver
    writeRegister(regAddress + 0x00, lowByte(phaseBegin));   // LEDx_L0
    writeRegister(regAddress + 0x01, highByte(phaseBegin));  // LEDx_H0
    writeRegister(regAddress + 0x02, lowByte(phaseEnd));     // LEDx_L1
    writeRegister(regAddress + 0x03, highByte(phaseEnd));    // LEDx_H1



    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::setPWMDutyCycle << ");
    #endif

    return GE_OK;
}
/**
 * @brief  read 8 bit register value
 *
 * @param[in] uint8_t *reg
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
uint8_t pwm_driver::HAL::readRegister(const uint8_t & reg) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::readRegister >>");
    #endif

    uint8_t parser[1] = {reg};
    uint8_t read_register = 0;
#ifdef __STM32__
    if(HAL_I2C_Master_Transmit(&hI2C, (m_address << 1) | I2C_WRITE_BIT, parser, 1, 10000) != HAL_OK)
    {
        return 0;
    }

    if( HAL_I2C_Master_Receive(&hI2C, (m_address << 1) | I2C_READ_BIT, &read_register, 1, 10000) != HAL_OK)
    {
        return 0;
    }
#endif

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::readRegister << ");
    #endif

    return read_register ;
}
/**
 * @brief   write to a register
 *
 * @attention
 *
 *
 * @param[in] const uint8_t &reg
 * @param[in]  const uint8_t &data
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
uint8_t pwm_driver::HAL::writeRegister(const uint8_t &reg,
        const uint8_t &data) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::writeRegister >>");
    #endif

    uint8_t parser[2] = {reg,data};
#ifdef __STM32__
    if(HAL_I2C_Master_Transmit(&hI2C, (m_address << 1) | I2C_WRITE_BIT, parser, 2, 10000) != HAL_OK)
    {
        return GE_FAIL;
    }
#endif

    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::writeRegister << ");
    #endif

    return GE_OK;
}
/**
 * @brief  return the low 8 bits of the 16 bit var
 *
 * @param[in] 16 byte
 *
 * @param[out] low 8 byte
 *
 * @return
 *    - N/A
 */
uint8_t pwm_driver::HAL::lowByte(uint16_t byte) {
    return (uint8_t)(byte >> 0);
}
/**
 * @brief  return the high 8 bits of the 16 bit var
 *
 * @param[in] 16 byte
 *
 * @param[out] high 8 byte
 *
 * @return
 *    - N/A
 */
uint8_t pwm_driver::HAL::highByte(uint16_t byte) {
    return (uint8_t)(byte >> 8);
}
/**
 * @brief   reset the pwm driver after power on
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t pwm_driver::HAL::resetDevice(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::resetDevice >>");
    #endif
#ifdef __STM32__

    uint8_t parser[1] ={PCA9685_SW_RESET};

#ifdef __STM32__
    // reset all pwm chips
    if(HAL_I2C_Master_Transmit(&hI2C, 0x00, parser, 1, 10000) != HAL_OK)
    {
        return GE_FAIL;
    }
#endif
    //writeRegister(PCA9685_MODE1_REG, PCA9685_MODE_RESTART);
    HAL_Delay(1000);

    uint8_t oldmode = readRegister(PCA9685_MODE1_REG);


#if 0
    uint8_t data =PCA9685_SW_RESET;
    if(HAL_I2C_Master_Transmit(&hI2C, 0x00, &data, 1, 10000) != HAL_OK)
    {
        return GE_FAIL;
    }
#endif

#endif


    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::resetDevice << ");
    #endif

    return GE_OK;
}

general_err_t pwm_driver::HAL::wakeUpDriver(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> pwm_driver::HAL::wakeUpDriver >>");
    #endif

    uint8_t sleep = readRegister(PCA9685_MODE1_REG);
     uint8_t wakeup = sleep & ~PCA9685_MODE_SLEEP; // set sleep bit low
     // if the two registers are different, it must mean, that the driver is sleeping
     // therefor we need to wake it up.
     if(sleep != wakeup){
     writeRegister(PCA9685_MODE1_REG, wakeup);
     }
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< pwm_driver::HAL::wakeUpDriver << ");
    #endif

    return GE_OK;
}
