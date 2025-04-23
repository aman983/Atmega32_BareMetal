#include <avr/io.h>
#include <avr/iom32.h>
#include "I2C.h"


void I2C_Master_Init(){
    TWSR &= 0xF8;
    TWBR = 0x07;
    TWCR |= (1 << 2);
}

void I2C_Start(){
    TWCR = (1 << 7) | (1 << 5) | (1 << 2);
    while ((TWCR & (1 << 7)) == 0);
}

void I2C_Stop(){
    TWCR = (1 << 4) | (1 << 2) | (1 << 7);
}

void I2C_Write(char data){
    TWDR = data;
    TWCR = (1 << 7) | (1 << 2);
    while ((TWCR & (1 << 7)) == 0);
}

void I2C_Read_Multiple(int n, uint8_t *buffer){
    for(int x = 0; x < n; x++){
        if(x < (n -1)){
            TWCR = (1 << 7) | (1 << 6) | (1 << 2);
            while ((TWCR & (1 << 7)) == 0);
            *buffer = TWDR;
        }
        else{
            TWCR = (1 << 7) | (1 << 2);
            while ((TWCR & (1 << 7)) == 0);
            *buffer = TWDR;
        }
        buffer++;
    }
}

