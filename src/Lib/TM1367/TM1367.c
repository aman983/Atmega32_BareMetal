#include <avr/io.h>
#include <avr/iom32.h>
#include <stdbool.h>

#include "Bit_Bang_I2C.h"
#include "GPIO.h"
#include "TM1637.h"

static Bit_Bang_I2C_Config_t I2C_Conf;

void TM1637_Send_Frame(TM1637_Config_t *display_config, uint8_t *frame){

    I2C_Start(&I2C_Conf);
    I2C_Send_Byte(&I2C_Conf, DISP_I2C_COMM1);
    I2C_Stop(&I2C_Conf);

    I2C_Start(&I2C_Conf);
    I2C_Send_Byte(&I2C_Conf, DISP_I2C_COMM2);
    for(uint8_t i=0; i<4; i++){
        I2C_Send_Byte(&I2C_Conf, *frame);
        frame++;
    }
    I2C_Stop(&I2C_Conf);

    I2C_Start(&I2C_Conf);
    I2C_Send_Byte(&I2C_Conf, DISP_I2C_COMM3 + (DISP_ON_MASK | display_config->Brightness));
    I2C_Stop(&I2C_Conf);

}


uint8_t Primitive_Number_Decoder(uint8_t Number){
    switch(Number) {
        case 0:
          return DISP_DIG_0;
          break;
        case 1:
          return DISP_DIG_1;
          break;
        case 2:
          return DISP_DIG_2;
          break;
        case 3:
          return DISP_DIG_3;
          break;
        case 4:
          return DISP_DIG_4;
          break;
        case 5:
          return DISP_DIG_5;
          break;
        case 6:
          return DISP_DIG_6;
          break;
        case 7:
          return DISP_DIG_7;
          break;
        case 8:
          return DISP_DIG_8;
          break;
        case 9:
          return DISP_DIG_9;
          break;
        default:
          return DISP_NONE;
      }
}

void TM1637_Display_Number(TM1637_Config_t *display_config, int16_t Number){
    int16_t safe_number = Number;
    uint8_t digit = 0;
    bool is_positive = safe_number > 0;
    // Out of Rnage Guard
    if(safe_number > 9999){
        safe_number = 9999;
    }else if(safe_number < -999){
        safe_number = -999;
    }
    if(!is_positive){
        safe_number = safe_number * -1;
    }
    
    uint8_t i = 0;
    
    if(safe_number == 0){
        display_config->frame[0] = DISP_NONE;
        display_config->frame[1] = DISP_NONE;
        display_config->frame[2] = DISP_NONE;
        display_config->frame[3] = DISP_DIG_0;
        TM1637_Send_Frame(display_config, display_config->frame);
        return;
    }
        
    for(; i<4; i++){
        if(i != 0){
            safe_number = safe_number / 10;
        }
        if(safe_number < 1){
            break;
        }
        digit = safe_number % 10;
        display_config->frame[3 - i] = Primitive_Number_Decoder(digit);
    }
        
    
    if(!is_positive){
        display_config->frame[3 - i] = DISP_MINUS;
    }

    TM1637_Send_Frame(display_config, display_config->frame);

}


void TM1637_Init(TM1637_Config_t *display_config){
    I2C_Conf.Driver_Port = display_config->Driver_Port;
    I2C_Conf.SDA = display_config->SDA_pin;
    I2C_Conf.SCL = display_config->SCL_pin;
    I2C_Init(&I2C_Conf);
}
