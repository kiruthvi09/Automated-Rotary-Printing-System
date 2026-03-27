#include "Functions.h"
#include "main.h"
#include <stdio.h>


#define rxBufferLen 100
#define colour_length 15
#define RollerSpeed  50
#define ConveyorSpeed 50

uint8_t rx_data;
char rxBuffer[rxBufferLen]={};
uint8_t RxDataReceived =0;
uint8_t delay1 = 0;
uint8_t delay2 = 0;
char *ptr;
char colour1[colour_length]={};
char colour2[colour_length]={};
uint8_t dataProcessed =0;
char DebugBuf[500]={};

void startRotor1(int delay1);
void startRotor2(int delay2);
void UART_ReceiveDelayData(char *RxBuf);
void conveyerRollersOn();
void conveyerRollersOff();
void RotorsOff();
void ManualKillSwitch();
void processUartData(char *dataBuffer);
void printingstart();
void DyePumpsOn();

void processUartData(uint8_t *dataBuffer){


	 ptr = strstr(buffer, "colour - ");
	    if (ptr != NULL)
	    {
	        ptr += strlen("colour - ");  // Move to colour name

	        sscanf(ptr, "%[^:]", colour1); // Read until ':'

	        ptr = strstr(ptr, ":");
	        if (ptr != NULL)
	            delay1 = atoi(ptr + 1);
	    }

	    // -------- Second Colour --------
	    ptr = strstr(ptr + 1, "colour - ");
	    if (ptr != NULL)
	    {
	        ptr += strlen("colour - ");

	        sscanf(ptr, "%[^:]", colour2);

	        ptr = strstr(ptr, ":");
	        if (ptr != NULL)
	            delay2 = atoi(ptr + 1);
	    }
      dataProcessed = 1;
      sendDebugMessage("The UART Data Processed Successfully");
      snprintf(DebugBuf,sizeof(DebugBuf),"The colour of Roller1 is %s and the delay of Roller1 is %d (ms)",colour1,delay1);
      sendDebugMessage(DebugBuf);
      snprintf(DebugBuf,sizeof(DebugBuf),"The colour of Roller2 is %s and the delay of Roller2 is %d (ms)",colour2,delay2);
      sendDebugMessage(DebugBuf);

	}

void printingStart(){
	conveyorRollerOn();
	dye_PumpsOn();
	startRotor1(delay1);         // start all rollers to print.
    startRotor2(delay2);

    sendDebugMessage("The Rotary Printing Started Successfully");

}
void startRotor1(int delay1){
	HAL_Delay(delay1); //Start a roller after the Received Delay
	HAL_GPIO_WritePin(IN1_Roll1_GPIO_Port, IN1_Roll1_Pin, 1);
	HAL_GPIO_WritePin(IN2_Roll1_GPIO_Port,IN2_Roll1_Pin,0);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, RollerSpeed);  //Speed at slow
	snprintf(DebugBuf,sizeof(DebugBuf),"The roller2 is %s colour and started at %d (ms) delay",colour1,delay1);
	sendDebugMessage(DebugBuf);
}

void startRotor2(int delay2){
	HAL_Delay(delay2); //Start a roller after the Received Delay
	HAL_GPIO_WritePin(IN1_Roll2_GPIO_Port, IN1_Roll2_Pin, 1);
	HAL_GPIO_WritePin(IN2_Roll2_GPIO_Port,IN2_Roll2_Pin,0);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, RollerSpeed);  //Speed at slow
	snprintf(DebugBuf,sizeof(DebugBuf),"The roller2 is %s colour and started at %d (ms) delay",colour2,delay2);
	sendDebugMessage(DebugBuf);
}

void conveyerRollersOn(){
	//conveyor 1
	HAL_GPIO_WritePin(IN1_Conv1_GPIO_Port,IN1_Conv1_Pin,1);
	HAL_GPIO_WritePin(IN2_Conv1_GPIO_Port,IN2_Conv1_Pin,0);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, ConveyorSpeed);  // speed at slow


	//conveyor 2
	HAL_GPIO_WritePin(IN1_Conv2_GPIO_Port,IN1_Conv2_Pin,1);
	HAL_GPIO_WritePin(IN1_Conv2_GPIO_Port,IN2_Conv2_Pin,0);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, ConveyorSpeed);  // speed at slow


	//conveyor 3
	HAL_GPIO_WritePin(IN1_Conv3_GPIO_Port,IN1_Conv3_Pin,1);
	HAL_GPIO_WritePin(IN2_Conv3_GPIO_Port,IN2_Conv3_Pin,0);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, ConveyorSpeed);  // speed at slow


	//conveyor 4
	HAL_GPIO_WritePin(IN1_Conv4_GPIO_Port,IN1_Conv4_Pin,1);
	HAL_GPIO_WritePin(IN2_Conv4_GPIO_Port,IN2_Conv4_Pin,0);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, ConveyorSpeed);  // speed at slow

	sendDebugMessage("Conveyors Running at set speed");

}

void conveyorRollersOff()
{
	//Stop all Conveyors

	//Conveyor 1 off
HAL_GPIO_WritePin(IN1_Conv1_GPIO_Port,IN1_Conv1_Pin,0);
HAL_GPIO_WritePin(IN2_Conv1_GPIO_Port,IN2_Conv1_Pin,0);
__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);


  //Conveyor 2 off
HAL_GPIO_WritePin(IN1_Conv2_GPIO_Port,IN1_Conv2_Pin,0);
HAL_GPIO_WritePin(IN1_Conv2_GPIO_Port,IN2_Conv2_Pin,0);
__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);


   //Conveyor 3 off
HAL_GPIO_WritePin(IN1_Conv3_GPIO_Port,IN1_Conv3_Pin,0);
HAL_GPIO_WritePin(IN2_Conv3_GPIO_Port,IN2_Conv3_Pin,0);
__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);


   //Conveyor 4 off
HAL_GPIO_WritePin(IN1_Conv4_GPIO_Port,IN1_Conv4_Pin,0);
HAL_GPIO_WritePin(IN2_Conv4_GPIO_Port,IN2_Conv4_Pin,0);
__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 0);

sendDebugMessage("Conveyers Turned Off");

}


 void RotorsOff(){
	 //Roller 1  off
	 HAL_GPIO_WritePin(IN1_Roll1_GPIO_Port,IN1_Roll1_Pin,0);
	 HAL_GPIO_WritePin(IN2_ROll1_GPIO_Port,IN2_Roll1_Pin,0);
	 __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);

	 //Roller2 off
	 HAL_GPIO_WritePin(IN1_Roll2_GPIO_Port,IN1_Roll2_Pin,0);
	 HAL_GPIO_WritePin(IN2_ROll2_GPIO_Port,IN2_Roll2_Pin,0);
	 __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
	 sendDebugMessage("Rotors Turned Off");

 }
void dye_PumpsOn(){
	//DyePump1 On
	HAL_GPIO_WritePin(DyePump1_GPIO_Port,DyePump1_Pin,1);
	HAL_GPIO_WritePin(DyePump2_GPIO_Port,DyePump2_Pin,1);
	sendDebugMessage("Dye Fill Started");
	HAL_Delay(1200);
	HAL_GPIO_WritePin(DyePump1_GPIO_Port,DyePump1_Pin,0);
    HAL_GPIO_WritePin(DyePump2_GPIO_Port,DyePump2_Pin,0);
    sendDebugMessage("Dye Fill Stopped");
}

 void ManualKillSwitch(){
	 conveyerRollersOff();
	 RotorsOff();
	 sendDebugMessage("The Printing Stopped using Manual Stop");
 }

 void sendDebugMessage(char *dataString){

HAL_UART_Transmit(&huart1,&dataString,sizeof(dataString),HAL_MAX_DELAY);
 }
