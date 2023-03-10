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
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "stdio.h"

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

volatile int number_display = 10;

volatile uint8_t counter_timer = 0;


volatile int lastDebounceTime1 = 0;
volatile int lastDebounceTime2 = 0;
const int debounceDelay = 250;

volatile uint8_t state1 = 0;
volatile uint8_t state2 = 0;

volatile int16_t liczba1 = 0;
volatile int16_t liczba2 = 0;
volatile int16_t liczba3 = 0;
volatile int16_t liczba4 = 0;


volatile uint8_t tx_buf[5];

volatile uint8_t rx_buf[5];

volatile uint16_t tx_buf_length;


const uint8_t Set_number[] = {
							   0b10000001,	/* 0 */
							   0b11100111,	/* 1 */
							   0b10101000,	/* 2 */
							   0b10100100,	/* 3 */
							   0b11000110,	/* 4 */
							   0b10010100,	/* 5 */
							   0b10010000,	/* 6 */
							   0b10100111,	/* 7 */
							   0b10000000,	/* 8 */
							   0b10000100,	/* 9 */
							   0b11111111,	/* NULL */
							   0b00000000	/* FULL */
											};


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */



void Set_Sign(uint8_t count, uint8_t display_number);
void Display(int number_display, uint8_t counter_timer);



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
  MX_TIM9_Init();
  MX_ADC1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  //============================================================================
  HAL_ADC_Start_IT(&hadc1);
  HAL_TIM_Base_Start_IT(&htim9);
  HAL_TIM_Base_Start_IT(&htim3);

  //tx_buf_length = snprintf(tx_buf, sizeof(tx_buf), " Tekst  \n");
  //HAL_UART_Transmit_IT(&huart2, tx_buf, tx_buf_length);




  HAL_UART_Receive_IT(&huart2, rx_buf, 5);






  number_display = 0;
  //============================================================================

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  HAL_Delay(100);
	  //HAL_ADC_Start_IT(&hadc1);
	  //number_display = HAL_ADC_GetValue(&hadc1);

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
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */



// ==============================================================================================================================//



/*
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){

	static uint16_t cnt;
	cnt ++;
	tx_buf_length = snprintf(tx_buf, sizeof(tx_buf), " Tekst 3 counter = %d \n", cnt);
	HAL_UART_Transmit_IT(&huart2, tx_buf, tx_buf_length);

}
*/


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	memcpy(tx_buf, rx_buf, 5);

	HAL_UART_Transmit_IT(&huart2, tx_buf, 5);

	HAL_UART_Receive_IT(&huart2, rx_buf, 5);

}



// ==============================================================================================================================//














void Set_Sign(uint8_t count, uint8_t display_number){
	GPIOC -> ODR |= ~(0x0F << 8); // clear all display
	//set displayHAL_ADC_ConvCpltCallback
	GPIOC -> ODR |= (0x0F << 8);
	GPIOC -> ODR &= ((0x0F ^ (1 << (display_number -1))) << 8);
	//print sign
	GPIOC -> ODR |= (0xFF << 0);
	GPIOC -> ODR &= (~(Set_number[count])<<0);
}


void Display(int number_display, uint8_t counter_timer){
	// Devide to units count to display

	//ONLY FOR COUNT type INT FROM RANGE --- [0-9999]
	if(number_display >= 0 && number_display <= 9999){
		uint8_t sign = 10;

			//data to divide example: number_display = 1234, a = 1, b = 2, c = 3, d = 4
			uint8_t a = 10;
			uint8_t b = 10;
			uint8_t c = 10;
			uint8_t d = 10; // 10 is clear display

			//Divide:
			a = number_display / 1000;
			number_display = number_display % 1000;

			b = number_display / 100;
			number_display = number_display % 100;

			c = number_display / 10;
			number_display = number_display % 10;

			d = number_display;

			if(a == 0){
				a = 10;
				if(b == 0){
					b = 10;
					if(c == 0){
						c = 10;
						if(d == 0){
							d = 10;
						}
					}
				}
			}
			// Display is [4, 3, 2, 1] 4 - is oldest
			if(counter_timer == 1){
				sign = d;
				Set_Sign(sign, counter_timer);
			}
			if(counter_timer == 2){
				sign = c;
				Set_Sign(sign, counter_timer);
			}
			if(counter_timer == 3){
				sign = b;
				Set_Sign(sign, counter_timer);
			}
			if(counter_timer == 4){
				sign = a;
				Set_Sign(sign, counter_timer);
			}
	}
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	switch( GPIO_Pin ){

		case Button2_Pin:
			state1 = 1;
			lastDebounceTime1 = HAL_GetTick();
			break;

		case Button1_Pin:
			state2 = 1;
			lastDebounceTime2 = HAL_GetTick();
			break;

		default:
			break;
		}
}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM9){

		Display(number_display,counter_timer);

		if(number_display < 0) number_display = 0;
		if(number_display > 9999) number_display = 9999;

		counter_timer++;
		if(counter_timer > 4){
			counter_timer = 1;
		}
	}

}

/*
	if(htim->Instance == TIM9){
		HAL_ADC_Start_IT(&hadc1);
		number_display = HAL_ADC_GetValue(&hadc1);
	}*/

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{

	liczba1  = HAL_ADC_GetValue(&hadc1);
	liczba2 =  liczba1;
	liczba3 = liczba2;
	liczba4 = liczba3;

	number_display = (liczba1 + liczba2 +liczba3 +liczba4) / 4;
	number_display = number_display / 10;
	//HAL_ADC_Start_IT(&hadc1);
}


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
