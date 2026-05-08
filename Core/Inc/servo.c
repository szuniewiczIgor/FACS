/*
 * servo.c
 * SERVO: MG90S
 *  Created on: Apr 18, 2026
 *      Author: szuniewiczIgor
 */
#include "servo.h"
extern TIM_HandleTypeDef htim4; //allows use htim4

void SetServoAngle(uint32_t axis, uint8_t angle){
	if (angle > 180){
		angle = 180;
	}
	uint16_t min_pulse = 575; //0 degree
	uint16_t max_pulse = 2500; // 180 degree

	uint16_t pulse = ((uint32_t)angle * (max_pulse - min_pulse) / 180) + min_pulse; //formula for pulse. angle is variable

	__HAL_TIM_SET_COMPARE(&htim4, axis, pulse);
}
