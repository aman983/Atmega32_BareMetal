#include <avr/io.h>
#include <avr/iom32.h>

#include "GPIO.h"

void Pin_Init(Port_config_t *config, Pin_mode P_config, uint8_t Pin) {

    // Pull UP Selected
    if (P_config == PIN_INPUT_PULLUP) {
        *(config->DDRx) &= ~(1 << Pin);  
        
        *(config->PORTx) |= (1 << Pin); 
    // Normal Input
    }else if (P_config == PIN_INPUT) {
        *(config->DDRx) &= ~(1 << Pin);   
        
        *(config->PORTx) &= ~(1 << Pin); 
    // Set as Output
    }else if (P_config == PIN_OUTPUT) {
        *(config->DDRx) |= (1 << Pin);   
        
        *(config->PORTx) &= ~(1 << Pin); 
    } 
}

void Port_Init(Port_config_t *config, Pin_mode P_config){
    if(P_config == PIN_INPUT){
        *(config->DDRx) = 0x00;
    }else if(P_config == PIN_INPUT_PULLUP){
        *(config->DDRx) = 0x00;
        *(config->PORTx) = 0xff;
    }else{
        *(config->DDRx) = 0xff;
        *(config->PORTx) = 0x00;
    }
}

// write to a defined Port Pin
void Write_Pin(Port_config_t *config, Pin_mode P_config, uint8_t Pin, Pin_state P_State) {
    if(P_config == PIN_OUTPUT){
        if(P_State == PIN_SET){
            *(config->PORTx) |= (1 << Pin);
        }else if(P_State == PIN_RESET){
            *(config->PORTx) &= ~(1 << Pin);          
        }
        
    }
}
// Write to Port
void Write_Port(Port_config_t *config, uint8_t Data){
    *(config->PORTx) = Data;
}


// Read Pin State
uint8_t Read_Pin(Port_config_t *config, uint8_t Pin) {
    
    return ( *(config->PINx) & (1 << Pin) );
    
}
// Read All Port Pins
uint8_t Read_Port(Port_config_t *config){
    return ( *(config->PINx) );
}