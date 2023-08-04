/*
    FIFO.h
    ENG.Mohamed Ahmed Salama
*/
#ifndef FIFO_H_
#define FIFO_H_

#define Element_Type int
#define FIFO_Buffer_Lenght  5

typedef struct{
    int length;
    int count;
    Element_Type* base;
    Element_Type* head;
    Element_Type* tail;
}FIFO_Buffer_t;

typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_not_full,
    FIFO_empty,
    FIFO_not_empty,
    FIFO_null
}FIFO_Status_t;

FIFO_Status_t FIFO_Init(FIFO_Buffer_t* FifoBuffer, Element_Type* buffer, unsigned int length);
FIFO_Status_t FIFO_Enqueue(FIFO_Buffer_t* FifoBuffer, Element_Type data);
FIFO_Status_t FIFO_Dequeue(FIFO_Buffer_t* FifoBuffer, Element_Type* data);
FIFO_Status_t FIFO_Peek(FIFO_Buffer_t* FifoBuffer, Element_Type* data);
FIFO_Status_t FIFO_IsFull(FIFO_Buffer_t* FifoBuffer);
FIFO_Status_t FIFO_IsEmpty(FIFO_Buffer_t* FifoBuffer);

#endif // FIFO_H_
