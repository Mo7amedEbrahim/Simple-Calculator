/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  Mohammed Gaafar        ***************************/
/*************                LAYER :   HAL			      ***************************/
/*************                SWC :     KPD	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/
#ifndef _KPD_H
#define _KPD_H

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/Error_States.h"
#include "KPD_cfg.h"

ES_t KPD_Init(void);


u8 KPD_u8GetPressedKey(void);

//	TODO : Try to make it abstract


#endif