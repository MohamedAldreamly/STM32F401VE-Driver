/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 5/7/2026
 *  Vertion : V01
 *  Layer   : HAL
 *
 *  STM32F401 Update:
 *  ----------------
 *  This keypad driver now uses STM32F4 GPIO APIs.
 *
 */

#ifndef _KPD_INTERFACE_H_
#define _KPD_INTERFACE_H_

#include "STD_TYPES.h"
#include "GPIO_interface.h"

#define KPD_ROWS_NUM 4
#define KPD_COLS_NUM 3 

#define KPD_NO_PRESSED_KEY   0xFFU

typedef struct
{
    GPIO_Typedef* RowPort[KPD_ROWS_NUM];
    u8 RowPin[KPD_ROWS_NUM];

    GPIO_Typedef* ColPort[KPD_COLS_NUM];
    u8 ColPin[KPD_COLS_NUM];

} KPD_t;


void KPD_voidInit(KPD_t Copy_Config);

u8 KPD_u8GetPressedKey(KPD_t Copy_Config);

#endif //_KPD_INTERFACE_H_
