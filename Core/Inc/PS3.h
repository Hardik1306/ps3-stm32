/*
 * PS3.h
 *
 *  Created on: Aug 2, 2022
 *      Author: hardik1306
 */

#ifndef INC_PS3_H_
#define INC_PS3_H_
#include"stm32f4xx.h"
#include"stm32f4xx_hal_uart.h"

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
#define TRIANGLE 5
#define CIRCLE 6
#define CROSS 7
#define SQUARE 8
#define L1 9
#define R1 10
#define L2 11
#define R2 12
#define LX 13
#define LY 14
#define RX 15
#define RY 16



class PS3 {


public:
	struct{
		uint8_t up = 0;
		uint8_t right = 0;
		uint8_t down = 0;
		uint8_t left = 0;
		uint8_t triangle = 0;
		uint8_t circle = 0;
		uint8_t cross = 0;
		uint8_t square = 0;
		uint8_t l1 = 0;
		uint8_t l2 = 0;
		uint8_t l3 = 0;
		uint8_t r1 = 0;
		uint8_t r2 = 0;
		uint8_t r3 = 0;
		uint8_t select = 0;
		uint8_t start = 0;
		uint8_t ps = 0;
	}digital;
	struct{
		uint8_t up = 0;
		uint8_t right = 0;
		uint8_t down = 0;
		uint8_t left = 0;
		uint8_t triangle = 0;
		uint8_t circle = 0;
		uint8_t cross = 0;
		uint8_t square = 0;
		uint8_t l1 = 0;
		uint8_t l2 = 0;
		uint8_t lx = 0;
		uint8_t ly = 0;
		uint8_t r1 = 0;
		uint8_t r2 = 0;
		uint8_t rx = 0;
		uint8_t ry = 0;
	}analog;

    uint8_t analogDataToRecieve[16]= {0};
    uint8_t datalength = 0;
    uint8_t rxBuffer[20] = {0};
    UART_HandleTypeDef *huart;
    PS3();
	void init(UART_HandleTypeDef *huart, char macAddress[],uint8_t *analogDataToRecieve);
	void update();


};



#endif /* INC_PS3_H_ */
