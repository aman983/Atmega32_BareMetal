#include <avr/io.h>
#include <avr/iom32.h>

#include "GPIO.h"
#include "SPI.h"

static Port_config_t INTERNAL_SPI_PORT;

void SPI_Master_Init(SPI_Config_t *SPI_Config){
    INTERNAL_SPI_PORT.DDRx = &DDRB;
    INTERNAL_SPI_PORT.PINx = &PINB;
    INTERNAL_SPI_PORT.PORTx = &PORTB;

    // SPI PINS MOSI | MISO | CLK
    Pin_Init(&INTERNAL_SPI_PORT, PIN_OUTPUT, 7);
    Pin_Init(&INTERNAL_SPI_PORT, PIN_INPUT, 6); // MISO
    Pin_Init(&INTERNAL_SPI_PORT, PIN_OUTPUT, 5);
    
    Write_Pin(&INTERNAL_SPI_PORT, PIN_OUTPUT, 7, PIN_RESET);
    Write_Pin(&INTERNAL_SPI_PORT, PIN_OUTPUT, 5, PIN_RESET);

    // SPI PIN CS
    Pin_Init(&INTERNAL_SPI_PORT, PIN_OUTPUT, SPI_Config->CS_PIN);
    Write_Pin(&INTERNAL_SPI_PORT, PIN_OUTPUT, SPI_Config->CS_PIN, PIN_SET);
    
    //Enable SPI
    SPCR = (1 << 6);
    
    if (SPI_Config->Data_Order == LSB_FIRST){
        SPCR |= (1 << 5);
    }else if (SPI_Config->Data_Order == MSB_FIRST){
        SPCR &= ~(1 << 5);
    }
    
    if(SPI_Config->Device_Role == SPI_MASTER){
        SPCR |= (1 << 4);
    }else if(SPI_Config->Device_Role == SPI_SLAVE){
        SPCR &= ~(1 << 4);
    }

    switch (SPI_Config->SCK_Freq)
    {
        case CPU_FREQ_2:
        SPSR |= (1 << 0);
        break;
    
        case CPU_FREQ_4:
        SPCR &= ~((1 << 0) | (1 << 1));
        break;
    
        case CPU_FREQ_8:
        SPSR |= (1 << 0);
        SPCR |= (1 << 0);
        SPCR &= ~(1 << 1);
        break;
    
        case CPU_FREQ_16:
        SPCR |= (1 << 0);
        SPCR &= ~(1 << 1);
        break;
    
        case CPU_FREQ_32:
        SPSR |= (1 << 0);
        SPCR |= (1 << 1);
        SPCR &= ~(1 << 0);
        break;
    
        case CPU_FREQ_64:
        SPSR |= (1 << 0);
        SPCR |= (1 << 1) | (1 << 0);
        break;
    
        case CPU_FREQ_128:
        SPCR |= (1 << 1) | (1 << 0);
        break;
    default:
        break;
    }
    
}

void SPI_Master_Tx(uint8_t data){
    uint8_t x = '\0';
    SPDR = data;
    while ( (SPSR & 0x80) == 0);
    x = SPDR;
}

void SPI_Master_Write_Register(uint8_t Address, uint8_t Data){
    SPI_Master_Tx(Address);
    SPI_Master_Tx(Data);
}

void SPI_CS_HIGH(SPI_Config_t *SPI_Config){
    Write_Pin(&INTERNAL_SPI_PORT, PIN_OUTPUT, SPI_Config->CS_PIN, PIN_SET);
}

void SPI_CS_LOW(SPI_Config_t *SPI_Config){
    Write_Pin(&INTERNAL_SPI_PORT, PIN_OUTPUT, SPI_Config->CS_PIN, PIN_RESET);
}