/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    RCC_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 14/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401 / Cortex-M4
 *
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/* STM32F401 PLL equation:
 * PLL input = HSI or HSE
 * VCO input = PLL input / PLLM
 * VCO output = VCO input * PLLN
 * SYSCLK = VCO output / PLLP
 * USB/SDIO/RNG clock = VCO output / PLLQ
 *
 * Safe HSI 84MHz example:
 * HSI = 16MHz, PLLM=16, PLLN=336, PLLP=4, PLLQ=7
 */



#endif /* RCC_CONFIG_H_ */
