#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/iom32.h>

#include <util/delay.h>

#include "GPIO.h"

void I2C_Init(Port_config_t *driver_port, uint8_t SDA, uint8_t SCL){
    Pin_Init(driver_port, PIN_OUTPUT, SDA);
    Pin_Init(driver_port, PIN_OUTPUT, SCL);
};

void I2C_Start(Port_config_t *driver_port, uint8_t SDA, uint8_t SCL){
    Write_Pin(driver_port, PIN_OUTPUT, SDA, PIN_RESET);
    _delay_us(100);
}


void I2C_Stop(Port_config_t *driver_port, uint8_t SDA, uint8_t SCL){
    Write_Pin(driver_port, PIN_OUTPUT, SDA, PIN_RESET);
    _delay_us(100);
    Write_Pin(driver_port, PIN_OUTPUT, SCL, PIN_SET);
    _delay_us(100);
    Write_Pin(driver_port, PIN_OUTPUT, SDA, PIN_SET);
    _delay_us(100);
}

void I2C_Send_Bit(Port_config_t *driver_port, uint8_t SDA, uint8_t SCL, uint8_t byte){
    uint8_t data = byte;
    
    for(uint8_t i = 0; i < 8; i++){
        Write_Pin(driver_port, PIN_OUTPUT, SCL, PIN_RESET);
        _delay_us(100);

        if(data & 0x01){
            Write_Pin(driver_port, PIN_OUTPUT, SDA, PIN_SET);
        }else {
            Write_Pin(driver_port, PIN_OUTPUT, SDA, PIN_RESET);
        }
        _delay_us(100);

        Write_Pin(driver_port, PIN_OUTPUT, SCL, PIN_SET);
        _delay_us(100);
        data = data >> 1;
    }
    Write_Pin(driver_port, PIN_OUTPUT, SCL, PIN_RESET);
    Write_Pin(driver_port, PIN_OUTPUT, SDA, PIN_SET);
    _delay_us(100);

    Write_Pin(driver_port, PIN_OUTPUT, SCL, PIN_SET);
    _delay_us(100);

    // add ack read at sda here using read pin fn
    //_delay_us(100);


    Write_Pin(driver_port, PIN_OUTPUT, SCL, PIN_RESET);
    _delay_us(100);
}




int main(){
    Port_config_t driver_port = {
        .DDRx = &DDRA,
        .PINx = &PINA,
        .PORTx = &PORTA
    };

    I2C_Init(&driver_port, 0,1);
    uint8_t data = 170;
    while(1){
        I2C_Send_Bit(&driver_port, 0,1,data);
        I2C_Stop(&driver_port, 0,1);
        _delay_ms(1000);
    }
}