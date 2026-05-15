/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STK_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 14/5/2026
 *  Vertion : V01
 *  Layer   : MCAL
 *
 */  


#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#include "STD_TYPES.h"

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;

} STK_t;

#define STK ((volatile STK_t*)0xE000E010UL)

/* CTRL Register Bits */
#define STK_ENABLE_BIT        0
#define STK_TICKINT_BIT       1
#define STK_CLKSOURCE_BIT     2
#define STK_COUNTFLAG_BIT     16

#endif