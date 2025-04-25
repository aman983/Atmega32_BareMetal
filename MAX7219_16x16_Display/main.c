#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/iom32.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>


#include "MAX7219.h"


int main(){
    
    MAX7219_Config_t dspl = {
        .Brightness = 0,
        .CS_Pin = 4,
        .Display_id = 1
    };
    MAX7219_Init(&dspl);
    while(1){
        MAX7219_Clear(&dspl);
        _delay_ms(500);

        MAX7219_Set(&dspl);
        _delay_ms(500);
    }
}