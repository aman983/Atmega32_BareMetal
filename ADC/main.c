#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/iom32.h>
#include <stdio.h>

#include "util/delay.h"

#include "GPIO.h"
#include "UART.h"
#include "ADC.h"
#include "LCD16X2.h"

int main(){

    char buffer[15];
    uint16_t k = 0;

    
    Port_config_t command_port_lcd ={
        .DDRx = &DDRD,
        .PINx = &PIND,
        .PORTx = &PORTD
    };
    Port_config_t data_port_lcd = {
        .DDRx = &DDRC,
        .PINx = &PINC,
        .PORTx = &PORTC
    };

    LCD_config_t display_config = {
        .Command_Port = &command_port_lcd,
        .Data_Port = &data_port_lcd,
        .En_pin = 5,
        .Rs_pin = 7,
        .Rw_pin = 6
    };
    
    LCD_init(&display_config);

    UART_config_t config_uart = {
        .Baud_rate = BAUD_9600
    };

    UART_Init(&config_uart);

   ADC_Config_t config_adc = {
    .Channel = CH_0,
    .Prescalar = CLK_128,
    .Ref_Voltage = AVCC
   };

   ADC_Init(&config_adc);


    while(1){
        k = ADC_Get_MilliVolts();
        sprintf(buffer, "%d.%d%d%d V\n", (k / 1000), (k / 100)%10, (k / 10)%10, (k %10));
        UART_send_Str(buffer);
        Display_Str(&display_config, buffer);

        _delay_ms(500);

        Display_Clear(&display_config);

    }
}