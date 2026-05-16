/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GPIO_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 14/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401VE / Cortex-M4
 *
 */

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "GPIO_private.h"



/* Modes MODER Register  */
#define GPIO_INPUT          0b00
#define GPIO_OUTPUT         0b01
#define GPIO_ALTFN          0b10
#define GPIO_ANALOG         0b11


/* Output Types Register GPIOx_OTYPER */

#define GPIO_PUSH_PULL      0
#define GPIO_OPEN_DRAIN     1

/* Output Speed Register GPIOx_OSPEEDR */

#define GPIO_LOW_SPEED      0b00
#define GPIO_MEDIUM_SPEED   0b01
#define GPIO_FAST_SPEED     0b10
#define GPIO_HIGH_SPEED     0b11

/* Pull Config GPIOx_PUPDR */
#define GPIO_NO_PULL        0b00
#define GPIO_PULL_UP        0b01
#define GPIO_PULL_DOWN      0b10

/* Pin values */
#define GPIO_HIGH 1
#define GPIO_LOW  0

/* Pins */
#define GPIO_PIN0   0
#define GPIO_PIN1   1
#define GPIO_PIN2   2
#define GPIO_PIN3   3
#define GPIO_PIN4   4
#define GPIO_PIN5   5
#define GPIO_PIN6   6
#define GPIO_PIN7   7
#define GPIO_PIN8   8
#define GPIO_PIN9   9
#define GPIO_PIN10  10
#define GPIO_PIN11  11
#define GPIO_PIN12  12
#define GPIO_PIN13  13
#define GPIO_PIN14  14
#define GPIO_PIN15  15

//  AFRL Register     
#define GPIO_AF_0   0b0000
#define GPIO_AF_1   0b0001
#define GPIO_AF_2   0b0010
#define GPIO_AF_3   0b0011
#define GPIO_AF_4   0b0100
#define GPIO_AF_5   0b0101
#define GPIO_AF_6   0b0110
#define GPIO_AF_7   0b0111

// AFRH Register 
#define GPIO_AF_8   0b1000
#define GPIO_AF_9   0b1001
#define GPIO_AF_10  0b1010
#define GPIO_AF_11  0b1011
#define GPIO_AF_12  0b1100
#define GPIO_AF_13  0b1101
#define GPIO_AF_14  0b1110
#define GPIO_AF_15  0b1111


void GPIO_voidSetPinMode(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8Mode);
void GPIO_voidSetOutputType(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8Type);
void GPIO_voidSetOutputSpeed(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8Speed);
void GPIO_voidSetPull(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8Pull);

void GPIO_voidSetPinValue(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8Value);
void GPIO_voidTogglePinValue(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin);
void GPIO_voidGetPinValue(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8* Copy_u8Value);

void GPIO_voidSetPinAF(GPIO_Typedef* Copy_GPIO, u8 Copy_u8Pin, u8 Copy_u8AFSelection);
#endif
