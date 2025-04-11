#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/iom32.h>

#include "util/delay.h"

#include "include/GPIO.h"
#include "include/LCD16X2.h"

int main(){

    char str[10] = "HELLO";
    Port_config_t lcd_Command_Port = {
        .DDRx = &DDRD,
        .PORTx = &PORTD,
        .PINx = &PIND
    };

    Port_config_t lcd_Data_Port = {
        .DDRx = &DDRC,
        .PORTx = &PORTC,
        .PINx = &PINC
    };

    LCD_config_t lcd_config = {
        .Command_Port = &lcd_Command_Port,
        .Data_Port = &lcd_Data_Port,
        .En_pin = 5,
        .Rs_pin = 7,
        .Rw_pin = 6
    };

    LCD_init(&lcd_config);
    Display_Str(&lcd_config, str);
    while(1){
        _delay_ms(1000);

    }
}