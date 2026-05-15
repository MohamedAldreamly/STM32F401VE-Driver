 /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GPIO_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 7/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401VE / Cortex-M4
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinMode(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
    if((Copy_GPIO == NULL) || (Copy_u8Pin > 15))
    {
        return;
    }

    CLR_2BIT_R(Copy_GPIO->MODER,Copy_u8Pin) ;   
    SET_2BIT_VALUE_R(Copy_GPIO->MODER,Copy_u8Pin,Copy_u8Mode); 

}

void GPIO_voidSetOutputType(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8Type)
{
    if((Copy_GPIO == NULL) || (Copy_u8Pin > 15))
    {
        return;
    }

    if(Copy_u8Type == GPIO_OPEN_DRAIN)
    {
        SET_BIT(Copy_GPIO->OTYPER, Copy_u8Pin);
    }
    else
    {
        CLR_BIT(Copy_GPIO->OTYPER, Copy_u8Pin);
    }
}

void GPIO_voidSetOutputSpeed(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8Speed)
{
    if((Copy_GPIO == NULL) || (Copy_u8Pin > 15))
    {
        return;
    }

    CLR_2BIT_R(Copy_GPIO->OSPEEDR,Copy_u8Pin) ;   
    SET_2BIT_VALUE_R(Copy_GPIO->OSPEEDR,Copy_u8Pin,Copy_u8Speed); 

}

void GPIO_voidSetPull(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8Pull)
{
    if((Copy_GPIO == NULL) || (Copy_u8Pin > 15))
    {
        return;
    }

    CLR_2BIT_R(Copy_GPIO->PUPDR,Copy_u8Pin) ;   
    SET_2BIT_VALUE_R(Copy_GPIO->PUPDR,Copy_u8Pin,Copy_u8Pull);

}

void GPIO_voidSetPinValue(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    if((Copy_GPIO == NULL) || (Copy_u8Pin > 15))
    {
        return;
    }

    if(Copy_u8Value == GPIO_HIGH)
    {
        Copy_GPIO->BSRR = (1 << Copy_u8Pin);
    }
    else
    {
        Copy_GPIO->BSRR = (1 << (Copy_u8Pin + 16));
    }
}

void GPIO_voidTogglePinValue(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin)
{
    if((Copy_GPIO == NULL) || (Copy_u8Pin > 15))
    {
        return;
    }

    TOG_BIT(Copy_GPIO->ODR, Copy_u8Pin);
}

void GPIO_voidGetPinValue(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8* Copy_u8Value)
{
    if((Copy_GPIO == NULL) || (Copy_u8Pin > 15) || (Copy_u8Value == NULL))
    {
        return;
    }

    *Copy_u8Value = GET_BIT(Copy_GPIO->IDR, Copy_u8Pin);
}

void GPIO_voidSetPinAF(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8AFSelection)
{
    
    if((Copy_GPIO == NULL) || (Copy_u8Pin > 15)|| (Copy_u8AFSelection > 15))
    {
        return;
    }
    GPIO_voidSetPinMode(Copy_GPIO,Copy_u8Pin, GPIO_ALTFN);
    if (Copy_u8Pin < 8)
    {
        CLR_4BIT_R(Copy_GPIO->AFRL ,Copy_u8Pin) ;
        SET_4BIT_VALUE_R(Copy_GPIO->AFRL,Copy_u8Pin,Copy_u8AFSelection) ;
    }

    else
    {
        
        CLR_4BIT_R(Copy_GPIO->AFRH ,(Copy_u8Pin-8)) ;
        SET_4BIT_VALUE_R(Copy_GPIO->AFRH,(Copy_u8Pin-8),Copy_u8AFSelection) ;
    }

}

