#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LED_interface.h"
#include "SW_interface.h"
#include "SSD_interface.h"
#include "KPD_interface.h"



// #include "NVIC_interface.h"
// #include "EXTI_interface.h"

LED_Type LED1 =
{
    .Port = GPIOA,
    .Pin = GPIO_PIN1,
    .ActiveStatus = LED_ACTIVE_HIGH
};

SW_t SW1 =
{
    .Port = GPIOA,
    .Pin = GPIO_PIN0,
    .SW_Type = SW_ACTIVE_HIGH
};

SSD_Config_t SSD1 = {
    .Port = {GPIOB , GPIOB , GPIOA , GPIOA , GPIOA , GPIOA , GPIOA , GPIOA},
    .Pin  = {GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7},
    .SSD_Type = SSD_COMMON_CATHODE,
};

KPD_t KPD1 = {
    .RowPort = {GPIOC , GPIOC , GPIOC , GPIOC },
    .RowPin  = {GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 },
    .ColPort = {GPIOC , GPIOC , GPIOC },
    .ColPin = {GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 },
};

// void Button1_EXTI_Callback(void)
// {
//     LED_voidToggle(LED1);
// }

int main(void)
{
    RCC_voidInitSysClock();
    STK_voidInit();
    SSD_voidInit(SSD1);

    RCC_voidEnablePeripheralClock(RCC_AHB1_BUS, RCC_GPIOA);
    //RCC_voidEnablePeripheralClock(RCC_APB2_BUS, RCC_SYSCFG);
    // أو:
    // RCC_voidEnableSYSCFGClock();

    SW_voidInit    (SW1);
    LED_voidInit(LED1);
    LED_voidTurnOff(LED1);
    SSD_voidClear(SSD1);
    SSD_voidEnable(SSD1);
    SSD_voidDisplay(SSD1,8);
    KPD_voidInit(KPD1);

    KPD_u8GetPressedKey(KPD1);
    u8 currentKey = KPD_NO_PRESSED_KEY; 
    u8 preKey = KPD_NO_PRESSED_KEY; 


    while (1)
    {
        if (currentKey !=KPD_NO_PRESSED_KEY && currentKey!= preKey)
        {
        SSD_voidDisplay(SSD1, (currentKey - '0'));
        }
        //preKey==currentKey;
        


        // if (SW_u8GetState(SW1) == SW_PRESSED)
        // {
        // SSD_voidDisplay(SSD1, 0);
        // LED_voidTurnOn(LED1);
        // }

    }
    

    // LED_voidInit(&LED1);
    // SW_voidInit(&SW1);
    
    // u8 v ;
    // while (1)
    // {
    //     GPIO_voidGetPinValue(GPIOA,GPIO_PIN0, &v);

    // if (v == SW_PRESSED)
    // {
    //     GPIO_voidSetPinValue(GPIOA, GPIO_PIN1, GPIO_HIGH);
    
    // }
    // }
    
}

    // EXTI_voidSetEXTIConfiguration(EXTI_LINE0, EXTI_PORTA);
    // EXTI_voidSetSignalLatch(EXTI_LINE0, EXTI_FALLING_EDGE);
    // EXTI_voidSetCallBack(EXTI_LINE0, Button1_EXTI_Callback);
    // EXTI_voidEnableLine(EXTI_LINE0);

    //NVIC_voidEnableInterrupt(NVIC_EXTI0_IRQ);
