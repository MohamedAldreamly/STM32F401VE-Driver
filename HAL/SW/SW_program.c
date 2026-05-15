/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SW_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 5/7/2026
 *  Vertion : V01
 *  Layer   : HAL
 *
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "STK_interface.h"   // util/delay

#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"


// u8 lastButtonState = GPIO_HIGH ;
//     u8 lastState = GPIO_HIGH ;
//     u8 currentButtonState = GPIO_HIGH ;
//     u8 currentButtonState1 = GPIO_HIGH ;
//     u8 currentButtonState2 = GPIO_HIGH ;

//     // u8 Local_u8State = SW_NOT_PRESSED ;
//     // u8 Local_u8PinState;
//     GPIO_voidSetPinValue(Copy_Config.Port, Copy_Config.Pin,lastState);


//     GPIO_voidGetPinValue(Copy_Config.Port, Copy_Config.Pin,&currentButtonState1);


//     while (1)
//     {
//         GPIO_voidGetPinValue(Copy_Config.Port, Copy_Config.Pin,&currentButtonState1);
//         for (u32 i =0 ; i <3000000 ; i++); 
//         GPIO_voidGetPinValue(Copy_Config.Port, Copy_Config.Pin,&currentButtonState2);
//         if (currentButtonState1 == currentButtonState2)
//         {
//             currentButtonState = currentButtonState1;
//             if (currentButtonState == GPIO_LOW)
//             {
//                 lastState = !lastState;
//                 GPIO_voidSetPinValue(Copy_Config.Port, Copy_Config.Pin,lastState);


//             }
//         }


void SW_voidInit(SW_t Copy_Config)
{
    
    GPIO_voidSetPinMode(Copy_Config.Port,Copy_Config.Pin,GPIO_INPUT);

    if (Copy_Config.SW_Type == SW_ACTIVE_HIGH)
    {    
        GPIO_voidSetPull(Copy_Config.Port,Copy_Config.Pin,GPIO_PULL_DOWN);
    }
    else if (Copy_Config.SW_Type == SW_ACTIVE_LOW)
    {    
        GPIO_voidSetPull(Copy_Config.Port,Copy_Config.Pin,GPIO_PULL_UP);
    }
    else 
    {    
        GPIO_voidSetPull(Copy_Config.Port,Copy_Config.Pin,GPIO_NO_PULL);
    }
}


u8 SW_u8GetState(SW_t Copy_Config)
{
    //u8 lastButtonState = SW_NOT_PRESSED ;
    u8 lastState = SW_NOT_PRESSED ;
    u8 currentButtonState = SW_NOT_PRESSED;
    u8 currentButtonState1 = SW_NOT_PRESSED ;
    u8 currentButtonState2 = SW_NOT_PRESSED ;

    GPIO_voidGetPinValue(Copy_Config.Port, Copy_Config.Pin,&currentButtonState1);

    if (Copy_Config.SW_Type == SW_ACTIVE_HIGH)
    {
        if (currentButtonState1 == SW_PRESSED)
        {
            //STK_voidDelayMs(SW_DEBOUNCE_TIME_MS);
            //for (volatile u32 i = 0 ; i >=1000000 ; i++);
            GPIO_voidGetPinValue(Copy_Config.Port,Copy_Config.Pin,&currentButtonState2);

            if (currentButtonState2 == currentButtonState1)
            {
                currentButtonState = SW_PRESSED;

                /*
                 * Wait until switch release.
                 */
                if (currentButtonState == SW_NOT_PRESSED)
                {
                lastState = !lastState;
                }
            }
        }

        return lastState;
    }

    /*
     * Active LOW switch logic.
     */
    else if (Copy_Config.SW_Type == SW_ACTIVE_LOW)
    {
        if (currentButtonState1 == SW_PRESSED)
        {
            
            //STK_voidDelayMs(SW_DEBOUNCE_TIME_MS);
            for (volatile u32 i = 0 ; i >=1000000 ; i++);

            GPIO_voidGetPinValue(Copy_Config.Port,
                               Copy_Config.Pin,
                               &currentButtonState2);

            if (currentButtonState1 == currentButtonState2)
            {
                currentButtonState = currentButtonState1;

                if (currentButtonState2 == currentButtonState1)
                {
                currentButtonState = SW_PRESSED;

                /*
                 * Wait until switch release.
                 */
                if (currentButtonState == SW_NOT_PRESSED)
                {
                lastState = SW_PRESSED;
                }
                }

            return lastState;
            }
        }
    }
    return SW_NOT_PRESSED;
}
