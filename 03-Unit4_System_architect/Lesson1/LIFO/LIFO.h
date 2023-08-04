/*
    LIFO.h
    ENG.Mohamed Ahmed Salama
*/
#ifndef LIFO_H_
#define LIFO_H_

#define LIFO_Buffer_Lenght  5

typedef struct{
    unsigned int length;
    unsigned int* base;
    unsigned int* head;
    unsigned int count;
}LIFO_Buffer_t;

typedef enum{
    LIFO_no_error,
    LIFO_full,
    LIFO_not_full,
    LIFO_empty,
    LIFO_not_empty,
    LIFO_null
}LIFO_Status_t;

LIFO_Status_t LIFO_Init(LIFO_Buffer_t* LifoBuffer, unsigned int* buffer, unsigned int length);
LIFO_Status_t LIFO_Push(LIFO_Buffer_t* LifoBuffer, unsigned int data);
LIFO_Status_t LIFO_Pop(LIFO_Buffer_t* LifoBuffer, unsigned int* data);
LIFO_Status_t LIFO_Peek(LIFO_Buffer_t* LifoBuffer, unsigned int* data);
LIFO_Status_t LIFO_IsFull(LIFO_Buffer_t* LifoBuffer);
LIFO_Status_t LIFO_IsEmpty(LIFO_Buffer_t* LifoBuffer);


#endif // LIFO_H_
