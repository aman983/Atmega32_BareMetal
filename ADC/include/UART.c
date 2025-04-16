#include <avr/io.h>
#include <avr/iom32.h>

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
    UCSRB |= (1 << 4) | (1 << 3);
    UCSRC |= (1 << 3) | (1 << 2);

    UBRRH = 0x00;
    UBRRL = config_uart->Baud_rate;
}
void UART_send_Str(char *str){
    while (*str)
    {
        UDR = *str;
        while ( (UCSRA & 0x40) == 0);
        str++;
    }   
}
