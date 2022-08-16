/*
 * PS3.cpp
 *
 *  Created on: Aug 2, 2022
 *      Author: Hardik1306
 */
#include"PS3.h"
PS3::PS3(){}
void PS3::init(UART_HandleTypeDef *huart, char macAddress[17],uint8_t *analogDataToRecieve){
 uint8_t dataToSend[35];
 this->huart = huart;
 for(uint8_t i = 0;i <17;i++){
	 dataToSend[i] = macAddress[i];
 }
datalength = 17;

 for(uint8_t i = 0;i < 17;i++){
  	 if(analogDataToRecieve[i] == 0){
  		 break;
  	 }
  	 else{
      datalength++;
	 dataToSend[i + 17] = analogDataToRecieve[i];
	 this->analogDataToRecieve[i] = analogDataToRecieve[i];
  	 }
 }
dataToSend[datalength] = 0b00110000;

 HAL_UART_Transmit(huart, dataToSend, datalength + 1, HAL_MAX_DELAY);
// HAL_UART_Receive_IT (huart, rxBuffer, 19);

}
void PS3::update(){
	digital.up = rxBuffer[0] & 1;
	digital.right = rxBuffer[0]>>1 & 1;
	digital.down = rxBuffer[0]>>2 & 1;
	digital.left = rxBuffer[0]>>3 & 1;
	digital.select = rxBuffer[0]>>4 & 1;
	digital.start = rxBuffer[0]>>5 & 1;
	digital.triangle = rxBuffer[1] & 1;
	digital.circle = rxBuffer[1]>>2 & 1;
	digital.cross = rxBuffer[1]>>3 & 1;
	digital.square = rxBuffer[1]>>4 & 1;
	digital.ps = rxBuffer[1]>>5 & 1;
	digital.l1 = rxBuffer[2] & 1;
	digital.l2 = rxBuffer[2]>>1 & 1;
	digital.l3 = rxBuffer[2]>>2 & 1;
	digital.r1 = rxBuffer[2]>>3 & 1;
	digital.r2 = rxBuffer[2]>>4 & 1;
	digital.r3 = rxBuffer[2]>>5 & 1;

	for(uint8_t i = 0;i < (datalength - 17);i++){
	switch (analogDataToRecieve[i])
	{
	    case UP:
	    	analog.up = rxBuffer[i];
	    	break;
	    case RIGHT:
	    	analog.right = rxBuffer[i];
	    	break;
	    case DOWN:
	    	analog.down = rxBuffer[i];
	    	break;
	    case LEFT:
	    	analog.left = rxBuffer[i];
	    	break;
	    case TRIANGLE:
	    	analog.triangle = rxBuffer[i];
	    	break;
	    case CIRCLE:
	    	analog.circle = rxBuffer[i];
	    	break;
	    case CROSS:
	    	analog.cross = rxBuffer[i];
	    	break;
	    case SQUARE:
	    	analog.square = rxBuffer[i];
	    	break;
	    case L1:
	    	analog.l1 = rxBuffer[i];
	    	break;
	    case L2:
	    	analog.l2 = rxBuffer[i];
	    	break;
	    case R1:
	    	analog.r1 = rxBuffer[i];
	    	break;
	    case R2:
	    	analog.r2 = rxBuffer[i];
	    	break;
	    case LX:
	    	analog.lx = rxBuffer[i];
	    	break;
	    case LY:
	    	analog.ly = rxBuffer[i];
	    	break;
	    case RX:
	    	analog.rx = rxBuffer[i];
	    	break;
	    case RY:
	    	analog.ry = rxBuffer[i];
	    	break;


	}
	}
	HAL_UART_Receive_IT (huart, rxBuffer, 19);
}




