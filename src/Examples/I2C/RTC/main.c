#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/iom32.h>


#include <util/delay.h>
#include <stdio.h>
#include <string.h>

#include "DS3231.h"
#include "UART.h"


int main(){
    char print_buffer[60];
    UART_config_t conf_uart = {
        .Baud_rate = 9600
    };
    UART_Init(&conf_uart);
    
    RTC_Config_t rt_conf = {
        .DS3231_I2C_ADDRESS = 0x68,
    };

    RTC_Data_Format Data_Frame;

    DS3231_Init();

    
    while(1){
        _delay_ms(500);
        DS3231_Get_Time(&rt_conf, &Data_Frame);
        sprintf(print_buffer, "Time %02x:%02x:%02x \t Day: %02x \t Date: %02x.%02x.%02x \r ",Data_Frame.hours, Data_Frame.minutes, Data_Frame.seconds, Data_Frame.Day_Of_Week, Data_Frame.Date, Data_Frame.Month, Data_Frame.Year);
        UART_send_Str(print_buffer);
        memset(print_buffer, '\0', 60);
    }
}