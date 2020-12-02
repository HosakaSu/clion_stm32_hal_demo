/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __key_H
#define __key_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#define KEY0        HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4)  //KEY0按键PE4
#define KEY1        HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3)  //KEY1按键PE3
#define KEY2        HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2) 	//KEY2按键PE2
#define WK_UP       HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)  //WKUP按键PA0

#define KEY0_PRES 	1
#define KEY1_PRES	2
#define KEY2_PRES	3
#define WKUP_PRES   4
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/* USER CODE BEGIN Prototypes */
uint8_t KEY_Scan(uint8_t mode);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/