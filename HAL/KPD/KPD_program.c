/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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
#include "STK_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

static void KPD_voidEnableGPIOClock(GPIO_Typedef* Copy_Port)
{
    if (Copy_Port == GPIOA)
    {
        RCC_voidEnablePeripheralClock(RCC_AHB1_BUS, RCC_GPIOA);
    }
    else if (Copy_Port == GPIOB)
    {
        RCC_voidEnablePeripheralClock(RCC_AHB1_BUS, RCC_GPIOB);
    }
    else if (Copy_Port == GPIOC)
    {
        RCC_voidEnablePeripheralClock(RCC_AHB1_BUS, RCC_GPIOC);
    }
    else
    {
        
    }
}

void KPD_voidInit(KPD_t Copy_Config)
{
    u8 i; 
    for( i = 0; i < KPD_ROWS_NUM; i++)
    {
        KPD_voidEnableGPIOClock(Copy_Config.RowPort[i]);

        GPIO_voidSetPinMode(Copy_Config.RowPort[i],
                            Copy_Config.RowPin[i],
                            GPIO_OUTPUT);

        GPIO_voidSetOutputType(Copy_Config.RowPort[i],
                               Copy_Config.RowPin[i],
                               GPIO_PUSH_PULL);

        GPIO_voidSetOutputSpeed(Copy_Config.RowPort[i],
                                Copy_Config.RowPin[i],
                                GPIO_LOW_SPEED);
        /*
         * Idle state HIGH.
         */
        GPIO_voidSetPinValue(Copy_Config.RowPort[i],
                             Copy_Config.RowPin[i],
                             GPIO_HIGH);
    }
    /*
     * Configure columns as input pull-up.
     */
    for( i = 0; i < KPD_COLS_NUM; i++)
    {
        KPD_voidEnableGPIOClock(Copy_Config.ColPort[i]);

        GPIO_voidSetPinMode(Copy_Config.ColPort[i],
                            Copy_Config.ColPin[i],
                            GPIO_INPUT);

        GPIO_voidSetPull(Copy_Config.ColPort[i],
                         Copy_Config.ColPin[i],
                         GPIO_PULL_UP);
    }
}

u8 KPD_u8GetPressedKey(KPD_t Copy_Config)
{
    u8 row, col;
    u8 Local_u8PinState;
    u8 Local_u8Key = KPD_NO_PRESSED_KEY;

    for(row = 0; row < KPD_ROWS_NUM; row++)
    {
        /*
         * Activate current row.
         */
        GPIO_voidSetPinValue(Copy_Config.RowPort[row],
                             Copy_Config.RowPin[row],
                             GPIO_LOW);

        for(col = 0; col < KPD_COLS_NUM; col++)
        {
            GPIO_voidGetPinValue(Copy_Config.ColPort[col],
                               Copy_Config.ColPin[col],
                               &Local_u8PinState);

            /*
             * Key pressed.
             */
            if(Local_u8PinState == GPIO_LOW)
            {
                STK_voidDelayMs(KPD_DEBOUNCE_TIME_MS);

                GPIO_voidGetPinValue(Copy_Config.ColPort[col],
                                   Copy_Config.ColPin[col],
                                   &Local_u8PinState);

                if(Local_u8PinState == GPIO_LOW)
                {
                    Local_u8Key = KPD_u8Keys[row][col];

                    /*
                     * Wait until release.
                     */
                    while(Local_u8PinState == GPIO_LOW)
                    {
                        GPIO_voidGetPinValue(Copy_Config.ColPort[col],
                                           Copy_Config.ColPin[col],
                                           &Local_u8PinState);
                    }
                }
            }
        }

        /*
         * Deactivate current row.
         */
        GPIO_voidSetPinValue(Copy_Config.RowPort[row],
                             Copy_Config.RowPin[row],
                             GPIO_HIGH);
    }

    return Local_u8Key;
}
