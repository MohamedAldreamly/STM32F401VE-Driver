/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GPIO_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 7/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401 / Cortex-M4
 *
 */


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

typedef struct
{
    volatile u32 MODER;     
    volatile u32 OTYPER;    
    volatile u32 OSPEEDR;   
    volatile u32 PUPDR;     
    volatile u32 IDR;       
    volatile u32 ODR;       
    volatile u32 BSRR;      
    volatile u32 LCKR;      
    volatile u32 AFRL;      
    volatile u32 AFRH;      

} GPIO_Typedef;

/* STM32F401 GPIO Base Addresses */
#define GPIOA ((GPIO_Typedef*)0x40020000)
#define GPIOB ((GPIO_Typedef*)0x40020400)
#define GPIOC ((GPIO_Typedef*)0x40020800)
#define GPIOD ((GPIO_Typedef*)0x40020C00)
#define GPIOE ((GPIO_Typedef*)0x40021000)
#define GPIOH ((GPIO_Typedef*)0x40021C00)


#endif
