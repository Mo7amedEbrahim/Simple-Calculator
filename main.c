/*
 * main.c
 *
 *  Created on: Feb , 20 , 2023
 *      Author: Mohammed Gaafar
 */
#include "APP/APP.h"
#include <util/delay.h>
s8 Buffer[10];
int main (void){
    KPD_Init();
    LCD_4BitInitialize();
    s16 Num1=0,Num2=0,Result=0;
    u8 Operator =0,Buffer_Idx=0;
    u8 Minus_Flag=0;
    		LCD_GoToXY4Bit(3,0);
        	LCD_WriteString4Bit("Calculator");
        	_delay_ms(2000);
        	LCD_ClearDisplay4Bit();
    while(1){

        u8 Key = GetKey();
        if((Key >= '0' && Key <= '9') || (Key == '-' && Minus_Flag == 0)){
            Buffer[Buffer_Idx++] = Key;
            LCD_WriteData4Bit(Key);
            Minus_Flag =1;
        }
        else if(Key == '+' || (Key == '-' && Minus_Flag == 1 )|| Key == '*' || Key == '/' ){
            Num1 = StrToInt(Buffer);
            Minus_Flag = 0;
            Buffer_Idx = 0;
            SetArrToZero(Buffer);
            Operator = Key;
            LCD_WriteData4Bit(Key);
        }
        else if(Key == '='){
            Num2 = StrToInt(Buffer);
            Buffer_Idx = 0;
            SetArrToZero(Buffer);
            switch(Operator){
                case '+': Result = Num1+Num2;   break;
                case '-': Result = Num1-Num2;   break;
                case '*': Result = Num1*Num2;   break;
                case '/': Result = Num1/Num2;   break;
            }
            LCD_GoToXY4Bit(10,1);
            LCD_WriteData4Bit('=');
            LCD_WriteNumber4Bit(Result);
        }
        else if(Key == 'E'){
        	LCD_ClearDisplay4Bit();
        	SetArrToZero(Buffer);
        	Buffer_Idx = 0;
        	Num1=0;Num2=0;Operator=0;
        }
    }
}
