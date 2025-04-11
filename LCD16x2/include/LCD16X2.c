#define F_CPU 8000000UL
#include "util/delay.h"

#include "GPIO.h"
#include "LCD16X2.h"


void Send_command(LCD_config_t *lcd_config, uint8_t command){
    Write_Pin(lcd_config->Command_Port, PIN_OUTPUT, lcd_config->Rw_pin, PIN_RESET);
    Write_Pin(lcd_config->Command_Port, PIN_OUTPUT, lcd_config->Rs_pin, PIN_RESET);

    Write_Port((lcd_config->Data_Port), command);

    Write_Pin(lcd_config->Command_Port, PIN_OUTPUT, lcd_config->En_pin, PIN_SET);
    _delay_ms(10);
    Write_Pin(lcd_config->Command_Port, PIN_OUTPUT, lcd_config->En_pin, PIN_RESET);
}

void Send_data(LCD_config_t *lcd_config, uint8_t data){
    Write_Pin(lcd_config->Command_Port, PIN_OUTPUT, lcd_config->Rs_pin, PIN_SET);
    Write_Pin(lcd_config->Command_Port, PIN_OUTPUT, lcd_config->Rw_pin, PIN_RESET);

    Write_Port(lcd_config->Data_Port, data);

    Write_Pin(lcd_config->Command_Port, PIN_OUTPUT, lcd_config->En_pin, PIN_SET);
    _delay_ms(10);
    Write_Pin(lcd_config->Command_Port, PIN_OUTPUT, lcd_config->En_pin, PIN_RESET);
}


void Display_Str(LCD_config_t *lcd_config, char *str){
    while (*str)
    {
        Send_data(lcd_config, *str);
        str++;
    }
    
}

void LCD_init(LCD_config_t *lcd_config){
    Port_Init(lcd_config->Data_Port, PIN_OUTPUT);
    Write_Port(lcd_config->Data_Port, 0x00);

    Pin_Init(lcd_config->Command_Port,PIN_OUTPUT, lcd_config->Rs_pin);
    Pin_Init(lcd_config->Command_Port,PIN_OUTPUT, lcd_config->Rw_pin);
    Pin_Init(lcd_config->Command_Port,PIN_OUTPUT, lcd_config->En_pin);

    Send_command(lcd_config, 0x38);
    Send_command(lcd_config, 0x0C);
    
    Send_command(lcd_config, 0x01); // clear cmd
    
    Send_command(lcd_config, 0x06);
}

