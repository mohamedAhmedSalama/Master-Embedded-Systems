/*
    LIFO.c
    ENG.Mohamed Ahmed Salama
*/
#include"LIFO.h"
#include<stdio.h>
#include<stdlib.h>
LIFO_Status_t LIFO_Init(LIFO_Buffer_t* LifoBuffer, unsigned int* buffer, unsigned int length)
{
    //check if buffer is available
    if(buffer == NULL)
        return LIFO_null;
    // if it is available then initialize buffer
    LifoBuffer->base = buffer;
    LifoBuffer->head = buffer;
    LifoBuffer->length = length;
    LifoBuffer->count = 0;

    return LIFO_no_error;
}

LIFO_Status_t LIFO_Push(LIFO_Buffer_t* LifoBuffer, unsigned int data)
{
    //check if LIFO is available
    if(!(LifoBuffer->base)|| !(LifoBuffer->head))
        return LIFO_null;

    //check if LIFO is full
    if(LifoBuffer->count == LifoBuffer->length)
        return LIFO_full;

    //push new data
    *(LifoBuffer->head) = data;
    LifoBuffer->head++;
    LifoBuffer->count++;
    return LIFO_no_error;
}

LIFO_Status_t LIFO_Pop(LIFO_Buffer_t* LifoBuffer, unsigned int* data)
{
    //check if LIFO is available
    if(!(LifoBuffer->base)|| !(LifoBuffer->head))
        return LIFO_null;

    //check if LIFO is empty
    if(0 == LifoBuffer->count)
        return LIFO_empty;

    //pop data
    LifoBuffer->head--;
    *data = *(LifoBuffer->head);
    LifoBuffer->count--;

    return LIFO_no_error;
}

LIFO_Status_t LIFO_Peek(LIFO_Buffer_t* LifoBuffer, unsigned int* data)
{
    //check if LIFO is available
    if(!(LifoBuffer->base)|| !(LifoBuffer->head))
        return LIFO_null;

    //check if LIFO is empty
    if(0 == LifoBuffer->count)
        return LIFO_empty;

    //peek data
    LifoBuffer->head--;
    *data = *(LifoBuffer->head);
    LifoBuffer->head++;

    return LIFO_no_error;
}

LIFO_Status_t LIFO_IsFull(LIFO_Buffer_t* LifoBuffer)
{
    //check if LIFO is available
    if(!(LifoBuffer->base)|| !(LifoBuffer->head))
        return LIFO_null;

    if(LifoBuffer->count == LifoBuffer->length)
        return LIFO_full;
    else
        return LIFO_not_full;
}

LIFO_Status_t LIFO_IsEmpty(LIFO_Buffer_t* LifoBuffer)
{
    //check if LIFO is available
    if(!(LifoBuffer->base)|| !(LifoBuffer->head))
        return LIFO_null;

    if(0 == LifoBuffer->count)
        return LIFO_empty;
    else
        return LIFO_not_empty;
}
