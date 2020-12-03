/**
  ******************************************************************************
  * File Name          : WWDG.c
  * Description        : This file provides code for the configuration
  *                      of the WWDG instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "wwdg.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

WWDG_HandleTypeDef hwwdg;

/* WWDG init function */
void MX_WWDG_Init(void)
{

  hwwdg.Instance = WWDG;
  hwwdg.Init.Prescaler = WWDG_PRESCALER_8;
  hwwdg.Init.Window = 0x5F;
  hwwdg.Init.Counter = 0x7F;
  hwwdg.Init.EWIMode = WWDG_EWI_ENABLE;
  if (HAL_WWDG_Init(&hwwdg) != HAL_OK)
  {
    Error_Handler();
  }
}

void HAL_WWDG_MspInit(WWDG_HandleTypeDef* wwdgHandle)
{

  if(wwdgHandle->Instance==WWDG)
  {
  /* USER CODE BEGIN WWDG_MspInit 0 */

  /* USER CODE END WWDG_MspInit 0 */
    /* WWDG clock enable */
    __HAL_RCC_WWDG_CLK_ENABLE();
  /* USER CODE BEGIN WWDG_MspInit 1 */
  HAL_NVIC_SetPriority(WWDG_IRQn,2,3);   //抢占优先级2，子优先级为3
  HAL_NVIC_EnableIRQ(WWDG_IRQn);          //使能窗口看门狗中断
  /* USER CODE END WWDG_MspInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void WWDG_IRQHandler(void)
{
    HAL_WWDG_IRQHandler(&hwwdg);
}

void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef* HWWDG)
{
    HAL_WWDG_Refresh(&hwwdg);
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
