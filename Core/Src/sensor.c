/*
 * sensor.c
 *
 *  Created on: May 7, 2026
 *      Author: szuni
 */

#include "sensor.h"

extern I2C_HandleTypeDef hi2c1;

uint8_t SensorInit(void){

    // 0x47 = 0100 0111 (50Hz, Normal Mode, on axis X, Y, Z)
    uint8_t init_data = 0x47;
    HAL_StatusTypeDef status = HAL_I2C_Mem_Write(&hi2c1, ACCEL_ADDR, CTRL_REG1_A, I2C_MEMADD_SIZE_8BIT, &init_data, 1, 100);

    if (status != HAL_OK) // Check write on 1st register
    	return 1;

    // 0x88 = 1000 1000 (BDU = 1, HR = 1)
    uint8_t ctrl4_data = 0x88;
    status = HAL_I2C_Mem_Write(&hi2c1, ACCEL_ADDR, CTRL_REG4_A, I2C_MEMADD_SIZE_8BIT, &ctrl4_data, 1, 100);

    if (status != HAL_OK) // Check write on 2nd register
    	return 1;

    return 0;
}

uint8_t SensorReadAccel(int16_t *x, int16_t *y, int16_t *z){
    uint8_t data[6] = {0};

    // OUT_X_L_A | 0x80
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&hi2c1, ACCEL_ADDR, (OUT_X_L_A | 0x80), I2C_MEMADD_SIZE_8BIT, data, 6, 100);

    if (status == HAL_OK)
    {
        // Komunikacja poprawna, składamy dane
        // Wyniki są wyrównane do lewej, więc po złożeniu przesuwamy je w prawo o 4 bity
        *x = ((int16_t)((data[1] << 8) | data[0])) >> 4;
        *y = ((int16_t)((data[3] << 8) | data[2])) >> 4;
        *z = ((int16_t)((data[5] << 8) | data[4])) >> 4;
        return 0;
    }
    // In case of communication failure
    *x = 0;
    *y = 0;
    *z = 0;
    return 1;
}
