/*
    FIFO.h
    ENG.Mohamed Ahmed Salama
*/
#ifndef FIFO_H_
#define FIFO_H_

#include <string.h>

#define FIFO_Buffer_Lenght  5
#define NAME_LENGTH    25
#define MAX_COURSES_NUM 5

typedef struct{
    char First_Name[NAME_LENGTH];
    char Last_Name[NAME_LENGTH];
    int ID;
    float GPA;
    int Course_ID[MAX_COURSES_NUM];
}Student_t;

#define Element_Type Student_t

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

typedef enum{
    OK,
    Not_Found
}Student_Status_t;

FIFO_Status_t FIFO_Init(FIFO_Buffer_t* FifoBuffer, Element_Type* buffer, unsigned int length);
FIFO_Status_t FIFO_Enqueue(FIFO_Buffer_t* FifoBuffer, Element_Type data);
FIFO_Status_t FIFO_Dequeue(FIFO_Buffer_t* FifoBuffer, Element_Type* data);
FIFO_Status_t FIFO_Peek(FIFO_Buffer_t* FifoBuffer, Element_Type* data);
FIFO_Status_t FIFO_IsFull(FIFO_Buffer_t* FifoBuffer);
FIFO_Status_t FIFO_IsEmpty(FIFO_Buffer_t* FifoBuffer);
FIFO_Status_t FIFO_CountStudent(FIFO_Buffer_t* FifoBuffer, int* count_num);
Student_Status_t FIFO_EditStudentData_ByID( int id , Element_Type* data);

void FIFO_AddStudent_Manually(FIFO_Buffer_t* FifoBuffer );
void FIFO_AddStudent_FromFile(FIFO_Buffer_t* FifoBuffer );
void FIFO_FindStudent_ByID(FIFO_Buffer_t* FifoBuffer);
void FIFO_FindStudent_ByFirstName(FIFO_Buffer_t* FifoBuffer);
void FIFO_FindStudent_ByCourse(FIFO_Buffer_t* FifoBuffer);
void FIFO_DeleteStudent_ByID(FIFO_Buffer_t* FifoBuffer );
void FIFO_UpdateStudent_ByID(FIFO_Buffer_t* FifoBuffer );
void FIFO_UpadteStudentFile(FIFO_Buffer_t* FifoBuffer);
void FIFO_PrintStudent_Count(FIFO_Buffer_t* FifoBuffer);
void FIFO_PrintAll(FIFO_Buffer_t* FifoBuffer);
#endif // FIFO_H_

