#ifndef ADC_H
#define ADC_H

typedef enum {
    CH_0,
    CH_1,
    CH_2,
    CH_3,
    CH_4,
    CH_5,
    CH_6,
    CH_7,
    CH_0_GAIN_10,
    DIFF_CH_1_CH_0_GAIN_10X,
    CH_0_GAIN_200X,
    DIFF_CH_1_CH_0_GAIN_200X,
    CH_2_GAIN_10X,
    DIFF_CH_3_CH_2_GAIN_10X,
    CH_2_GAIN_200X,
    DIFF_CH_3_CH_2_GAIN_200X,
    DIFF_CH_0_CH_1_GAIN_1X,
    CH_1_GAIN_1X,
    DIFF_CH_2_CH_1_GAIN_1X,
    DIFF_CH_3_CH_1_GAIN_1X,
    DIFF_CH_4_CH_1_GAIN_1X,
    DIFF_CH_5_CH_1_GAIN_1X,
    DIFF_CH_6_CH_1_GAIN_1X,
    DIFF_CH_7_CH_1_GAIN_1X,
    DIFF_CH_0_CH_2_GAIN_1X,
    DIFF_CH_1_CH_2_GAIN_1X,
    DIFF_CH_2_CH_2_GAIN_1X,
    DIFF_CH_3_CH_2_GAIN_1X,
    DIFF_CH_4_CH_2_GAIN_1X,
    DIFF_CH_5_CH_2_GAIN_1X,
    V_BG_1_22V,
    GND
}ADC_Chnannel;

typedef enum{
    AREF,
    AVCC,
    INTERNAL_2_56V = 3
}V_Ref_Select;

typedef enum{
    CLK_2 = 1,
    CLK_4,
    CLK_8,
    CLK_16,
    CLK_32,
    CLK_64,
    CLK_128,
}ADC_Prescalar;

typedef struct {
    ADC_Chnannel Channel;
    V_Ref_Select Ref_Voltage;
    // ADLAR to be selected as Left Adjusted by default
    ADC_Prescalar Prescalar;



}ADC_Config_t;

void ADC_Init(ADC_Config_t *adc_config);
double ADC_Get_Raw_Value();
uint16_t ADC_Get_MilliVolts();


#endif