#ifndef TIMER_H
#define TIMER_H

typedef enum {
    TIM_0,
    TIM_1,
    TIM_2,
    NORMAL,
    PWM_PHASE_CORRECT,
    CTC,
    FAST_PWM,
    CLK_0,
    CLK_8,
    CLK_64,
    CLK_256,
    CLK_1024,
    CLK_EXT_T0_FALLING_EDGE,
    CLK_EXT_T0_RISING_EDGE,
    TOGGLE_OC0_ON_MATCH,
    CLEAR_OC0_ON_MATCH,
    SET_OC0_ON_MATCH,
}timer_settings;

typedef struct{
    timer_settings timer_select;
    timer_settings Prescaler;
    timer_settings mode;
    timer_settings output_compare_behaviour;
}timer_config_t;


int Timer_Init(timer_config_t *timer);

#endif