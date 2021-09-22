#include <xc.h>
#include "libs/config.h"
#include "libs/Nokia5110.h"
#include "libs/keypad.h"
char arr[9];
void display();
uint8_t from_char_to_num(char num);
char Key;
uint8_t numKey, turn, move;
char sign;

uint8_t i;
void computerTurn();
void myTurn();
uint8_t checkResult();
char from_num_to_char(uint8_t num);
int main()
{
    LCD_Init();
    keyinit();
    uint8_t result;
   
    while (1)
    {
         for (i = 0; i < 9; i++)
    {
        arr[i] = '0' + (i + 1);
    }

        i = 0;
        do
        {
            LCD_clear();
            display();
            __delay_ms(1000);

            turn = (i % 2) ? 1 : 2;

            if (turn == 1)
            {
                sign = 'X';
                myTurn();
            }
            else if (turn == 2)
            {
                sign = 'O';
                computerTurn();
            }
            i++;
            result = checkResult();
            __delay_ms(500);
        } while (result == 2);
        if (result == 1)
        {

            LCD_clear();
            LCD_setCursor(0, 0);
            LCD_print_string("winner ");
            char lol = from_num_to_char((i - 1)%2);
            LCD_print_char(lol);
            __delay_ms(5000);
        }
        else if (result == 0)
        {
            LCD_clear();
            LCD_setCursor(0, 0);
            LCD_print_string("DRAW");
            __delay_ms(5000);
        }
         LCD_clear();
            LCD_setCursor(0, 0);
            LCD_print_string("play agin?");
            LCD_setCursor(0, 1);
            LCD_print_string("press 1");
            Key=key();
           
        if(Key == '1'){
             LCD_clear();
            LCD_setCursor(0, 0);
            LCD_print_string("nice");
        }
        else{
             LCD_clear();
            LCD_setCursor(0, 0);
            LCD_print_string("sad :(");
            Key=key();
        }
    }

    // move = 1;
}
void display()
{

    LCD_setCursor(0, 0);
    LCD_print_char(arr[0]);
    LCD_setCursor(10, 0);
    LCD_print_char('|');
    LCD_setCursor(20, 0);
    LCD_print_char(arr[1]);
    LCD_setCursor(30, 0);
    LCD_print_char('|');
    LCD_setCursor(40, 0);
    LCD_print_char(arr[2]);
    LCD_setCursor(0, 1);
    LCD_print_char(arr[3]);
    LCD_setCursor(10, 1);
    LCD_print_char('|');
    LCD_setCursor(20, 1);
    LCD_print_char(arr[4]);
    LCD_setCursor(30, 1);
    LCD_print_char('|');
    LCD_setCursor(40, 1);
    LCD_print_char(arr[5]);
    LCD_setCursor(0, 2);
    LCD_print_char(arr[6]);
    LCD_setCursor(10, 2);
    LCD_print_char('|');
    LCD_setCursor(20, 2);
    LCD_print_char(arr[7]);
    LCD_setCursor(30, 2);
    LCD_print_char('|');
    LCD_setCursor(40, 2);
    LCD_print_char(arr[8]);
}
void myTurn()
{
    LCD_setCursor(0, 4);
    LCD_print_string("X turn");
    Key = key();
    numKey = from_char_to_num(Key);
    //  arr[numKey - 1] = sign;
    if (numKey == 1 && arr[0] == '1')
        arr[0] = sign;

    else if (numKey == 2 && arr[1] == '2')
        arr[1] = sign;

    else if (numKey == 3 && arr[2] == '3')
        arr[2] = sign;

    else if (numKey == 4 && arr[3] == '4')
        arr[3] = sign;

    else if (numKey == 5 && arr[4] == '5')
        arr[4] = sign;

    else if (numKey == 6 && arr[5] == '6')
        arr[5] = sign;

    else if (numKey == 7 && arr[6] == '7')
        arr[6] = sign;

    else if (numKey == 8 && arr[7] == '8')
        arr[7] = sign;

    else if (numKey == 9 && arr[8] == '9')
        arr[8] = sign;

    else
    {
        LCD_setCursor(0, 4);
        LCD_print_string("Error");
        __delay_ms(1000);
        --i;
    }
}
void computerTurn()
{
    if (arr[0] == '1' && arr[1] == sign && arr[2] == sign)
        arr[0] = sign;

    else if (arr[1] == '2' && arr[0] == sign && arr[2] == sign)
        arr[1] = sign;
        

    else if (arr[2] == '3' && arr[1] == sign && arr[0] == sign)
        arr[2] = sign;

    else if (arr[3] == '4' && arr[4] == sign && arr[5] == sign)
        arr[3] = sign;

    else if (arr[4] == '5' && arr[3] == sign && arr[5] == sign)
        arr[4] = sign;

    else if (arr[5] == '6' && arr[3] == sign && arr[4] == sign)
        arr[5] = sign;

    else if (arr[6] == '7' && arr[8] == sign && arr[9] == sign)
        arr[6] = sign;

    else if (arr[7] == '8' && arr[6] == sign && arr[8] == sign)
        arr[7] = sign;

    else if (arr[8] == '9' && arr[7] == sign && arr[6] == sign)
        arr[8] = sign;

    else if (arr[0] == '1' && arr[4] == sign && arr[8] == sign)
        arr[0] = sign;

    else if (arr[4] == '5' && arr[0] == sign && arr[8] == sign)
        arr[1] = sign;

    else if (arr[8] == '9' && arr[4] == sign && arr[0] == sign)
        arr[8] = sign;

    else if (arr[2] == '3' && arr[4] == sign && arr[6] == sign)
        arr[2] = sign;

    else if (arr[4] == '5' && arr[2] == sign && arr[6] == sign)
        arr[4] = sign;

    else if (arr[6] == '7' && arr[4] == sign && arr[2] == sign)
        arr[6] = sign;

    else if (arr[0] == '1' && arr[3] == sign && arr[6] == sign)
        arr[0] = sign;

    else if (arr[3] == '4' && arr[0] == sign && arr[6] == sign)
        arr[3] = sign;

    else if (arr[6] == '7' && arr[3] == sign && arr[2] == sign)
        arr[6] = sign;

    else if (arr[1] == '2' && arr[4] == sign && arr[7] == sign)
        arr[1] = sign;

    else if (arr[4] == '5' && arr[1] == sign && arr[7] == sign)
        arr[4] = sign;

    else if (arr[7] == '8' && arr[1] == sign && arr[4] == sign)
        arr[7] = sign;

    else if (arr[2] == '3' && arr[5] == sign && arr[8] == sign)
        arr[2] = sign;

    else if (arr[5] == '6' && arr[2] == sign && arr[9] == sign)
        arr[5] = sign;

    else if (arr[8] == '9' && arr[3] == sign && arr[5] == sign)
        arr[8] = sign;

    else if (arr[0] == '1' && arr[1] == '2' && arr[2] == sign)
        arr[0] = sign;

    else if (arr[2] == '3' && arr[1] == '2' && arr[0] == sign)
        arr[2] = sign;

    else if (arr[0] == '1' && arr[2] == '3' && arr[1] == sign)
        arr[0] = sign;

    else if (arr[3] == '4' && arr[4] == '5' && arr[5] == sign)
        arr[3] = sign;

    else if (arr[3] == '4' && arr[5] == '6' && arr[4] == sign)
        arr[3] = sign;

    else if (arr[5] == '6' && arr[4] == '5' && arr[5] == sign)
        arr[5] = sign;

    else if (arr[6] == '7' && arr[7] == '8' && arr[8] == sign)
        arr[6] = sign;

    else if (arr[6] == '7' && arr[8] == '9' && arr[7] == sign)
        arr[6] = sign;

    else if (arr[7] == '8' && arr[8] == '9' && arr[6] == sign)
        arr[7] = sign;

    else if (arr[0] == '1' && arr[3] == '4' && arr[6] == sign)
        arr[0] = sign;

    else if (arr[0] == '1' && arr[6] == '7' && arr[3] == sign)
        arr[0] = sign;

    else if (arr[6] == '7' && arr[3] == '4' && arr[0] == sign)
        arr[6] = sign;

    else if (arr[0] == '1' && arr[1] == '2' && arr[2] == sign)
        arr[0] = sign;

    else if (arr[1] == '2' && arr[4] == '5' && arr[7] == sign)
        arr[1] = sign;

    else if (arr[1] == '2' && arr[7] == '8' && arr[4] == sign)
        arr[1] = sign;

    else if (arr[5] == '6' && arr[8] == '9' && arr[2] == sign)
        arr[5] = sign;

    else if (arr[2] == '3' && arr[5] == '6' && arr[8] == sign)
        arr[2] = sign;

    else if (arr[2] == '3' && arr[8] == '9' && arr[5] == sign)
        arr[2] = sign;

    else if (arr[0] == '1' && arr[4] == '5' && arr[8] == sign)
        arr[0] = sign;

    else if (arr[0] == '1' && arr[8] == '9' && arr[4] == sign)
        arr[0] = sign;

    else if (arr[8] == '9' && arr[4] == '5' && arr[0] == sign)
        arr[8] = sign;

    else if (arr[2] == '3' && arr[4] == '5' && arr[6] == sign)
        arr[2] = sign;

    else if (arr[2] == '3' && arr[6] == '7' && arr[4] == sign)
        arr[2] = sign;

    else if (arr[6] == '7' && arr[4] == '5' && arr[2] == sign)
        arr[6] = sign;

    else if (arr[0] == '1')
        arr[0] = sign;

    else if (arr[1] == '2')
        arr[1] = sign;

    else if (arr[2] == '3')
        arr[2] = sign;

    else if (arr[3] == '4')
        arr[3] = sign;

    else if (arr[4] == '5')
        arr[4] = sign;

    else if (arr[5] == '6')
        arr[5] = sign;

    else if (arr[6] == '7')
        arr[6] = sign;

    else if (arr[7] == '8')
        arr[7] = sign;

    else if (arr[8] == '9')
        arr[8] = sign;

    else
    {
        LCD_setCursor(0, 4);
        LCD_print_string("wrong input");
        i--;
    }
}
uint8_t checkResult()
{
    if (arr[0] == arr[1] && arr[0] == arr[2])
        return 1;
    else if (arr[3] == arr[4] && arr[3] == arr[5])
        return 1;
    else if (arr[6] == arr[7] && arr[6] == arr[8])
        return 1;
    else if (arr[0] == arr[3] && arr[0] == arr[6])
        return 1;
    else if (arr[1] == arr[4] && arr[1] == arr[7])
        return 1;
    else if (arr[2] == arr[5] && arr[2] == arr[8])
        return 1;
    else if (arr[2] == arr[4] && arr[2] == arr[6])
        return 1;
    else if (arr[0] == arr[4] && arr[0] == arr[8])
        return 1;
    else if (arr[0] != '1' && arr[1] != '2' && arr[2] != '3' && arr[3] != '4' && arr[4] != '5' && arr[5] != '6' && arr[6] != '7' && arr[7] != '8' && arr[8] != '9')
        return 0;
    else
        return 2;
}
uint8_t from_char_to_num(char num)
{
    return (num - '0');
}
char from_num_to_char(uint8_t num)
{
    return (num + '0');
}