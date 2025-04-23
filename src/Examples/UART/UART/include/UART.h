#ifndef UART_H
#define UART_H

typedef enum {
    BAUD_2400   = 0xCF,
    BAUD_4800   = 0x67,
    BAUD_9600   = 0x33,
    BAUD_19200  = 0x19,
    BAUD_38400  = 0x0C
}UART_baudrate;


typedef struct{
   UART_baudrate Baud_rate;
}UART_config_t;




void UART_Init(UART_config_t *config_uart);
void UART_send_Str(char *str);

#endif