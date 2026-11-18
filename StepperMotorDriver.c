/*
 * StepperMotorDriver.c
 *
 *  Created on: Sep 25, 2026
 *      Author: BVilla
 */
#include "StepperMotorDriver.h"
#include "stm32f1xx_hal_gpio.h"
#include "stdio.h"
extern TIM_HandleTypeDef htim1;
/*Stepper Motor Message Layout
 * Bytes:
 * 1 - Header: contains synch nibble and 4 empty bits
 * 2 - 8 bit node address
 * 3
 * 4
 * 5
 * 6
 * 7
 * 8 - CRC
 */
void INIT_Stepper_Motor(){
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET); //enable pin, motor turned off when pulled high
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, RESET); //Direction
	 // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET); //Step
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, RESET); //MS2
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, RESET); //MS1
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET); //Power Down Saving, active when Low
	  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);

}

void Stepper_PWM_Test(uint8_t DutyCycle){
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, RESET); //Direction
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET); //Enable Motor
	TIM1->CCR2 = DutyCycle; //Writes the PWM duty cycle
	HAL_Delay(5000);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET); //Disable Motor

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, SET); //Direction
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET); //Enable Motor
	TIM1->CCR2 = DutyCycle; //Writes the PWM duty cycle
	HAL_Delay(5000);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET); //Disable Motor
}

void Stepper_Step(uint8_t steps){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET); //Enable Motor
for (int var = 0; var < steps; ++var) {

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET); //Step
	HAL_Delay(1);
}
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET); //Disable Motor

}
void Stepper_Motor_UART_Test(){


}

/*void swuart_calcCRC(UCHAR* datagram, UCHAR datagramLength)
{
 int i,j;
 UCHAR* crc = datagram + (datagramLength-1); // CRC located in last byte of message
 UCHAR currentByte;
 *crc = 0;
 for (i=0; i<(datagramLength-1); i++) { // Execute for all bytes of a message
 currentByte = datagram[i]; // Retrieve a byte to be sent from Array
 for (j=0; j<8; j++) {
 if ((*crc >> 7) ^ (currentByte&0x01)) // update CRC based result of XOR operation
 {
 *crc = (*crc << 1) ^ 0x07;
 }
 else
 {
 *crc = (*crc << 1);
 }
 currentByte = currentByte >> 1;
 } // for CRC bit
 } // for message byte
}
*/
