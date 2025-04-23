#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/iom32.h>

#include <util/delay.h>

#include "GPIO.h"
#include "Bit_Bang_I2C.h"

void I2C_Init(Bit_Bang_I2C_Config_t *config){
    Pin_Init(config->Driver_Port, PIN_OUTPUT, config->SDA);
    Pin_Init(config->Driver_Port, PIN_OUTPUT, config->SCL);
};

void I2C_Start(Bit_Bang_I2C_Config_t *config){
    Pin_Init(config->Driver_Port, PIN_OUTPUT, config->SDA);
    _delay_us(100);
}


void I2C_Stop(Bit_Bang_I2C_Config_t *config){
    Pin_Init(config->Driver_Port, PIN_OUTPUT, config->SDA);
    _delay_us(100);
    Pin_Init(config->Driver_Port, PIN_INPUT, config->SCL);
    _delay_us(100);
    Pin_Init(config->Driver_Port, PIN_INPUT, config->SDA);
    _delay_us(100);
}

void I2C_Send_Byte(Bit_Bang_I2C_Config_t *config, uint8_t byte){
    uint8_t data = byte;
    uint8_t ack = 0;
    for(uint8_t i = 0; i < 8; i++){
        Pin_Init(config->Driver_Port, PIN_OUTPUT, config->SCL);
        _delay_us(100);

        if(data & 0x01){
            Pin_Init(config->Driver_Port, PIN_INPUT, config->SDA);
        }else {
            Pin_Init(config->Driver_Port, PIN_OUTPUT, config->SDA);
        }
        _delay_us(100);

        Pin_Init(config->Driver_Port, PIN_INPUT, config->SCL);
        _delay_us(100);
        data = data >> 1;
    }
    Pin_Init(config->Driver_Port, PIN_OUTPUT, config->SCL);
    Pin_Init(config->Driver_Port, PIN_INPUT, config->SDA);
    _delay_us(100);

    Pin_Init(config->Driver_Port, PIN_INPUT, config->SCL);
    _delay_us(100);

    // add ack read at config->SDA here using read pin fn

    ack  = Read_Pin(config->Driver_Port, config->SDA);
    if(ack == 0){
        Pin_Init(config->Driver_Port, PIN_OUTPUT, config->SDA);
    }
    _delay_us(100);

    Pin_Init(config->Driver_Port, PIN_OUTPUT, config->SCL);
    _delay_us(100);
}
