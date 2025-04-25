#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/iom32.h>
#include <util/delay.h>

#include "GPIO.h"
#include "MAX7219.h"
#include "SPI.h"

#define NO_OP_REG           0x00
#define INTENSITY_REG       0x0A
#define SCAN_LIMIT_REG      0x0B
#define SHUTDOWN_REG        0x0C
#define DISPLAY_TEST_REG    0x0F 

static SPI_Config_t MAX7219_SPI_Channel_Config;


void MAX7219_Init(MAX7219_Config_t *config){
    MAX7219_SPI_Channel_Config.CS_PIN = config->CS_Pin;
    MAX7219_SPI_Channel_Config.Data_Order = MSB_FIRST;
    MAX7219_SPI_Channel_Config.Device_Role = SPI_MASTER;
    MAX7219_SPI_Channel_Config.SCK_Freq = CPU_FREQ_4;
    
    SPI_Master_Init(&MAX7219_SPI_Channel_Config);

    SPI_CS_LOW(&MAX7219_SPI_Channel_Config);
    SPI_Master_Write_Register(INTENSITY_REG, 0x05);
    SPI_CS_HIGH(&MAX7219_SPI_Channel_Config);
    
    SPI_CS_LOW(&MAX7219_SPI_Channel_Config);
    SPI_Master_Write_Register(SCAN_LIMIT_REG, 0x07);
    SPI_CS_HIGH(&MAX7219_SPI_Channel_Config);

    SPI_CS_LOW(&MAX7219_SPI_Channel_Config);
    SPI_Master_Write_Register(SHUTDOWN_REG, 0x01);
    SPI_CS_HIGH(&MAX7219_SPI_Channel_Config);

    SPI_CS_LOW(&MAX7219_SPI_Channel_Config);
    SPI_Master_Write_Register(DISPLAY_TEST_REG, 0x00);
    SPI_CS_HIGH(&MAX7219_SPI_Channel_Config);
}

void MAX7219_Clear(MAX7219_Config_t *config){
    MAX7219_SPI_Channel_Config.CS_PIN = config->CS_Pin;
    for(uint8_t  i = 0x01; i <= 0x08; i += 0x01){
        SPI_CS_LOW(&MAX7219_SPI_Channel_Config);
        SPI_Master_Write_Register(SHUTDOWN_REG, 0x00);
        SPI_Master_Write_Register(i, 0x00);
        SPI_CS_HIGH(&MAX7219_SPI_Channel_Config);
       
    }
}

void MAX7219_Set(MAX7219_Config_t *config){
    MAX7219_SPI_Channel_Config.CS_PIN = config->CS_Pin;
    for(uint8_t  i = 0x01; i <= 0x08; i += 0x01){
        SPI_CS_LOW(&MAX7219_SPI_Channel_Config);
        SPI_Master_Write_Register(SHUTDOWN_REG, 0x00);
        SPI_Master_Write_Register(i, 0xFF);
        SPI_CS_HIGH(&MAX7219_SPI_Channel_Config);
    }
}

void MAX7219_Display_Frame(MAX7219_Config_t *config, uint8_t *Frame){
    MAX7219_SPI_Channel_Config.CS_PIN = config->CS_Pin;
    for(uint8_t i = 0x01; i <= 0x08; i += 0x01){
        SPI_CS_LOW(&MAX7219_SPI_Channel_Config);
        SPI_Master_Write_Register(i, *Frame);
        SPI_CS_HIGH(&MAX7219_SPI_Channel_Config);
        Frame++;
    }
}

