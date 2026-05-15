/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    RCC_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 14/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401 / Cortex-M4
 *
 */ 

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define RCC_PLL_M            16
#define RCC_PLL_N            336
#define RCC_PLL_P            4
#define RCC_PLL_Q            7

/* AHB prescaler values for RCC_CFGR HPRE */
#define SYSCLK_NOT_DIVIDED       0b0000
#define SYSCLK_DIVIDED_BY_2      0b1000
#define SYSCLK_DIVIDED_BY_4      0b1001
#define SYSCLK_DIVIDED_BY_8      0b1010
#define SYSCLK_DIVIDED_BY_16     0b1011
#define SYSCLK_DIVIDED_BY_64     0b1100
#define SYSCLK_DIVIDED_BY_128    0b1101
#define SYSCLK_DIVIDED_BY_256    0b1110
#define SYSCLK_DIVIDED_BY_512    0b1111

/* APB prescaler values for RCC_CFGR PPRE1/PPRE2 */
#define HCLK_NOT_DIVIDED         0b000
#define HCLK_DIVIDED_BY_2        0b100
#define HCLK_DIVIDED_BY_4        0b101
#define HCLK_DIVIDED_BY_8        0b110
#define HCLK_DIVIDED_BY_16       0b111

#define DISABLE_CLOCK_SECURITY_SYSTEM   0
#define ENABLE_CLOCK_SECURITY_SYSTEM    1

/*==================== RCC Bus IDs ====================*/

#define RCC_AHB1_BUS        0
#define RCC_AHB2_BUS        1
#define RCC_APB1_BUS        2
#define RCC_APB2_BUS        3


/*==================== AHB1 Peripherals ====================*/

#define RCC_GPIOA           0
#define RCC_GPIOB           1
#define RCC_GPIOC           2
#define RCC_GPIOD           3
#define RCC_GPIOE           4
#define RCC_GPIOH           7
#define RCC_CRC             12
#define RCC_DMA1            21
#define RCC_DMA2            22


/*==================== AHB2 Peripherals ====================*/

#define RCC_OTGFS           7


/*==================== APB1 Peripherals ====================*/

#define RCC_TIM2            0
#define RCC_TIM3            1
#define RCC_TIM4            2
#define RCC_TIM5            3
#define RCC_WWDG            11
#define RCC_SPI2            14
#define RCC_SPI3            15
#define RCC_USART2          17
#define RCC_I2C1            21
#define RCC_I2C2            22
#define RCC_I2C3            23
#define RCC_PWR             28


/*==================== APB2 Peripherals ====================*/

#define RCC_TIM1            0
#define RCC_USART1          4
#define RCC_USART6          5
#define RCC_ADC1            8
#define RCC_SDIO            11
#define RCC_SPI1            12
#define RCC_SPI4            13
#define RCC_SYSCFG          14
#define RCC_TIM9            16
#define RCC_TIM10           17
#define RCC_TIM11           18


void RCC_voidInitSysClock(void);
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

#endif /* RCC_INTERFACE_H_ */
