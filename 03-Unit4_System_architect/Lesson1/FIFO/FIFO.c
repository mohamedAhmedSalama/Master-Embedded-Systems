/*
    FIFO.c
    ENG.Mohamed Ahmed Salama
*/
#include"FIFO.h"
#include<stdio.h>
#include<stdlib.h>

FIFO_Status_t FIFO_Init(FIFO_Buffer_t* FifoBuffer, Element_Type* buffer, unsigned int length)
{
    //check if buffer is available
    if(buffer == NULL)
        return FIFO_null;

    // if it is available then initialize buffer
    FifoBuffer->base = buffer;
    FifoBuffer->head = buffer;
    FifoBuffer->tail = buffer;
    FifoBuffer->count = 0;
    FifoBuffer->length = length;

    return FIFO_no_error;

}

FIFO_Status_t FIFO_Enqueue(FIFO_Buffer_t* FifoBuffer, Element_Type data)
{
    //check if FIFO is available
    if(!(FifoBuffer->base) || !(FifoBuffer->head) || !(FifoBuffer->tail))
        return FIFO_null;

    //check if FIFO is full
    if(FifoBuffer->count == FifoBuffer->length)
        return FIFO_full;

    // Enqueue new data into fifo
    *(FifoBuffer->head) = data;
    FifoBuffer->count++;

    if(FifoBuffer->head == (FifoBuffer->base + (FifoBuffer->length * sizeof(Element_Type))))
        FifoBuffer->head = FifoBuffer->base;
    else
        FifoBuffer->head++;

    return FIFO_no_error;


}

FIFO_Status_t FIFO_Dequeue(FIFO_Buffer_t* FifoBuffer, Element_Type* data)
{
    //check if FIFO is available
    if(!(FifoBuffer->base) || !(FifoBuffer->head) || !(FifoBuffer->tail))
        return FIFO_null;

    //check if FIFO is empty
    if(FifoBuffer->count == 0)
        return FIFO_empty;

    //dequeue data from fifo
    *data = *(FifoBuffer->tail);
    FifoBuffer->count--;
    if(FifoBuffer->tail == (FifoBuffer->base + (FifoBuffer->length * sizeof(Element_Type))))
        FifoBuffer->tail = FifoBuffer->base;
    else
        FifoBuffer->tail++;

    return FIFO_no_error;
}

FIFO_Status_t FIFO_Peek(FIFO_Buffer_t* FifoBuffer, Element_Type* data)
{
    //check if FIFO is available
    if(!(FifoBuffer->base) || !(FifoBuffer->head) || !(FifoBuffer->tail))
        return FIFO_null;

    //check if FIFO is empty
    if(FifoBuffer->count == 0)
        return FIFO_empty;

    //dequeue data from fifo
    *data = *(FifoBuffer->tail);
    return FIFO_no_error;

}

FIFO_Status_t FIFO_IsFull(FIFO_Buffer_t* FifoBuffer)
{
    //check if FIFO is available
    if(!(FifoBuffer->base) || !(FifoBuffer->head) || !(FifoBuffer->tail))
        return FIFO_null;

    //check if FIFO is full
    if(FifoBuffer->count == FifoBuffer->length)
        return FIFO_full;
    else
        return FIFO_not_full;
}

FIFO_Status_t FIFO_IsEmpty(FIFO_Buffer_t* FifoBuffer)
{
    //check if FIFO is available
    if(!(FifoBuffer->base) || !(FifoBuffer->head) || !(FifoBuffer->tail))
        return FIFO_null;

    //check if FIFO is empty
    if(FifoBuffer->count == 0)
        return FIFO_empty;
    else
        return FIFO_not_empty;
}
