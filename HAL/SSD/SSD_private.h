/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SSD_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 5/7/2026
 *  Vertion : V01
 *  Layer   : HAL
 *
 */

#ifndef _SSD_PRIVATE_H_
#define _SSD_PRIVATE_H_

#include "STD_TYPES.h"

/*
 * Segment bit order:
 *      bit0 -> A
 *      bit1 -> B
 *      bit2 -> C
 *      bit3 -> D
 *      bit4 -> E
 *      bit5 -> F
 *      bit6 -> G
 */
static const u8 SSD_u8Digits[10] =
{
    0b00111111, /* 0 */
    0b00000110, /* 1 */
    0b01011011, /* 2 */
    0b01001111, /* 3 */
    0b01100110, /* 4 */
    0b01101101, /* 5 */
    0b01111101, /* 6 */
    0b00000111, /* 7 */
    0b01111111, /* 8 */
    0b01101111  /* 9 */
};


#endif //_SSD_PRIVATE_H_
