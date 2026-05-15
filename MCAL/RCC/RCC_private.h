/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    RCC_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 14/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401 / Cortex-M4
 *
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

typedef struct
{
    volatile u32 CR;              /* 0x00 */
    volatile u32 PLLCFGR;         /* 0x04 */
    volatile u32 CFGR;            /* 0x08 */
    volatile u32 CIR;             /* 0x0C */
    volatile u32 AHB1RSTR;        /* 0x10 */
    volatile u32 AHB2RSTR;        /* 0x14 */
    volatile u32 RESERVED0[2];    /* 0x18 - 0x1C */
    volatile u32 APB1RSTR;        /* 0x20 */
    volatile u32 APB2RSTR;        /* 0x24 */
    volatile u32 RESERVED1[2];    /* 0x28 - 0x2C */
    volatile u32 AHB1ENR;         /* 0x30 */
    volatile u32 AHB2ENR;         /* 0x34 */
    volatile u32 RESERVED2[2];    /* 0x38 - 0x3C */
    volatile u32 APB1ENR;         /* 0x40 */
    volatile u32 APB2ENR;         /* 0x44 */
    volatile u32 RESERVED3[2];    /* 0x48 - 0x4C */
    volatile u32 AHB1LPENR;       /* 0x50 */
    volatile u32 AHB2LPENR;       /* 0x54 */
    volatile u32 RESERVED4[2];    /* 0x58 - 0x5C */
    volatile u32 APB1LPENR;       /* 0x60 */
    volatile u32 APB2LPENR;       /* 0x64 */
    volatile u32 RESERVED5[2];    /* 0x68 - 0x6C */
    volatile u32 BDCR;            /* 0x70 */
    volatile u32 CSR;             /* 0x74 */
    volatile u32 RESERVED6[2];    /* 0x78 - 0x7C */
    volatile u32 SSCGR;           /* 0x80 */
    volatile u32 PLLI2SCFGR;      /* 0x84 */
    volatile u32 RESERVED7;       /* 0x88 */
    volatile u32 DCKCFGR;         /* 0x8C */
} RCC_t;

#define RCC ((volatile RCC_t *)0x40023800UL)

#define FLASH_BASE_ADDR   0x40023C00UL

typedef struct
{
    volatile u32 ACR;
    volatile u32 KEYR;
    volatile u32 OPTKEYR;
    volatile u32 SR;
    volatile u32 CR;
    volatile u32 OPTCR;
} FLASH_t;

#define FLASH ((FLASH_t *)FLASH_BASE_ADDR)

/* RCC_CR bits */
#define RCC_CR_HSION       0
#define RCC_CR_HSIRDY      1
#define RCC_CR_HSEON       16
#define RCC_CR_HSERDY      17
#define RCC_CR_HSEBYP      18
#define RCC_CR_CSSON       19
#define RCC_CR_PLLON       24
#define RCC_CR_PLLRDY      25

/* RCC_CFGR positions */
#define RCC_CFGR_SW_POS       0
#define RCC_CFGR_SWS_POS      2
#define RCC_CFGR_HPRE_POS     4
#define RCC_CFGR_PPRE1_POS    10
#define RCC_CFGR_PPRE2_POS    13

#define RCC_CFGR_SW_HSI       0b00
#define RCC_CFGR_SW_HSE       0b01
#define RCC_CFGR_SW_PLL       0b10

/* RCC_PLLCFGR positions */
#define RCC_PLLCFGR_PLLM_POS      0
#define RCC_PLLCFGR_PLLN_POS      6
#define RCC_PLLCFGR_PLLP_POS      16
#define RCC_PLLCFGR_PLLSRC_POS    22
#define RCC_PLLCFGR_PLLQ_POS      24

#define RCC_PLLSRC_HSI_VALUE      0
#define RCC_PLLSRC_HSE_VALUE      1

#define RCC_TIMEOUT               50000UL

#endif /* RCC_PRIVATE_H_ */
