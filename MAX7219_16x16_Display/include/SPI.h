#ifndef SPI_H
#define SPI_H

typedef enum{
    CPU_FREQ_4,
    CPU_FREQ_16,
    CPU_FREQ_64,
    CPU_FREQ_128,
    CPU_FREQ_2,
    CPU_FREQ_8,
    CPU_FREQ_32,
}SCK_select;

typedef enum{
    LSB_FIRST,
    MSB_FIRST
}Data_Ord;

typedef enum{
    SPI_MASTER,
    SPI_SLAVE
}SPI_Role;

typedef struct {
    SPI_Role Device_Role;
    uint8_t CS_PIN;
    SCK_select SCK_Freq;
    Data_Ord Data_Order;
}SPI_Config_t;

void SPI_Master_Init(SPI_Config_t *SPI_Config);
void SPI_Master_Tx(uint8_t data);
void SPI_Master_Write_Register(uint8_t Address, uint8_t Data);
void SPI_CS_HIGH(SPI_Config_t *SPI_Config);
void SPI_CS_LOW(SPI_Config_t *SPI_Config);

#endif