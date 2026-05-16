/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Ring_Buffer.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Aldreamly
 *  Date    : 16/5/2026
 *  Version : V01
 *  Layer   : LIB
 *  Target  : STM32F401 / Cortex-M4
 *
 */

#include "RingBuffer.h"

void RB_Init(RingBufferType* rb)
{
    rb->writeIndex = 0; 
    rb->readIndex = 0; 
    rb->count = 0 ;
}

bool RB_Enqueue(RingBufferType* rb , u8 byte)
{
    if (RB_Full(rb)){
        return FALSE; 
    }
    rb->buffer[rb->writeIndex] = byte ; 
    rb->writeIndex = (rb->writeIndex +1 ) % RB_SIZE; 
    rb->count++; 
    return TRUE; 
}

bool RB_Denqueu(RingBufferType* rb , u8 byte)
{
    if (RB_IsEmpty(rb)){
        return FALSE; 
    }
    rb->buffer[rb->readIndex] = byte ; 
    rb->readIndex = (rb->readIndex + 1 ) % RB_SIZE; 
    rb->count--; 
    return TRUE; 

}

u8 RB_Peek(const RingBufferType* rb)
{
    return rb->buffer[rb->readIndex];
}
bool RB_IsEmpty(const RingBufferType* rb)
{
    return(rb->count == 0);
}

bool RB_IsFull(const RingBufferType* rb)
{
    return(rb->count == RB_SIZE);
}

u32 RB_Available(const RingBufferType* rb)
{
    return rb->count;
}

u32 RB_Flush( RingBufferType* rb)
{
    rb->writeIndex = 0; 
    rb->readIndex = 0; 
    rb->count = 0 ;
}

