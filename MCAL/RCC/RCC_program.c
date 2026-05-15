/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    RCC_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 14/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401 / Cortex-M4
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"



void RCC_voidInitSysClock(void)
{
    /* 1- Enable HSI */
    RCC->CR |= (1 << 0);
    while (!(RCC->CR & (1 << 1)));

 /* 2- Configure FLASH access for high-speed operation (84 MHz)
 *----------------------------------------------------------
 * FLASH memory is slower than the CPU at high frequencies,
 * so wait states must be added to ensure stable operation.
 *
 * LATENCY = 2 WS  -> Required for 84 MHz on STM32F401
 *
 * Enable:
 * - Instruction cache
 * - Data cache
 * to improve FLASH access performance.
 *---------------------------------------------------------*/

/* Clear previous latency configuration */

    FLASH->ACR &= ~(0x7 << 0);

    /* Set 2 wait states */
    FLASH->ACR |=  (2 << 0);

    FLASH->ACR |= (1 << 8);   // Prefetch enable
    FLASH->ACR |= (1 << 9);   // Instruction cache enable
    FLASH->ACR |= (1 << 10);  // Data cache enable

    /*----------------------------------------------------------
 * PLL Configuration for 84 MHz System Clock
 *
 * Clock Source : HSI = 16 MHz
 *
 * PLL Input  = HSI / PLLM
 *            = 16 MHz / 16
 *            = 1 MHz
 *
 * VCO Output = PLL Input * PLLN
 *            = 1 MHz * 336
 *            = 336 MHz
 *
 * SYSCLK     = VCO Output / PLLP
 *            = 336 MHz / 4
 *            = 84 MHz
 *
 * USB Clock  = VCO Output / PLLQ
 *            = 336 MHz / 7
 *            = 48 MHz
 *
 * Final Clocks:
 * AHB  = 84 MHz
 * APB1 = 42 MHz
 * APB2 = 84 MHz
 *---------------------------------------------------------*/

    /* 3- Configure PLL */
    RCC->PLLCFGR = 0;
    RCC->PLLCFGR |= (RCC_PLL_M << 0);     // PLLM = 16
    RCC->PLLCFGR |= (RCC_PLL_N << 6);    // PLLN = 336
    RCC->PLLCFGR |= (1 << 16);     // PLLP = /4
    CLR_BIT(RCC->PLLCFGR,22);     // PLL source = HSI
    RCC->PLLCFGR |= (RCC_PLL_Q << 24);     // PLLQ = 7

    /*----------------------------------------------------------
 * Bus Clock Configuration
 *
 * PLL generates the System Clock (SYSCLK = 84 MHz).
 *
 * Bus clocks are NOT taken directly from PLL.
 * They are derived through prescalers as follows:
 *
 * SYSCLK --> AHB Prescaler --> HCLK
 * HCLK   --> APB1 Prescaler --> PCLK1
 * HCLK   --> APB2 Prescaler --> PCLK2
 *
 * Clock Tree:
 *
 * PLL --> SYSCLK = 84 MHz
 *              |
 *           AHB /1
 *              |
 *         HCLK = 84 MHz
 *            /       \
 *      APB1 /2     APB2 /1
 *         |            |
 *   PCLK1 = 42 MHz  PCLK2 = 84 MHz
 *
 * APB1 is limited to 42 MHz maximum on STM32F401.
 * APB2 supports up to 84 MHz.
 *---------------------------------------------------------*/
    /* 4- Bus prescalers */
    RCC->CFGR &= ~(0xF << 4);      // AHB  /1 = 84MHz

    RCC->CFGR &= ~(0x7 << 10);
    RCC->CFGR |=  (0x4 << 10);     // APB1 /2 = 42MHz

    RCC->CFGR &= ~(0x7 << 13);     // APB2 /1 = 84MHz

    /* 5- Enable PLL */
    RCC->CR |= (1 << 24);
    while (!(RCC->CR & (1 << 25)));

    /* 6- Select PLL as system clock */
    RCC->CFGR &= ~(0x3 << 0);
    RCC->CFGR |=  (0x2 << 0);

    while (((RCC->CFGR >> 2) & 0x3) != 0x2);
}


void RCC_voidEnablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    switch (Copy_u8BusId)
    {
        case RCC_AHB1_BUS: SET_BIT(RCC->AHB1ENR, Copy_u8PeripheralId); break;
        case RCC_AHB2_BUS: SET_BIT(RCC->AHB2ENR, Copy_u8PeripheralId); break;
        case RCC_APB1_BUS: SET_BIT(RCC->APB1ENR, Copy_u8PeripheralId); break;
        case RCC_APB2_BUS: SET_BIT(RCC->APB2ENR, Copy_u8PeripheralId); break;
        default: break;
    }
}

void RCC_voidDisablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    switch (Copy_u8BusId)
    {
        case RCC_AHB1_BUS: CLR_BIT(RCC->AHB1ENR, Copy_u8PeripheralId); break;
        case RCC_AHB2_BUS: CLR_BIT(RCC->AHB2ENR, Copy_u8PeripheralId); break;
        case RCC_APB1_BUS: CLR_BIT(RCC->APB1ENR, Copy_u8PeripheralId); break;
        case RCC_APB2_BUS: CLR_BIT(RCC->APB2ENR, Copy_u8PeripheralId); break;
        default: break;
    }
}
