/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    NVIC_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> >
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 12/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401 / Cortex-M4
 *
 */

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#include "STD_TYPES.h"

/* STM32F401VE IRQ Numbers */

#define NVIC_WWDG_IRQ              0
#define NVIC_PVD_IRQ               1
#define NVIC_TAMP_STAMP_IRQ        2
#define NVIC_RTC_WKUP_IRQ          3
#define NVIC_FLASH_IRQ             4
#define NVIC_RCC_IRQ               5

#define NVIC_EXTI0_IRQ             6
#define NVIC_EXTI1_IRQ             7
#define NVIC_EXTI2_IRQ             8
#define NVIC_EXTI3_IRQ             9
#define NVIC_EXTI4_IRQ             10

#define NVIC_DMA1_STREAM0_IRQ      11
#define NVIC_DMA1_STREAM1_IRQ      12
#define NVIC_DMA1_STREAM2_IRQ      13
#define NVIC_DMA1_STREAM3_IRQ      14
#define NVIC_DMA1_STREAM4_IRQ      15
#define NVIC_DMA1_STREAM5_IRQ      16
#define NVIC_DMA1_STREAM6_IRQ      17

#define NVIC_ADC_IRQ               18

#define NVIC_EXTI9_5_IRQ           23

#define NVIC_TIM1_BRK_TIM9_IRQ     24
#define NVIC_TIM1_UP_TIM10_IRQ     25
#define NVIC_TIM1_TRG_COM_TIM11_IRQ 26
#define NVIC_TIM1_CC_IRQ           27

#define NVIC_TIM2_IRQ              28
#define NVIC_TIM3_IRQ              29
#define NVIC_TIM4_IRQ              30

#define NVIC_I2C1_EV_IRQ           31
#define NVIC_I2C1_ER_IRQ           32
#define NVIC_I2C2_EV_IRQ           33
#define NVIC_I2C2_ER_IRQ           34

#define NVIC_SPI1_IRQ              35
#define NVIC_SPI2_IRQ              36

#define NVIC_USART1_IRQ            37
#define NVIC_USART2_IRQ            38

#define NVIC_EXTI15_10_IRQ         40
#define NVIC_RTC_ALARM_IRQ         41
#define NVIC_OTG_FS_WKUP_IRQ       42

#define NVIC_DMA1_STREAM7_IRQ      47

#define NVIC_SDIO_IRQ              49
#define NVIC_TIM5_IRQ              50
#define NVIC_SPI3_IRQ              51

#define NVIC_DMA2_STREAM0_IRQ      56
#define NVIC_DMA2_STREAM1_IRQ      57
#define NVIC_DMA2_STREAM2_IRQ      58
#define NVIC_DMA2_STREAM3_IRQ      59
#define NVIC_DMA2_STREAM4_IRQ      60

#define NVIC_OTG_FS_IRQ            67

#define NVIC_DMA2_STREAM5_IRQ      68
#define NVIC_DMA2_STREAM6_IRQ      69
#define NVIC_DMA2_STREAM7_IRQ      70

#define NVIC_USART6_IRQ            71

#define NVIC_I2C3_EV_IRQ           72
#define NVIC_I2C3_ER_IRQ           73

#define NVIC_FPU_IRQ               81

#define NVIC_SPI4_IRQ              84

void NVIC_voidEnableInterrupt(u8 Copy_u8IRQNumber);
void NVIC_voidDisableInterrupt(u8 Copy_u8IRQNumber);


#endif
