/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */


/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


//=====================================================LED1


GPIO_InitTypeDef LED_1_IN = {
		.Pin = LED_1_Pin,
		.Mode = GPIO_MODE_INPUT,
		.Pull = GPIO_NOPULL
};

GPIO_InitTypeDef LED_1_OUT = {
		.Pin = LED_1_Pin,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_NOPULL,
		.Speed = GPIO_SPEED_FREQ_LOW
};

// ===================================================LED2

GPIO_InitTypeDef LED_2_IN = {
		.Pin = LED_2_Pin,
		.Mode = GPIO_MODE_INPUT,
		.Pull = GPIO_NOPULL
};

GPIO_InitTypeDef LED_2_OUT = {
		.Pin = LED_2_Pin,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_NOPULL,
		.Speed = GPIO_SPEED_FREQ_LOW
};
//==================================================LED_3

GPIO_InitTypeDef LED_3_IN = {
		.Pin = LED_3_Pin,
		.Mode = GPIO_MODE_INPUT,
		.Pull = GPIO_NOPULL
};

GPIO_InitTypeDef LED_3_OUT = {
		.Pin = LED_3_Pin,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_NOPULL,
		.Speed = GPIO_SPEED_FREQ_LOW
};

//====================================================LED_4

GPIO_InitTypeDef LED_4_IN = {
		.Pin = LED_4_Pin,
		.Mode = GPIO_MODE_INPUT,
		.Pull = GPIO_NOPULL
};

GPIO_InitTypeDef LED_4_OUT = {
		.Pin = LED_4_Pin,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_NOPULL,
		.Speed = GPIO_SPEED_FREQ_LOW
};

//===========================================================================FUNCTION





void set_led(uint8_t led, char *RGB, uint8_t time_s){


	switch(led){

		case 1:
			HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_OUT);
			HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);

			switch(RGB[0]){
				case 'R':
					HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_OUT);
					HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);
					HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);
					HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);

					break;

				case 'G':
					HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
					HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_OUT);
					HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

					HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
					break;

				case 'B':
					HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
					HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);
					HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_OUT);

					HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
					break;

				default:
					return;
				}

			break;

		case 2:
			HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_OUT);
			HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);

			switch(RGB[0]){
				case 'R':
					HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
					HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_OUT);
					HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

					HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
					break;

				case 'G':
					HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
					HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);
					HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_OUT);

					HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
					break;

				case 'B':
					HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_OUT);
					HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);
					HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

					HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
					break;

				default:
					return;
				}

			break;

		case 3:
			HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_OUT);
			HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);

			switch(RGB[0]){
				case 'R':
					HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
					HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
					HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_OUT);

					HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
					break;

				case 'G':
					HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_OUT);
					HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
					HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

					HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
					break;

				case 'B':
					HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
					HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_OUT);
					HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

					HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
					break;

				default:
					return;
				}

			break;

		case 4:
			HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_OUT);
			HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET);

			switch(RGB[0]){
				case 'R':
					HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_OUT);
					HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
					HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);

					HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
					break;

				case 'G':
					HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
					HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_OUT);
					HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);

					HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
					break;

				case 'B':
					HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
					HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
					HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_OUT);

					HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
					break;

				default:
					return;
				}

			break;

	default:
		return;
	}

	HAL_Delay(time_s*100);

}







/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //================================= LED 1 =============================================

	  	  	  HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_OUT);
	  	  	  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);

	  		//========================================================================== czerwona
	  		  HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_OUT);
	  		  HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);
	  		  HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

	  		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);

	  		  //========================================================================== zielona
	  		  HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
	  		  HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_OUT);
	  		  HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

	  		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);

	  		  //========================================================================== niebieska
	  		  HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
	  		  HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);
	  		  HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_OUT);

	  		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);


	  		//================================= LED 2 =============================================

	  		  HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_OUT);
	  		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);

	  		//========================================================================== czerwona
	  		  HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
	  		  HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_OUT);
	  		  HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

	  		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);

	  		  //========================================================================== zielona
	  		  HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
	  		  HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);
	  		  HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_OUT);

	  		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);

	  		  //========================================================================== niebieska
	  		  HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_OUT);
	  		  HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);
	  		  HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

	  		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);

	  		//================================= LED 3 =============================================

	  		  HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_OUT);
	  		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);

	  		//========================================================================== czerwona
	  		  HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
	  		  HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
	  		  HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_OUT);

	  		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);

	  		//========================================================================== zielona
	  		  HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_OUT);
	  		  HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
	  		  HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

	  		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);

	  		  //========================================================================== niebieska
	  		  HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
	  		  HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_OUT);
	  		  HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_IN);

	  		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);

	  		//================================= LED 4 =============================================

	  		  HAL_GPIO_Init(LED_4_GPIO_Port, &LED_4_OUT);
	  		  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET);

	  		//========================================================================== czerwona
	  		  HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_OUT);
	  		  HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
	  		  HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);

	  		  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);

	  		//========================================================================== zielona
	  		  HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
	  		  HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_OUT);
	  		  HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_IN);

	  		  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);

	  		  //========================================================================== niebieska
	  		  HAL_GPIO_Init(LED_1_GPIO_Port, &LED_1_IN);
	  		  HAL_GPIO_Init(LED_2_GPIO_Port, &LED_2_IN);
	  		  HAL_GPIO_Init(LED_3_GPIO_Port, &LED_3_OUT);

	  		  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);

	  		  HAL_Delay(1000);


	  	  char RGB[3] = {'R','G','B'};

	  	      for(int i = 1; i <= 4; i++){

	  	          for(uint8_t j = 0; j < 3; ++j) {
	  	        	  set_led(i, &RGB[j], 1);
	  	          }
	  	      }





	  /*
	  if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 0){
		  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		  HAL_Delay(1000);
		  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		  HAL_Delay(1000);
		  while(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 1);
	  }
	  */

	  /*
	  if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 0){
	  		  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	  		  HAL_Delay(5);
	  		  while(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 1);
	  	  }
	  */

	  /*
	  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);

	  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);



	  HAL_Delay(1000);	  HAL_Delay(1000);

	  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);


	  HAL_Delay(1000);


	  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);

	  HAL_Delay(1000);


	  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET);

	  HAL_Delay(1000);

	  */




    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
