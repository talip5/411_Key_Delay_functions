/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
//static void MX_GPIO_Init(void);
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

	int32_t n = 2+2;

	int32_t sum = n+5;

	int8_t number=1;

	 char myText[] = "Hello";
	 char Key='K';

	 bool counter=true;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
 // SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  //MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  	  clock_D();
  	  led_init();
  	//turn_on(); // çalışıyor
  /* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */

	while (number) {
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
		//if (sum == 9)
			if (Key=='K' ) {
		 turn_on();
		 HAL_Delay(1500);
		 }

		 //turn_on();
		 //delay1(3);

		 //HAL_Delay(1500);
		number = 0;
	}

	turn_off();
	/* USER CODE END 3 */
	//turn_on();
}



/* USER CODE BEGIN 4 */

void delay1(int t2)
{
	int t1=1000000;
	int top= t1*t2;
	for(int i=0; i<top; i++)
			 {

			 }
}

 void turn_on()
{
    //LD6_Pin
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOD, LD6_Pin, GPIO_PIN_SET);

}

 void turn_off()
{
    //LD6_Pin
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOD, LD6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, LD4_Pin, GPIO_PIN_SET);
}

void clock_D()
{
	__HAL_RCC_GPIOD_CLK_ENABLE();
}

void led_init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct = {0};
	  /*Configure GPIO pins : LD4_Pin LD3_Pin LD5_Pin LD6_Pin
	                             Audio_RST_Pin */
	    GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin
	                            |Audio_RST_Pin;
	    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}
/* USER CODE END 4 */
