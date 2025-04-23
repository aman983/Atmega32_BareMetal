#include <avr/io.h>
#include <avr/iom32.h>


#include "GPIO.h"
#include "TIMER.h"

int Timer_Init(timer_config_t *timer){ 
    switch (timer->timer_select)
    {
    case TIM_0:
        switch (timer->Prescaler)
        {
        case CLK_0:
            
            break;
        case CLK_8:
            
            break;
        case CLK_64:
            
            break;
        case CLK_1024:
            
            break;
        case CLK_EXT_T0_FALLING_EDGE:
            
            break;
        case CLK_EXT_T0_RISING_EDGE:
            
            break;
        
        default:
            return -1;
            break;
        }

        switch (timer->mode)
        {
        case NORMAL:
            
            break;
        case CTC:
            
            break;
        case FAST_PWM:
            
            break;
        case PWM_PHASE_CORRECT:
            
            break;
        
        default:
            return -1;
            break;
        }

        switch (timer->output_compare_behaviour)
        {
    
        case NORMAL:
            
            break;
        
        case TOGGLE_OC0_ON_MATCH:
            if (timer->mode == NORMAL)
            {
               
            }
            else{
                return -1;
            }
            break;
        
        case CLEAR_OC0_ON_MATCH:
            
            break;
        
        case SET_OC0_ON_MATCH:
            
            break;
        default:
            break;
        }

        return 0;
        break;
    
    default:
        return -1;
        break;
    }
}