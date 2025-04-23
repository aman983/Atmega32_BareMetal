#ifndef BIT_BANG_I2C_H
#define BIT_BANG_I2C_H
#include "GPIO.h"

typedef struct {
    Port_config_t *Driver_Port;
    uint8_t SDA;
    uint8_t SCL;
}Bit_Bang_I2C_Config_t;


void I2C_Init(Bit_Bang_I2C_Config_t *config);
void I2C_Start(Bit_Bang_I2C_Config_t *config);
void I2C_Stop(Bit_Bang_I2C_Config_t *config);
void I2C_Send_Byte(Bit_Bang_I2C_Config_t *config, uint8_t byte);

#endif