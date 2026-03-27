#ifndef __INTERRUPT_HANDLERS_H
#define __INTERRUPT_HANDLERS_H

extern uint8_t instantStopFlag;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);//UART Callback
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin); //EXT Interrupt Callback


#endif
