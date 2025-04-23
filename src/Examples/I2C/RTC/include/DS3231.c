#include <avr/io.h>
#include <avr/iom32.h>

#include "I2C.h"
#include "DS3231.h"



void DS3231_Init(){
    I2C_Master_Init();
}

void DS3231_Set_Time(RTC_Config_t *rtc_config, RTC_Data_Format *time_configuration){
    if(rtc_config->DS3231_I2C_ADDRESS == 0){
        rtc_config->DS3231_I2C_ADDRESS = 0x68;    
    }

    I2C_Start();
    I2C_Write((rtc_config->DS3231_I2C_ADDRESS << 1) + 0x0);  
    I2C_Write(DS3231_CLK_REG);             

    // Write time values in BCD Format
    I2C_Write(dec_to_bcd(time_configuration->seconds));
    I2C_Write(dec_to_bcd(time_configuration->minutes));
    I2C_Write(dec_to_bcd(time_configuration->hours));
    I2C_Write(dec_to_bcd(time_configuration->Day_Of_Week));
    I2C_Write(dec_to_bcd(time_configuration->Date));
    I2C_Write(dec_to_bcd(time_configuration->Month));
    I2C_Write(dec_to_bcd(time_configuration->Year));

    I2C_Stop();  // End transaction
}

void DS3231_Get_Time(RTC_Config_t *rtc_config, RTC_Data_Format *Return_Format){
    uint8_t rtc_buffer[7];
    I2C_Start();
    I2C_Write((rtc_config->DS3231_I2C_ADDRESS << 1) + 0x0);
    I2C_Write(DS3231_CLK_REG);
    I2C_Stop();

    I2C_Start();
    I2C_Write((rtc_config->DS3231_I2C_ADDRESS << 1) + 0x1);
    I2C_Read_Multiple(7, rtc_buffer);
    I2C_Stop();

    Return_Format->Year         = rtc_buffer[6];
    Return_Format->Month        = rtc_buffer[5] & 0x1f;
    Return_Format->Date         = rtc_buffer[4];
    Return_Format->Day_Of_Week  = rtc_buffer[3] & 0x3f;
    Return_Format->hours        = rtc_buffer[2];
    Return_Format->minutes      = rtc_buffer[1];
    Return_Format->seconds      = rtc_buffer[0];
}

uint8_t dec_to_bcd(uint8_t val) {
    return ((val / 10) << 4) | (val % 10);
}
uint8_t bcd_to_dec(uint8_t val) {
    return ((val >> 4) * 10) + (val & 0x0F);
}