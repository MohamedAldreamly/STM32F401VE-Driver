/*
 *<<<<<<<<<<<<<<<<<<<    USART_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 15/5/2026
 *  Version : V02
 *  Layer   : MCAL
 *  Target  : STM32F401 / Cortex-M4
 *
 */

#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_

void USART_Init(void);

u8 Usart1_TransmitByte(u8 Byte);
u8 Usart1_TransmitString(const char *Str);
u8 Usart1_RecieveByte(void);

char* Usart1_ReadLine(char *buffer , u32 maxLen);


#endif 