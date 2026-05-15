/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LED_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 5/8/2026
 *  Vertion : V01
 *  Layer   : HAL
 *
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


void LED_voidInit(LED_Type Copy_Config)
{
    //  if (Copy_Config == NULL)
    // {
    //     return;
    // }

    GPIO_voidSetPinMode(Copy_Config.Port, Copy_Config.Pin, GPIO_OUTPUT);
    GPIO_voidSetOutputType(Copy_Config.Port, Copy_Config.Pin, GPIO_PUSH_PULL);
    GPIO_voidSetOutputSpeed(Copy_Config.Port, Copy_Config.Pin, GPIO_LOW_SPEED);
    
    LED_voidTurnOff(Copy_Config);

}

void LED_voidTurnOn(LED_Type Copy_Config)
{
    // if (Copy_Config == NULL)
    // {
    //     return;
    // }
    if (Copy_Config.ActiveStatus == LED_ACTIVE_HIGH)
    {
        GPIO_voidSetPinValue(Copy_Config.Port, Copy_Config.Pin, GPIO_HIGH);
    }
    else if (Copy_Config.ActiveStatus == LED_ACTIVE_LOW)
    {
        GPIO_voidSetPinValue(Copy_Config.Port, Copy_Config.Pin, GPIO_LOW);
    }
}

void LED_voidTurnOff(LED_Type Copy_Config)
{
    // if (Copy_Config == NULL)
    // {
    //     return;
    // }
    if (Copy_Config.ActiveStatus == LED_ACTIVE_HIGH)
    {
        GPIO_voidSetPinValue(Copy_Config.Port, Copy_Config.Pin, GPIO_LOW);
    }
    else if (Copy_Config.ActiveStatus == LED_ACTIVE_LOW)
    {
        GPIO_voidSetPinValue(Copy_Config.Port, Copy_Config.Pin, GPIO_HIGH);
    }
}

void LED_voidToggle(LED_Type Copy_Config)
{
    GPIO_voidTogglePinValue(Copy_Config.Port, Copy_Config.Pin);
}