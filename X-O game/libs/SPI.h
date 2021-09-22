#include "config.h"
#include <stdint.h>
void SPI_Master_Inti();
void SPI_Write(uint8_t);
void SPI_Write_Char(char);

uint8_t SPI_Read();
void SPI_Slave_Init();
uint8_t SPI_Read();
void SPI_Read_String(uint8_t *, uint16_t);
