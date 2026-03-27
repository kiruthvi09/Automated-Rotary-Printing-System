#include "interrupt_Handlers.h"
#include "Functions.h"
uint8_t insantStopFlag = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_13)
    {
        instantStopFlag = 1;
    }
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

    if (huart->Instance == USART3)
    {

        if(rx_data == "\n"){                //"\n" indicates end of data
        	rxBuffer[index] = '\0';
        	RxDataReceived = 1;
        	index = 0;

        }

        else
        	{
        	rxBuffer[index++]= rx_data;

        	}
    }
    HAL_UART_Receive_IT(&huart3, &rx_data, 1);
}
