#include "Nokia5110.h"
void LCD_command(char x)
{
    DC = 0;
    SPI_Write_Char(x);
  
}
void LCD_data(char x)
{
    DC = 1;
    SPI_Write_Char(x);
   
}
void LCD_setCursor(uint8_t x, uint8_t y)
{
    LCD_SetX(x);
    LCD_SetY(y);
    DC = 1;
}
void LCD_SetY(uint8_t y)
{
    LCD_command(0x40 | y);
}
void LCD_SetX(uint8_t x)
{
    LCD_command(0x80 | x);
}

void LCD_Init()
{
    
    TRISC = 0;
    SPI_Master_Inti();
    //make a reset
    RES = 0;
    RES = 1;
    LCD_command(FUNCTION_SET | EXTENDED_INSTRUCTION);
    //set bias
    LCD_command(SET_BIAS | 0x04);
    //set contrust
    LCD_command(SET_VOP | 40);
    LCD_command(FUNCTION_SET);
    LCD_command(DISPLAY_CONTROL_NORMAL_MODE | DISPLAY_CONTROL);

    // the 0 ,0 position 
    LCD_SetX(0);
    LCD_SetY(0);
    DC = 1;
}
void LCD_clear()
{
    for (int i = 0; i < (LCD_WIDTH * LCD_HIGHT / 8); i++)
    {
        LCD_data(0x00);
    }
}
void LCD_print_char(char data)
{
    LCD_data(0x00);
    for (int i = 0; i < 5; i++)
    {
        LCD_data(ASCII[data - 0x20][i]);
    }
}
void LCD_print_string(char *chr)
{
    LCD_data(0x00);
    while (*chr)
    {
        LCD_print_char(*chr++);
        
    }
}
