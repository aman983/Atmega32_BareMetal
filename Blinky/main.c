#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/iom32.h>

#include "util/delay.h"

#include "include/GPIO.h"

int main(){

    // Before using the GPIO always make a valid PORT configuration this helps to keep the code in order
    Port_config_t config_PortA = {
        .DDRx = &DDRA,
        .PINx = &PINA,
        .PORTx = &PORTA
    };

    // Initalise the pin in output state and also pass the required port configuration
    Pin_Init(&config_PortA, PIN_OUTPUT, 7);

    while (1)
    {
        // Write Pin Function used to set the pin value of specified pin (7 in this case)
        Write_Pin(&config_PortA, PIN_OUTPUT, 7, PIN_SET);
        _delay_ms(500);

        Write_Pin(&config_PortA, PIN_OUTPUT, 7, PIN_RESET);
        _delay_ms(500);
        
    }
    
}