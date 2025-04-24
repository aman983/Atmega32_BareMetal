#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/iom32.h>
#include <stdbool.h>

#include <util/delay.h>

#include "TM1637.h"

#define ANIMATION_FRAMES 6
#define FRAME_LENGTH 4
int main(){
     // each row is one frame
    uint8_t Animation[ANIMATION_FRAMES][FRAME_LENGTH] = {
        {DISP_UP, DISP_UP, DISP_UP, DISP_UP},
        {DISP_TR, DISP_TR, DISP_TR, DISP_TR},
        {DISP_BR, DISP_BR, DISP_BR, DISP_BR},
        {DISP_DN, DISP_DN, DISP_DN, DISP_DN},
        {DISP_BL, DISP_BL, DISP_BL, DISP_BL},
        {DISP_TL, DISP_TL, DISP_TL, DISP_TL}
    };
    Port_config_t driver_port = {
        .DDRx = &DDRA,
        .PINx = &PINA,
        .PORTx = &PORTA
    };
    TM1637_Config_t display_config = {
        .Driver_Port = &driver_port,
        .SDA_pin = 0,
        .SCL_pin = 1,
        .Brightness = 5
    };
    TM1637_Init(&display_config);

    TM1637_Display_Number(&display_config, 1427);
    _delay_ms(1000);
    while(1){
        TM1637_Animate(&display_config, ANIMATION_FRAMES, FRAME_LENGTH, Animation, 50);
    }
}