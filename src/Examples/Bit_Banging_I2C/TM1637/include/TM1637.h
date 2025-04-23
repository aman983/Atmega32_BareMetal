#ifndef TIM1637_h
#define TIM1637_h

#include "GPIO.h"

#define DISP_I2C_COMM1 0b01000000 // data command setting
#define DISP_I2C_COMM2 0b11000000 // address command setting (can be without address offset, then the address is 0)
#define DISP_I2C_COMM3 0b10000000 // display control

// brightness
#define DISP_BR_0 0b00000000
#define DISP_BR_1 0b00000001
#define DISP_BR_2 0b00000010
#define DISP_BR_3 0b00000011
#define DISP_BR_4 0b00000100
#define DISP_BR_5 0b00000101
#define DISP_BR_6 0b00000110
#define DISP_BR_7 0b00000111

#define DISP_ON_MASK  0b00001000
#define DISP_OFF_MASK 0b00000000

#define DISP_CTRL_MASK 0b00001111

// segments
#define DISP_SEG_DP 0b10000000 // decimal point
#define DISP_SEG_G  0b01000000
#define DISP_SEG_F  0b00100000
#define DISP_SEG_E  0b00010000
#define DISP_SEG_D  0b00001000
#define DISP_SEG_C  0b00000100
#define DISP_SEG_B  0b00000010
#define DISP_SEG_A  0b00000001

// digits
#define DISP_NONE  0
#define DISP_DIG_0 DISP_SEG_A | DISP_SEG_B | DISP_SEG_C | DISP_SEG_D | DISP_SEG_E | DISP_SEG_F
#define DISP_DIG_1 DISP_SEG_B | DISP_SEG_C
#define DISP_DIG_2 DISP_SEG_A | DISP_SEG_B | DISP_SEG_G | DISP_SEG_E | DISP_SEG_D
#define DISP_DIG_3 DISP_SEG_A | DISP_SEG_B | DISP_SEG_G | DISP_SEG_C | DISP_SEG_D
#define DISP_DIG_4 DISP_SEG_B | DISP_SEG_C | DISP_SEG_G | DISP_SEG_F
#define DISP_DIG_5 DISP_SEG_A | DISP_SEG_F | DISP_SEG_G | DISP_SEG_C | DISP_SEG_D
#define DISP_DIG_6 DISP_SEG_A | DISP_SEG_F | DISP_SEG_G | DISP_SEG_C | DISP_SEG_D | DISP_SEG_E
#define DISP_DIG_7 DISP_SEG_A | DISP_SEG_B | DISP_SEG_C
#define DISP_DIG_8 DISP_SEG_A | DISP_SEG_B | DISP_SEG_C | DISP_SEG_D | DISP_SEG_E | DISP_SEG_F | DISP_SEG_G
#define DISP_DIG_9 DISP_SEG_A | DISP_SEG_B | DISP_SEG_C | DISP_SEG_D | DISP_SEG_F | DISP_SEG_G

// minus
#define DISP_MINUS DISP_SEG_G

// circle
#define DISP_UP DISP_SEG_F | DISP_SEG_A | DISP_SEG_B
#define DISP_TR DISP_SEG_A | DISP_SEG_B | DISP_SEG_C
#define DISP_BR DISP_SEG_B | DISP_SEG_C | DISP_SEG_D
#define DISP_DN DISP_SEG_C | DISP_SEG_D | DISP_SEG_E
#define DISP_BL DISP_SEG_D | DISP_SEG_E | DISP_SEG_F


typedef struct {
    Port_config_t *Driver_Port;
    uint8_t SDA_pin;
    uint8_t SCL_pin;
    uint8_t Brightness;
    uint8_t frame[4];
}TM1637_Config_t;

void TM1637_Init(TM1637_Config_t *display_config);
void TM1637_Display_Number(TM1637_Config_t *display_config, int16_t Number);
uint8_t Primitive_Number_Decoder(uint8_t Number);
void TM1637_Send_Frame(TM1637_Config_t *display_config, uint8_t *frame);




#endif