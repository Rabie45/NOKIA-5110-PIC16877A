#include <xc.h>
#include "libs/config.h"
#include "libs/SPI.h"
#include "libs/Nokia5110.h"

int main()
{
    LCD_Init();
    LCD_clear();
    LCD_setCursor(0,0);
    LCD_print_char('H');
    LCD_setCursor(1,2);
    LCD_print_string("fuck u");
    __delay_ms(1000);
    LCD_clear();
    while (1)
    {
        /* code */
    }
    
}


