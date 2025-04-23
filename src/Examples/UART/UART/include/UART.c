#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/iom32.h>
#include <util/delay.h>
#include "GPIO.h"
#include "UART.h"


void UART_Init(UART_config_t *config_uart){
    Port_config_t Uart_Port = {
        .DDRx = &DDRD,
        .PINx = &PIND,
        .PORTx = &PORTD
    };
    Pin_Init(&Uart_Port, PIN_OUTPUT, 2);
    Write_Pin(&Uart_Port, PIN_OUTPUT, 2, PIN_RESET);

    UCSRA = 0x00;
    UCSRB |= 0x18;
    UCSRC |= 0x06;

    UBRRH = 0x00;
    UBRRL = 0x33;
}
void UART_send_Str(char *str){
    while (*str)
    {
        UDR = *str;
        while ( (UCSRA & 0x40) == 0);
        _delay_ms(10);
        str++;
    }   
}
