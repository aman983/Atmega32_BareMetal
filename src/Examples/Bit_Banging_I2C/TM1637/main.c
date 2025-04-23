#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/iom32.h>
#include <stdbool.h>

#include <util/delay.h>

#include "TM1637.h"


int main(){
    Port_config_t driver_port = {
        .DDRx = &DDRA,
        .PINx = &PINA,
        .PORTx = &PORTA
    };
    TM1637_Config_t display_config = {
        .Driver_Port = &driver_port,
        .SDA_pin = 0,
        .SCL_pin = 1,
        .Brightness = 4
    };
    TM1637_Init(&display_config);
    int16_t i = 0;
    while(1){
        for(i=999; i>0; i--){
            TM1637_Display_Number(&display_config, i);
            _delay_ms(10);
        }
        
    }
}