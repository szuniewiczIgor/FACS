/*
 * sensor.h
 *
 *  Created on: May 7, 2026
 *      Author: szuni
 */

#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

#include "main.h"

#define ACCEL_ADDR    0x32
#define CTRL_REG1_A   0x20
#define CTRL_REG4_A   0x23
#define OUT_X_L_A     0x28

uint8_t SensorInit(void);
uint8_t SensorReadAccel(int16_t *x, int16_t *y, int16_t *z);

#endif /* INC_SENSOR_H_ */




