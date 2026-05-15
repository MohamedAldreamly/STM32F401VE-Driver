/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    NVIC_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> >
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 12/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401 / Cortex-M4
 *
 */

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#include "STD_TYPES.h"

#define NVIC_BASE_ADDRESS   0xE000E100UL

typedef struct
{
    volatile u32 ISER[8];      /* Interrupt Set Enable Registers */
    volatile u32 RESERVED0[24];
    volatile u32 ICER[8];      /* Interrupt Clear Enable Registers */

} NVIC_t;

#define NVIC   ((volatile NVIC_t*)NVIC_BASE_ADDRESS)

#endif


