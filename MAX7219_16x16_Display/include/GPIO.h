#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef enum {
    PIN_RESET,
    PIN_SET
}Pin_state;

typedef enum{
    PIN_INPUT,
    PIN_INPUT_PULLUP,
    PIN_OUTPUT
}Pin_mode;
typedef struct {
    volatile uint8_t *DDRx;
    volatile uint8_t *PORTx;
    volatile uint8_t *PINx;
}Port_config_t;



void Port_Init(Port_config_t *config, Pin_mode P_config);

void Pin_Init(Port_config_t *config, Pin_mode P_config, uint8_t Pin);

void Write_Pin(Port_config_t *config, Pin_mode P_config, uint8_t Pin, Pin_state P_State);
void Write_Port(Port_config_t *config, uint8_t Data);

uint8_t Read_Pin(Port_config_t *config, uint8_t Pin);
uint8_t Read_Port(Port_config_t *config);

#endif