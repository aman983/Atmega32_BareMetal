#ifndef DS3231_H
#define DS3231_H

#define DS3231_CLK_REG  0x00

typedef struct {
    char seconds;
    char minutes;
    char hours;
    char Day_Of_Week;
    char Date;
    char Month;
    char Year;
}RTC_Data_Format;

typedef struct {
    uint8_t DS3231_I2C_ADDRESS;
}RTC_Config_t;

void DS3231_Init();

void DS3231_Set_Time(RTC_Config_t *rtc_config, RTC_Data_Format *time_configuration);

void DS3231_Get_Time(RTC_Config_t *rtc_config, RTC_Data_Format *Return_Format);

uint8_t dec_to_bcd(uint8_t val);
uint8_t bcd_to_dec(uint8_t val);

#endif