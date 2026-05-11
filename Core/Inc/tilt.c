/*
 * tilt.c
 *
 *  Created on: May 8, 2026
 *      Author: szuni
 */
#include "tilt.h"
#include <math.h>

static float filtered_x_angle = 0.0f;
static float filtered_y_angle = 0.0f;
static const float alpha = 0.25f; // Low-pass filter factor. Less -> servo reacts slower, More -> servo reacts faster

uint8_t TiltCalculateServoX(float ax, float ay, float az, float offset){

	// Calculating raw angle [degree] form -90 to 90
	float raw_x_angle = (atan2(ax, sqrt(ay*ay + az*az)) * 180.0f / M_PI) - offset;
	// Filtering noise by low pass filter
	filtered_x_angle = (alpha * raw_x_angle) + ((1.0f - alpha) * filtered_x_angle);
	// Rescaling tilt degree to servo degree
	float servo_x_angle = 90.0f + filtered_x_angle;

	// Servo overshoot protection
	if (servo_x_angle < 0.0f) {
			servo_x_angle = 0.0f;
	}
	if (servo_x_angle > 180.0f){
			servo_x_angle = 180.0f;
	}

	// Return 8 bit integer
	return (uint8_t)servo_x_angle;
}

uint8_t TiltCalculateServoY(float ax, float ay, float az, float offset){
	float raw_y_angle = (atan2(ay, sqrt((ax*ax + az*az))) * 180.0f / M_PI) - offset;
	filtered_y_angle = (alpha * raw_y_angle) + ((1.0f - alpha) * filtered_y_angle);
	float servo_y_angle = 90.0f + filtered_y_angle;
	if (servo_y_angle < 0.0f) {
			servo_y_angle = 0.0f;
		}
	if (servo_y_angle > 180.0f){
			servo_y_angle = 180.0f;
		}

		// Return 8 bit integer
		return (uint8_t)servo_y_angle;
}

