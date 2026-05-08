/*
 * tilt.h
 *
 *  Created on: May 8, 2026
 *      Author: szuni
 */

#ifndef INC_TILT_H_
#define INC_TILT_H_

#include "main.h"

// Function of calculating raw data into angle
uint8_t TiltCalculateServoX(float ax, float ay, float az);
uint8_t TiltCalculateServoY(float ax, float ay, float az);

#endif /* INC_TILT_H_ */
