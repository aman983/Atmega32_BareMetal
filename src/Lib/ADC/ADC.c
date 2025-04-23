#include <avr/io.h>
#include <avr/iom32.h>

#include "GPIO.h"
#include "ADC.h"

void ADC_Init(ADC_Config_t *adc_config){
    Port_config_t ADC_PORT = {
        .DDRx = &DDRA,
        .PINx = &PINA,
        .PORTx = &PORTA
    };
    
    switch (adc_config->Channel)
    {
    case CH_0:
            Pin_Init(&ADC_PORT, PIN_INPUT, 0);
            ADMUX |= CH_0;
        break;
        case CH_1:
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            ADMUX |= CH_1;
        break;
        case CH_2:
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= CH_2;
        break;
        case CH_3:
            Pin_Init(&ADC_PORT, PIN_INPUT, 3);
            ADMUX |= CH_3;
        break;
        case CH_4:
            Pin_Init(&ADC_PORT, PIN_INPUT, 4);
            ADMUX |= CH_4;
        break;
        case CH_5:
            Pin_Init(&ADC_PORT, PIN_INPUT, 5);
            ADMUX |= CH_5;
        break;
        case CH_6:
            Pin_Init(&ADC_PORT, PIN_INPUT, 6);
            ADMUX |= CH_6;
        break;
        case CH_7:
            Pin_Init(&ADC_PORT, PIN_INPUT, 7);
            ADMUX |= CH_7;
        break;
        case CH_0_GAIN_10:
            Pin_Init(&ADC_PORT, PIN_INPUT, 0);
            ADMUX |= CH_0_GAIN_10;
        break;
        case CH_0_GAIN_200X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 0);
            ADMUX |= CH_0_GAIN_200X;
        break;
        case CH_1_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            ADMUX |= CH_1_GAIN_1X;
        break;
        case CH_2_GAIN_10X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= CH_2_GAIN_10X;
        break;
        case CH_2_GAIN_200X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= CH_2_GAIN_200X;
        break;
        case DIFF_CH_0_CH_1_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 0);
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            ADMUX |= DIFF_CH_0_CH_1_GAIN_1X;
        break;
        case DIFF_CH_0_CH_2_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 0);
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= DIFF_CH_0_CH_2_GAIN_1X;
        break;
        case DIFF_CH_1_CH_0_GAIN_10X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 0);
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            ADMUX |= DIFF_CH_1_CH_0_GAIN_10X;
        break;
        case DIFF_CH_1_CH_0_GAIN_200X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 0);
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            ADMUX |= DIFF_CH_1_CH_0_GAIN_200X;
        break;
        case DIFF_CH_1_CH_2_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= DIFF_CH_1_CH_2_GAIN_1X;
        break;
        case DIFF_CH_2_CH_1_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= DIFF_CH_2_CH_1_GAIN_1X;
        break;
        case DIFF_CH_2_CH_2_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= DIFF_CH_2_CH_2_GAIN_1X;
        break;
        case DIFF_CH_3_CH_1_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 3);
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            ADMUX |= DIFF_CH_3_CH_1_GAIN_1X;
        break;
        case DIFF_CH_3_CH_2_GAIN_10X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 3);
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= DIFF_CH_3_CH_2_GAIN_10X;
        break;
        case DIFF_CH_3_CH_2_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 3);
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= DIFF_CH_3_CH_2_GAIN_1X;
        break;
        case DIFF_CH_3_CH_2_GAIN_200X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 3);
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= DIFF_CH_3_CH_2_GAIN_200X;
        break;
        case DIFF_CH_4_CH_1_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 4);
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            ADMUX |= DIFF_CH_4_CH_1_GAIN_1X;
        break;
        case DIFF_CH_4_CH_2_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 4);
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= DIFF_CH_4_CH_2_GAIN_1X;
        break;
        case DIFF_CH_5_CH_1_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 5);
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            ADMUX |= DIFF_CH_5_CH_1_GAIN_1X;
        break;
        case DIFF_CH_5_CH_2_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 5);
            Pin_Init(&ADC_PORT, PIN_INPUT, 2);
            ADMUX |= DIFF_CH_5_CH_2_GAIN_1X;
        break;
        case DIFF_CH_6_CH_1_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 6);
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            ADMUX |= DIFF_CH_6_CH_1_GAIN_1X;
        break;
        case DIFF_CH_7_CH_1_GAIN_1X:
            Pin_Init(&ADC_PORT, PIN_INPUT, 7);
            Pin_Init(&ADC_PORT, PIN_INPUT, 1);
            ADMUX |= DIFF_CH_7_CH_1_GAIN_1X;
        break;
        case V_BG_1_22V:
            ADMUX |= V_BG_1_22V;
        break;
        case GND:
            ADMUX |= GND;
        break;
    }

    switch (adc_config->Ref_Voltage)
    {
        case AREF:
        ADMUX |=  ~( (1 << 6) | (1 << 6) );
        break;

        case AVCC:
            
            ADMUX |=  (1 << 6);
        break;
        case INTERNAL_2_56V:
            ADMUX |= (1 << 6) | (1 << 5);
        break;
    }


    ADMUX |= (1 << 5); // ADLAR == 1 by default for result left adjust enabled
    ADCSRA |= (1 << 7) | adc_config->Prescalar;
}


double ADC_Get_Raw_Value(){
    ADCSRA |= (1 << 6); // Start ADC Conversion
    while ( ( ADCSRA & (1 << 6) ) != 0);

    
    return ( (ADCL >>  6) | (ADCH << 2) );
}

uint16_t ADC_Get_MilliVolts(){
    ADCSRA |= (1 << 6); // Start ADC Conversion
    while ( ( ADCSRA & (1 << 6) ) != 0);

    return ( ( ( (ADCL >>  6) | (ADCH << 2) )* 5 ) / 1023.0 )* 1000;
}
