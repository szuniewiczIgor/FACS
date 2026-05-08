/*
 * servo.h
 *
 *  Created on: Apr 18, 2026
 *      Author: szuniewiczIgor
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_
#include "main.h"

#define AXIS_X TIM_CHANNEL_1
#define AXIS_Y TIM_CHANNEL_3

void SetServoAngle(uint32_t axis, uint8_t angle);


#endif /* INC_SERVO_H_ */
