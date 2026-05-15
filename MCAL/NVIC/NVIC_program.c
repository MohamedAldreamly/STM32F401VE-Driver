/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    NVIC_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> >
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 12/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401 / Cortex-M4
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_voidEnableInterrupt(u8 Copy_u8IRQNumber)
{
    if(Copy_u8IRQNumber < 240)
    {
        NVIC->ISER[Copy_u8IRQNumber / 32] = (1UL << (Copy_u8IRQNumber % 32));
    }
}


void NVIC_voidDisableInterrupt(u8 Copy_u8IRQNumber)
{
    if(Copy_u8IRQNumber < 240)
    {
        NVIC->ICER[Copy_u8IRQNumber / 32] = (1UL << (Copy_u8IRQNumber % 32));
    }
}



