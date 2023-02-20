/*
 * main.c
 *
 *  Created on: Feb , 20 , 2023
 *      Author: Mohammed Gaafar
 */

#include "APP.h"


s16 StrToInt(const s8 *str) {
    s16 res = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + (str[i] - '0');
        }
        else {
            break;
        }
    }

    return sign * res;
}

void SetArrToZero(s8 *Copy_Array){
    u8 i=0;
    while(*(Copy_Array+i) != '\0'){
        *(Copy_Array+i) = 0;
        i++;
    }
}

u8 GetKey(void){
	u8 x =0xff;
	while(x == 0xff){
		x = KPD_u8GetPressedKey();
	}
	return x;
}
