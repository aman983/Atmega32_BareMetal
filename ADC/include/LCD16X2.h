#ifndef LCD16X2_H
#define LCD16X2_H
#include <stdint.h>
#include "GPIO.h"

typedef struct {
    Port_config_t *Data_Port;
    Port_config_t *Command_Port;
    uint8_t Rs_pin;
    uint8_t Rw_pin;
    uint8_t En_pin;
}LCD_config_t;


void LCD_init(LCD_config_t *lcd_config);
void Display_Str(LCD_config_t *lcd_config, char *str);
void Display_Clear(LCD_config_t *lcd_config);


#endif