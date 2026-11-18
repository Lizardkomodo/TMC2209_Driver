/*
 * StepperMotorDriver.h
 *
 *  Created on: Sep 25, 2026
 *      Author: BVilla
 */

#ifndef INC_STEPPERMOTORDRIVER_H_
#define INC_STEPPERMOTORDRIVER_H_
#endif /* INC_STEPPERMOTORDRIVER_H_ */

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

#define STEPPER_HEADER 0xA0 //first byte to send in message, contains sync message
#define TMC2209_GCONF_ADDR 0x00 //first byte to send in message, contains sync message
#define TMC2209_GSTAT_ADDR 0x01
#define TMC2209_IFCNT_ADDR 0x02
#define TMC2209_NODECONF_ADDR 0x03
#define TMC2209_GSTAT_ADDR 0x01
#define TMC2209_GSTAT_ADDR 0x01



void INIT_Stepper_Motor();

void Enable_Stepper_Motor();

void Stepper_Step(uint8_t steps);

void Stepper_PWM_Test(uint8_t DutyCycle);
//void swuart_calcCRC(UCHAR* datagram, UCHAR datagramLength);

