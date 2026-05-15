/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STK_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 14/5/2026
 *  Vertion : V01
 *  Layer   : MCAL
 *
 */  

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


void STK_voidInit(void)
{
    /* Disable SysTick */
    CLR_BIT(STK->CTRL, STK_ENABLE_BIT);

    /* Select Processor Clock (AHB) */
    SET_BIT(STK->CTRL, STK_CLKSOURCE_BIT);

    /* Disable Interrupt */
    CLR_BIT(STK->CTRL, STK_TICKINT_BIT);
}

void STK_voidDelayMs(u32 Copy_u32TimeMs)
{
    while (Copy_u32TimeMs--)
    {
        STK->LOAD = 84000 - 1;
        STK->VAL  = 0;

    /* Start timer */
        SET_BIT(STK->CTRL, STK_ENABLE_BIT);

        while (!(GET_BIT(STK->CTRL, STK_COUNTFLAG_BIT)));

        CLR_BIT(STK->CTRL, STK_ENABLE_BIT);
        /* Clear registers */
        STK->LOAD = 0;
        STK->VAL  = 0;
    }
}

