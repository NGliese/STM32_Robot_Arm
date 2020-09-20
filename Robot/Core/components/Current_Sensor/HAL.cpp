/*
 * HAL.cpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */




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
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/


#include "include/HAL.hpp"

#define ERROR_INDICATOR (-1.234)
static void stm32_hal_adc_init(void);

#ifdef __STM32__
      ADC_HandleTypeDef hadc1;
#endif

#ifdef __DEBUG__
static const char *LOG_TAG = "HAL";
#endif

#ifdef UNIT_TEST_MODE
extern int16_t m_robot_arm[6][2];


#else

#endif

NS_Current_Sensor::HAL::HAL() {


}

NS_Current_Sensor::HAL::~HAL() {
}
/**
 * @brief initialize adc
 *
 *
 * @return
 *    - GE_OK
 */
general_err_t NS_Current_Sensor::HAL::initialize(const HAL_conf_t & conf) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> enclosing_method >> ");
    #endif
    // Executable code:
    // set ADC pin
       m_conf = conf;
       // to reduce computation time, we will store the ratio as a float here:
       bitConverter =  (float)(m_conf.Vmax - m_conf.Vmin) / (m_conf.bitsize);

       // initialize the adc hal from the
       // stm32 driver code
       stm32_hal_adc_init();

       m_inititalized = true;
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< enclosing_method << ");
    #endif

    return GE_OK;
}
/**
 * @brief get the current measurement in voltage
 *
 *
 * @param[out] current measurement
 *
 * @return
 *    - N/A
 */
float NS_Current_Sensor::HAL::getMeasurement() {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> NS_Current_Sensor::HAL::get_current >> ");
    #endif
    // Executable code:
    // ToDo Measure the current
    uint16_t val = get_adc_value();
    // do some convertion from adc value to voltage
    return convertToVolt(val);
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< NS_Current_Sensor::HAL::get_current << ");
    #endif


    return val;
}
/**
 * @brief
 *
 * @attention
 *

 * @param[out]

 */
uint16_t NS_Current_Sensor::HAL::get_adc_value() {

#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, ">> NS_Current_Sensor::HAL::get_adc_value >> ");
#endif
// Executable code:
#ifdef UNIT_TEST_MODE
return m_robot_arm[m_conf.pin][1];
#else

return m_raw;


#endif

#ifdef __DEBUG__
LOG_PRINT_INFO(LOG_TAG, "<< NS_Current_Sensor::HAL::get_adc_value << ");
#endif

return GE_OK;

}
/**
 * @brief convert the adc value to a voltage
 *
 * @attention
 *
 *
 * @param[in] uint16_t adcVal
 * @param[in]
 *
 * @param[out] float
 * @param[out]
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */

float NS_Current_Sensor::HAL::convertToVolt(uint16_t adcVal) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> NS_Current_Sensor::HAL::convertToVolt >>");
    #endif

    // we have to make sure, that our measured value do
    // not exceed the maximum limit.
    // and if it does, we have no choice but to return -1.23
    if(adcVal > m_conf.bitsize)
    {
        return ERROR_INDICATOR;
    }

    return  adcVal * bitConverter;


    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< NS_Current_Sensor::HAL::convertToVolt << ");
    #endif

    return 0;
}
/**
 * @brief  Measure the adc
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
general_err_t NS_Current_Sensor::HAL::measure(void) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> NS_Current_Sensor::HAL::measure >>");
    #endif
    if(!m_inititalized)
    {
        return GE_NOT_INITIALIZED;
    }

#ifdef __STM32__

    uint32_t raw = 0;
for(size_t i = 0 ; i < m_conf.numberOfConv; i++){

    /* USER CODE END WHILE */
     // start conv
     HAL_ADC_Start(&hadc1);
     // wait for finish
     HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
     // get value
     raw += HAL_ADC_GetValue(&hadc1);
}
    if(raw == 0)
    {
        return GE_FAIL;
    }
    m_raw = raw / m_conf.numberOfConv;

#endif
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< NS_Current_Sensor::HAL::measure << ");
    #endif

    return GE_OK;
}
/**
 * @brief Convert a voltage to a adc value
 * @param[in] float Val
 *
 * @param[out] uint16_t
 *
 * @return
 *    - GE_OK
 *    -
 *    -
 */
uint16_t NS_Current_Sensor::HAL::convertToADC(float Val) {
    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, ">> NS_Current_Sensor::HAL::convertToADC >>");
    #endif

      // we have to make sure, that our measured value do
      // not exceed the maximum limit.
      // and if it does, we have no choice but to return 0.00
      if(Val > m_conf.Vmax or Val < m_conf.Vmin)
      {
          return 0.00;
      }

      return  Val / bitConverter;


    #ifdef __DEBUG__
    LOG_PRINT_INFO(LOG_TAG, "<< NS_Current_Sensor::HAL::convertToADC << ");
    #endif

}




/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void stm32_hal_adc_init(void)
{
#ifdef __STM32__
  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 16;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_11;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = 2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 4;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 6;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 7;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 8;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 9;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 10;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 11;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 12;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 13;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 14;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 15;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Rank = 16;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */
#endif
}
