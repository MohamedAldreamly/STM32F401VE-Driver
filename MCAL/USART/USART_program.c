/*
 *<<<<<<<<<<<<<<<<<<<   USART_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 15/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401 / Cortex-M4
 *
 */
#include "stm32f401xe.h"

#include "GPIO_interface.h"
#include "NVIC_interface.h"

#include "USART_interface.h"
#include "RingBuffer.h"

static RingBufferType usart1_rx_ring;

void USART_Init(void)
{   
    GPIO_voidSetPinMode(GPIOA, GPIO_PIN7, GPIO_ALTFN);
    GPIO_voidSetPinMode(GPIOB, GPIO_PIN7, GPIO_ALTFN);

    GPIO_voidSetPinAF(GPIOA ,  GPIO_PIN7, GPIO_AF_7);
    GPIO_voidSetPinAF(GPIOB ,  GPIO_PIN7, GPIO_AF_7);

    CLR_BIT(USART1->CR1 ,USART_CR1_M_Pos );

    USART1->CR2 &= ~(USART_CR2_STOP_Msk);

    CLR_BIT(USART1->CR1 ,USART_CR1_OVER8_Pos );

    USART1->BRR = 0x683; 

    NVIC_voidEnableInterrupt(NVIC_USART1_IRQ);

    SET_BIT(USART1->CR1 ,USART_CR1_RE_Pos );

    SET_BIT(USART1->CR1 ,USART_CR1_TE_Pos );

    SET_BIT(USART1->CR1 ,USART_CR1_UE_Pos );

}

u8 Usart1_TransmitByte(u8 Byte)
{
    if (USART1->SR & USART_SR_TXE)
    {
        USART1->DR = Byte ; 
        while  (!(USART1->SR & USART_SR_TC_Msk));
        USART1->SR &= ~(USART_SR_TC_Msk);
        return 1;//Tx_OK
    }
    return 0;//Tx_NO
}

u8 Usart1_TransmitString(const char *Str)
{
    u32 i=0; 
    u8 transmitResult=-1;
    while (Str[i] != '\0')
    {
        transmitResult = Usart1_TransmitByte(Str[i]);
        if (transmitResult == 1 )
        {
            i++;
        }
    }

}

u8 Usart1_RecieveByte(void)
{
    while (!(USART1->SR & USART_SR_RXNE_Msk));
    return USART1->DR; 
}

static u32 idx = 0 ; 
char* Usart1_ReadLine(char *buffer , u32 maxLen)
{
    u8 ch ;

    while (RB_Available(&usart1_rx_ring)>0)
    {
        ch = RB_Peek(&usart1_rx_ring);
        if (ch == '\n' || ch == '\r')
        {
            RB_Denqueue(&usart1_rx_ring, &ch);

            if (ch == '\r')
            {
                if (RB_Available(&usart1_rx_ring)>0)
                {
                    u8 next = RB_Peek(&usart1_rx_ring);
                    if (next == '\n')
                    {
                        RB_Denqueue(&usart1_rx_ring, &next);
                    }
                }
            }else if (ch == '\n')
            {
                if (RB_Available(&usart1_rx_ring)>0)
                {
                    u8 next = RB_Peek(&usart1_rx_ring);
                    if (next == '\r')
                    {
                        RB_Denqueue(&usart1_rx_ring, &next);
                    }
                }
            } 
            buffer[idx] = '\0';
            idx = 0 ;
            return buffer;
        }else
            {
                RB_Denqueue(&usart1_rx_ring, &ch);
                if(idx < (maxLen - 1))
                {
                    buffer[idx]= ch;
                    idx++;
                }
                else
                {
                return NULL ; 
                }
            }
        }
        return NULL;
    }
    
void USRAT1_IRQHandler(void)
{
    if(USART1->SR && USART_SR_RXNE)
    {
        u8 byte = USART1->DR;
        RB_Enqueue(&usart1_rx_ring,byte);

    }
}
