#include <avr/io.h>
#include <avr/iom32.h>

#include <util/delay.h>
#include "GPIO.h"

int main(){
    Port_config_t Driver_Port = {  
        .DDRx = &DDRC,
        .PINx = &PINC,
        .PORTx = &PORTC
    };
    
    Pin_Init(&Driver_Port, PIN_INPUT, 7);
    Pin_Init(&Driver_Port, PIN_OUTPUT, 6);
    while(1){
        if(Read_Pin(&Driver_Port, 7)){
            Write_Pin(&Driver_Port, PIN_OUTPUT, 6, PIN_SET);
        }else{
            Write_Pin(&Driver_Port, PIN_OUTPUT, 6, PIN_RESET);
        }
        _delay_ms(100);
        
    }
}