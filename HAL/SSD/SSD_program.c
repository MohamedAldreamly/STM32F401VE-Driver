/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SSD_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"


// in main 

// SSD_Config_t SSD1 = {
//     .Port = {GPIOA , GPIOA , GPIOA , GPIOA , GPIOA , GPIOA , GPIOA , GPIOA},
//     .Pin  = {GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7},
//     .SSD_Type = SSD_COMMON_CATHODE,
// };


static void SSD_voidEnableGPIOClock(GPIO_Typedef* Copy_Port)
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


void SSD_voidInit(SSD_Config_t Copy_Config)
{
    u8 Local_u8Iterator;

    /*
     * Enable GPIO clock for all used segment pins.
     *
     * Note:
     * -----
     * Re-enabling the same clock more than once is safe.
     */
    for (Local_u8Iterator = 0; Local_u8Iterator < SSD_TOTAL_PINS; Local_u8Iterator++)
    {
        SSD_voidEnableGPIOClock(Copy_Config.Port[Local_u8Iterator]);
    }

    /*
     * Configure all SSD pins as output push-pull.
     */
    for (Local_u8Iterator = 0; Local_u8Iterator < SSD_TOTAL_PINS; Local_u8Iterator++)
    {
        GPIO_voidSetPinMode(Copy_Config.Port[Local_u8Iterator],
                            Copy_Config.Pin[Local_u8Iterator],
                            GPIO_OUTPUT);

        GPIO_voidSetOutputType(Copy_Config.Port[Local_u8Iterator],
                               Copy_Config.Pin[Local_u8Iterator],
                               GPIO_PUSH_PULL);

        GPIO_voidSetOutputSpeed(Copy_Config.Port[Local_u8Iterator],
                                Copy_Config.Pin[Local_u8Iterator],
                                GPIO_LOW_SPEED);

    }

    /*
     * Start from a clean state:
     *      segments off
     *      SSD disabled
     */
    SSD_voidClear(Copy_Config);
    SSD_voidDisable(Copy_Config);
}


void SSD_voidDisplay(SSD_Config_t Copy_Config, u8 Copy_u8Number)
{
    u8 Local_u8Iterator;
    u8 Local_u8BitValue;

    if (Copy_u8Number < 10U)
    {
        for (Local_u8Iterator = 0; Local_u8Iterator < SSD_SEGMENT_COUNT; Local_u8Iterator++)
        {
            Local_u8BitValue = GET_BIT(SSD_u8Digits[Copy_u8Number], Local_u8Iterator);

            if (Copy_Config.SSD_Type == SSD_COMMON_CATHODE)
            {
                /*
                 * Common cathode:
                 *      1 turns segment ON
                 *      0 turns segment OFF
                 */
                GPIO_voidSetPinValue(Copy_Config.Port[Local_u8Iterator],
                                     Copy_Config.Pin[Local_u8Iterator],
                                     Local_u8BitValue);
            }
            else
            {
                /*
                 * Common anode:
                 *      0 turns segment ON
                 *      1 turns segment OFF
                 *
                 * So invert common cathode digit pattern.
                 */
                GPIO_voidSetPinValue(Copy_Config.Port[Local_u8Iterator],
                                     Copy_Config.Pin[Local_u8Iterator],
                                     !Local_u8BitValue);
            }
        }
    }
    else
    {
        /*
         * Invalid number.
         * SSD supports digits 0..9 only.
         */
    }
}


void SSD_voidClear(SSD_Config_t Copy_Config)
{
    u8 Local_u8Iterator;

    for (Local_u8Iterator = 0; Local_u8Iterator < SSD_SEGMENT_COUNT; Local_u8Iterator++)
    {
        if (Copy_Config.SSD_Type == SSD_COMMON_CATHODE)
        {
            GPIO_voidSetPinValue(Copy_Config.Port[Local_u8Iterator],
                                 Copy_Config.Pin[Local_u8Iterator],
                                 GPIO_LOW);
        }
        else
        {
            GPIO_voidSetPinValue(Copy_Config.Port[Local_u8Iterator],
                                 Copy_Config.Pin[Local_u8Iterator],
                                 GPIO_HIGH);
        }
    }
}


void SSD_voidEnable(SSD_Config_t Copy_Config)
{
    /*
     * Enable pin logic depends on your hardware design.
     *
     * For common cathode:
     *      EN = HIGH enables SSD
     *
     * For common anode:
     *      EN = LOW enables SSD
     */
    if (Copy_Config.SSD_Type == SSD_COMMON_CATHODE)
    {
        GPIO_voidSetPinValue(Copy_Config.Port[SSD_SEG_EN],
                             Copy_Config.Pin[SSD_SEG_EN],
                             GPIO_LOW);
    }
    else
    {
        GPIO_voidSetPinValue(Copy_Config.Port[SSD_SEG_EN],
                             Copy_Config.Pin[SSD_SEG_EN],
                             GPIO_HIGH);
    }
}


void SSD_voidDisable(SSD_Config_t Copy_Config)
{
    /*
     * Disable pin logic is the opposite of enable logic.
     */
    if (Copy_Config.SSD_Type == SSD_COMMON_CATHODE)
    {
        GPIO_voidSetPinValue(Copy_Config.Port[SSD_SEG_EN],
                             Copy_Config.Pin[SSD_SEG_EN],
                             GPIO_HIGH);
    }
    else
    {
        GPIO_voidSetPinValue(Copy_Config.Port[SSD_SEG_EN],
                             Copy_Config.Pin[SSD_SEG_EN],
                             GPIO_LOW);
    }
}
