/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Ring_Buffer.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 16/5/2026
 *  Version : V01
 *  Layer   : LIB
 *  Target  : STM32F401 / Cortex-M4
 *
 */

#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include "STD_TYPES.h"

#define FALSE 0 
#define TRUE 1

#define RB_SIZE 256

 typedef struct 
 {
    u8 buffer[RB_SIZE];
    volatile u32 writeIndex; 
    volatile u32 readIndex; 
    volatile u32 count ; 
 }RingBufferType;

void RB_Init(RingBufferType* rb);
bool RB_Enqueue(RingBufferType* rb , u8 byte);
bool RB_Denqueue(RingBufferType* rb , u8 byte);
u8 RB_Peek(const RingBufferType* rb);
bool RB_IsEmpty(const RingBufferType* rb);
bool RB_IsFull(const RingBufferType* rb);
u32 RB_Available(const RingBufferType* rb);
u32 RB_Flush( RingBufferType* rb);



#endif
