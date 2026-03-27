#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H


extern uint8_t rx_data;
extern char rxBuffer[rxBufferLen];
extern uint8_t RxDataReceived;
extern uint8_t dataProcessed;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart1;

void startRotor1(int delay1);
void startRotor2(int delay2);
void UART_ReceiveDelayData(char *RxBuf);
void conveyerRollersOn();
void conveyerRollersOff();
void RotorsOff();
void ManualKillSwitch();
void processUartData();
void printingstart();


#endif
