#ifndef MAX7219_H
#define MAX7219_H

#include "GPIO.h"

typedef struct {
    uint8_t CS_Pin;
    uint8_t Display_id;
    uint8_t Brightness;
}MAX7219_Config_t;

void MAX7219_Init(MAX7219_Config_t *config);
void MAX7219_Clear(MAX7219_Config_t *config);
void MAX7219_Set(MAX7219_Config_t *config);
void MAX7219_Display_Frame(MAX7219_Config_t *config, uint8_t *Frame);

#endif