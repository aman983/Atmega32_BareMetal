#ifndef I2C_H
#define I2C_h

void I2C_Master_Init();
void I2C_Start();
void I2C_Stop();
void I2C_Write(char data);
void I2C_Read_Multiple(int n, uint8_t *buffer);



#endif