/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 5/7/2026
 *  Vertion : V01
 *  Layer   : HAL
 *
 */

#ifndef _KPD_PRIVATE_H_
#define _KPD_PRIVATE_H_

/*
 * Default keypad mapping.
 *
 * Row x Column
 */
static const u8 KPD_u8Keys[4][3] =
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

#endif //_KPD_PRIVATE_H_
