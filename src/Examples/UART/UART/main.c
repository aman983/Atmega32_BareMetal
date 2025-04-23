#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/iom32.h>
#include <util/delay.h>
#include <stdio.h>

#include "UART.h"



int main(){
    char Buffer[20];
    uint8_t some_value = 7;
    UART_config_t config_uart = {
        .Baud_rate = BAUD_9600
    };

    UART_Init(&config_uart);
    sprintf(Buffer, "Hello World ! %d\n",some_value);
    
    while(1){
        UART_send_Str(Buffer);
        _delay_ms(1000);
    }
}