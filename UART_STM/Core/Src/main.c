/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

uint8_t  RX1_Char[6]                  = {0,0,0,0,0,0};  // 0 0 0 0 0 0 0 0
uint8_t  RX_set_key_man[4]            = {0,0,0,0};  // 0 0 0 0


//---------[  COMMAND LIST    ]---------
uint8_t  cmd_check_key_connection[6]  = {1,0,0,0,1,0};  // 1 0 0 0 1 0 (evry command ending with '1' for stop receiving data, than changed by CRC function to necessary byte value}
uint8_t  cmd_get_key_number[6]        = {2,0,0,0,1,1};  // 2 0 0 0 1 2 
uint8_t  cmd_get_key_id[6]            = {3,0,0,0,1,2};  // 2 0 0 0 1 2 
uint8_t  cmd_key_confirmation[6]      = {4,0,0,0,1,3};  // 2 0 0 0 1 2 


//---------[  FLAGS    ]---------
uint8_t  command_number               = 0x00;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

//---------[ UART Data Reception Completion CallBackFunc. ]---------
void HAL_USART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    HAL_UART_Receive_IT(&huart2, RX1_Char, 6);
	  HAL_UART_Receive_IT(&huart2, RX_set_key_man, 4);

}

void HAL_USART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    HAL_UART_Transmit_IT(&huart2, RX1_Char, 8);
}

//---------[  Function for clearing received data  ]---------
void clear_recieved_data (uint8_t RX1_Char[])
{
        RX1_Char[0] = 0x00;
        RX1_Char[1] = 0x00;
        RX1_Char[2] = 0x00;
        RX1_Char[3] = 0x00;
        RX1_Char[4] = 0x00;
        RX1_Char[5] = 0x00;
}

//---------[  Function for searching command  ]---------
void finding_command (uint8_t RX1_Char[])
{
      if (RX1_Char[0] == cmd_check_key_connection[0])
        {
        command_number = 0x01;
        }
      else if (RX1_Char[0] == cmd_get_key_number[0])
        {
        command_number = 0x02;
        }
			else if (RX1_Char[0] == cmd_get_key_id[0])
        {
        command_number = 0x03;
        }
			else if (RX1_Char[0] == cmd_key_confirmation[0])
        {
        command_number = 0x04;
        }	
}

int main(void)
{
  uint8_t MSG_unknown_cmd[]              = "UNKNOWN COMMAND \r\n";
  uint8_t MSG_set_key_number[]           = "Please SET the KEY NUMBER: \r\n";

	
  uint8_t MSG_cmd_check_key_connection[8] = {1,0,0,0,0,0,1,0};
	uint8_t MSG_cmd_get_key_number[8]       = {2,0,0,0,0,0,1,1};
	uint8_t MSG_cmd_get_key_id[8]           = {3,0,0,0,0,0,1,2};
	uint8_t MSG_cmd_key_confirmation[8]     = {4,0,0,0,0,0,1,3};
 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  
  HAL_UART_Receive_IT(&huart2, RX1_Char, 6);
  
  while (1)
  {    

    finding_command(RX1_Char);
		
/*---------[  Command UKNOWN COMMAND ]---------    
    if (command_number == 0x99)
        {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
        HAL_UART_Transmit_IT(&huart2, MSG_unknown_cmd, sizeof(MSG_unknown_cmd));
        HAL_UART_Receive_IT(&huart2, RX1_Char, 6);

        clear_recieved_data(RX1_Char);
          
        command_number = 0x00;
        }	
*/
		
//---------[  Command cmd_check_key_connection ]---------    
    if (command_number == 0x01)
        {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
        HAL_UART_Transmit_IT(&huart2, MSG_cmd_check_key_connection, sizeof(MSG_cmd_check_key_connection));
        HAL_UART_Receive_IT(&huart2, RX1_Char, 6);

        clear_recieved_data(RX1_Char);
          
        command_number = 0x00;
        }
				
//---------[  Command cmd_check_key_connection ]---------    				
    if ( (command_number == 0x02)&& (RX1_Char[1] == 0) && (RX1_Char[2] == 0) && (RX1_Char[3] == 0) && (RX1_Char[4] == 1))
        {					
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
        HAL_UART_Transmit_IT(&huart2, MSG_cmd_get_key_number, sizeof(MSG_cmd_get_key_number));
        HAL_UART_Receive_IT(&huart2, RX1_Char, 6);

        clear_recieved_data(RX1_Char);
          
        command_number = 0x00;
        }
	
    if ((command_number == 0x02) && (RX1_Char[1] == 1) && (RX1_Char[2] == 1) && (RX1_Char[3] == 1) && (RX1_Char[4] == 1))	
			  {
			   HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
				 HAL_UART_Transmit_IT(&huart2, MSG_set_key_number, sizeof(MSG_set_key_number));
					
				 HAL_UART_Receive_IT(&huart2, RX_set_key_man, 4);
					
				 MSG_cmd_get_key_number[1] = RX_set_key_man[0];
         MSG_cmd_get_key_number[2] = RX_set_key_man[1];
         MSG_cmd_get_key_number[3] = RX_set_key_man[2];
         MSG_cmd_get_key_number[4] = RX_set_key_man[3];
				
         HAL_UART_Transmit_IT(&huart2, MSG_cmd_get_key_number, sizeof(MSG_cmd_get_key_number));
				 HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	
				 HAL_UART_Receive_IT(&huart2, RX1_Char, 6);
				 clear_recieved_data(RX1_Char);
          
         command_number = 0x00;	

			 }
									

				
//---------[  Command cmd_get_key_id ]---------    				
    if (command_number == 0x03)
        {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
        HAL_UART_Transmit_IT(&huart2, MSG_cmd_get_key_id, sizeof(MSG_cmd_get_key_id));
        HAL_UART_Receive_IT(&huart2, RX1_Char, 6);

        clear_recieved_data(RX1_Char);
          
        command_number = 0x00;
        }
				
//---------[  Command cmd_get_key_id ]---------    				
    if (command_number == 0x04)
        {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
        HAL_UART_Transmit_IT(&huart2, MSG_cmd_key_confirmation, sizeof(MSG_cmd_key_confirmation));
        HAL_UART_Receive_IT(&huart2, RX1_Char, 6);

        clear_recieved_data(RX1_Char);
          
        command_number = 0x00;
        }					
				
     HAL_Delay(100);
  }
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{
	 __HAL_RCC_USART2_CLK_ENABLE();

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LD4_Pin|LD3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LD4_Pin LD3_Pin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

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
