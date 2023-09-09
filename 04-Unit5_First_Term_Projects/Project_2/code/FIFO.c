/*
    FIFO.c
    ENG.Mohamed Ahmed Salama
*/
#include"FIFO.h"
#include<stdio.h>
#include<stdlib.h>

FILE* Get_Student ,*Update_Student;

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
    while(FifoBuffer->base->ID != 0)
    {
        FifoBuffer->count++;
        FifoBuffer->base++;
    }
    FifoBuffer->base = buffer;
    FifoBuffer->length = length;

    return FIFO_no_error;

}

static Element_Type* Search_ByID(FIFO_Buffer_t* FifoBuffer , int id)
{
    Element_Type* stu = FifoBuffer->tail;
    int i , flag = 0;
    for( i = 0 ; i < FifoBuffer->count ; i++)
    {
        if(id == stu->ID)
        {
            flag = 1 ;
            break;
        }
        if( stu == (FifoBuffer->base + (FifoBuffer->length * sizeof(Element_Type))))
            stu = FifoBuffer->base;
        else
            stu++;
    }
    if(flag == 0)
        stu = 0;


    return stu;

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

/*
static Element_Type* FIFO_SearchStudent_ByID(FIFO_Buffer_t* FifoBuffer , int id )
{
    Element_Type* temp;
    temp =FifoBuffer->base;
    for(int i = 0 ; i < FifoBuffer->count ; i++)
    {
        if(temp->ID == id )
        {
            *data = temp ;
            return OK;
        }
        temp++;
    }
    return Not_Found;
}*/

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

FIFO_Status_t FIFO_CountStudent(FIFO_Buffer_t* FifoBuffer, int* count_num)
{
    *count_num = FifoBuffer->count;
    return FIFO_IsEmpty(FifoBuffer);
}

void FIFO_AddStudent_Manually(FIFO_Buffer_t* FifoBuffer )
{
    Element_Type data;
    FIFO_Status_t status;

    printf("=== Enter student data ===\n");

    printf("\tEnter student ID: ");
    scanf("%d",&data.ID);


    if(!Search_ByID(FifoBuffer,data.ID))
    {
        printf("\tEnter first name: ");
        scanf("%s",data.First_Name);

        printf("\tEnter second name: ");
        scanf("%s",data.Last_Name);

        printf("\tEnter GPA: ");
        scanf("%f", &data.GPA);

        printf("\tEnter Courses IDs\n");
        for (int i = 0; i < MAX_COURSES_NUM ; i++)
        {
            printf("\t\tEnter Courses no.%d: ",i+1);
            scanf("%d", &data.Course_ID[i]);
        }

        status = FIFO_Enqueue(FifoBuffer,data);
        if(status == FIFO_null)
         printf("\n [ERROR] Adding new student manually failed\n");
        else
         printf("\n [INFO] Adding new student with %d is done ! \n",data.ID);
    }
    else
    {
       printf("\n [ERROR] ID number %d is already taken\n", data.ID);
       printf(" [ERROR] Adding new student manually failed\n");
    }
}

void FIFO_AddStudent_FromFile(FIFO_Buffer_t* FifoBuffer )
{
    Element_Type data;
    FIFO_Status_t status;
    Get_Student = fopen("Student_data.txt","r");
    if(Get_Student == NULL)
    {
        printf("\n [ERROR] File is not found\n [ERROR] Adding new student from file failed\n");
        return;
    }
     while(!feof(Get_Student))
    {
        fscanf(Get_Student,"%d",&data.ID);
        if(Search_ByID(FifoBuffer,data.ID)==0)
        {
          fscanf(Get_Student,"%s",data.First_Name);

          fscanf(Get_Student,"%s",data.Last_Name);

          fscanf(Get_Student,"%f",&data.GPA);

          for (int i = 0; i < 5; ++i)
            fscanf(Get_Student,"%d",&data.Course_ID[i]);

          status = FIFO_Enqueue(FifoBuffer,data);

          if(status == FIFO_null)
          {
            printf("\n [ERROR] Adding new student from file failed\n");
            return;
          }
          else
            printf("\n [INFO] Adding new student with %d is done ! \n",data.ID);
        }
        else
        {
            printf("\n [ERROR] ID number %d is already taken , So can not be added\n", data.ID);
            fscanf(Get_Student,"%*[^\n]");
        }

    }
     printf("\n [INFO] Successfully Adding new Students :)\n" );
     fclose(Get_Student);
}

static void Print_StudentInfo(Element_Type* data)
{
    printf("\n The student info: \n\n");

    printf(" Name: %s %s\n",data->First_Name,data->Last_Name);

    printf(" ID: %d\n",data->ID);

    printf(" GPA: %.1f\n",data->GPA);

    printf(" Courses are :\n");
    for(int i = 0 ; i < MAX_COURSES_NUM ; i++)
    {
        printf("  Course %d ID is: %d\n",i+1,data->Course_ID[i]);
    }

}

void FIFO_FindStudent_ByID(FIFO_Buffer_t* FifoBuffer)
{
   int id;
   Element_Type* stu;
   FIFO_Status_t status;
   status = FIFO_IsEmpty(FifoBuffer);
   if(status == FIFO_null || status == FIFO_empty)
   {
       printf("\n [ERROR] Finding student by ID Number failed\n");
       return;
   }
   else
   {
       printf(" Enter ID Number: ");
       scanf("%d",&id);

       stu = Search_ByID(FifoBuffer,id);
       if(stu)
           Print_StudentInfo(stu);
       else
           printf(" [ERROR] ID number %d is not found, Try again!\n",id);
   }


}

void FIFO_FindStudent_ByFirstName(FIFO_Buffer_t* FifoBuffer)
{
    Element_Type* stu = FifoBuffer->base;
    char str[NAME_LENGTH];
    FIFO_Status_t status;
    status = FIFO_IsEmpty(FifoBuffer);
   if(status == FIFO_null || status == FIFO_empty)
   {
       printf("\n [ERROR] Finding student by first name failed\n");
       return;
   }
   else
   {
        printf(" Enter First Name: ");
        scanf("%s",str);
        for(int i = 0; i < FifoBuffer->count ; i++)
        {
            if(!strcmp(str,stu->First_Name))
            {
                Print_StudentInfo(stu);
                return;
            }
            stu++;

        }
        printf("\n [ERROR] %s in not found\n",str);
   }
}

void FIFO_PrintStudent_Count(FIFO_Buffer_t* FifoBuffer)
{
    int counter = FifoBuffer->count;
    int capcity = FifoBuffer->length;
    printf(" [INFO] Total number of students is %d\n", counter);
	printf(" [INFO] You can add up to %d students\n", capcity);
	printf(" [INFO] You can add %d more students\n", capcity - counter);
}

void FIFO_FindStudent_ByCourse(FIFO_Buffer_t* FifoBuffer)
{
   Element_Type* stu = FifoBuffer->base;
   int course_id , flag = 0 , counter = 0;
   FIFO_Status_t status;
   status = FIFO_IsEmpty(FifoBuffer);
   if(status == FIFO_null || status == FIFO_empty)
   {
       printf("\n [ERROR] Finding student by course failed\n");
       return;
   }
   else
   {
       printf(" Enter Course ID: ");
       scanf("%d",&course_id);
       for(int i = 0 ; i < FifoBuffer->count ; i++)
       {
           for(int j = 0 ; j < MAX_COURSES_NUM ; j++)
           {
               if(course_id == stu->Course_ID[j])
               {
                    Print_StudentInfo(stu);
                    printf("\n\n");
                    flag = 1;
                    counter++;
                    break;
               }
           }
           stu++;
       }
       if(flag == 1)
       {
           printf(" There is (%d) students enrolled in this course id: %d\n",counter,course_id);
       }
       else
       {
          printf("\n [ERROR] Course ID %d is not found\n",course_id);
       }

   }
}

void FIFO_DeleteStudent_ByID(FIFO_Buffer_t* FifoBuffer )
{
    Element_Type* stu;
    int id , flag = 0 ;
    FIFO_Status_t status;
   status = FIFO_IsEmpty(FifoBuffer);
   if(status == FIFO_null || status == FIFO_empty)
   {
       printf("\n [ERROR] Deleting student by ID number failed\n");
       return;
   }
   else
   {
       printf(" Enter ID Number: ");
       scanf("%d",&id);
       stu = FifoBuffer->tail;
       for(int i = 0 ;  i < FifoBuffer->count ; i++)
       {
           if( id ==  stu->ID )
           {
                for(int j = i ; j < FifoBuffer->count ; j++)
                {
                    if(stu == (FifoBuffer->base + (FifoBuffer->length * sizeof(Element_Type))))
                    {
                        stu = FifoBuffer->base;
                    }
                    else
                    {
                        *stu = *(stu + 1);
                    }
                }
                FifoBuffer->count--;
                flag = 1;
                break;
           }

           if(stu == (FifoBuffer->base + (FifoBuffer->length * sizeof(Element_Type))))
                stu = FifoBuffer->base;
           else
                stu++;
       }
       if(flag)
       {
          printf(" [INFO] Deleting a student by ID:%d is done successfully\n ",id);
       }
       else
       {
          printf(" [ERROR] The ID : %d is not found !\n",id);
       }

   }


}

//Student_Status_t FIFO_EditStudentData_ByID(FIFO_Buffer_t* FifoBuffer , int id , Element_Type* data)

void FIFO_UpdateStudent_ByID(FIFO_Buffer_t* FifoBuffer )
{
       Element_Type* stu;
       FIFO_Status_t status;
       int id;
       status = FIFO_IsEmpty(FifoBuffer);
       if(status == FIFO_null || status == FIFO_empty)
       {
           printf("\n [ERROR] Deleting student by ID number failed\n");
           return;
       }
       else
       {
           printf(" Enter ID Number: ");
           scanf("%d",&id);
           stu = Search_ByID(FifoBuffer,id);
           if(stu)
           {
               printf(" The old student data:\n");
               Print_StudentInfo(stu);

               printf("\n Updating a student with ID number %d ......\n\n",id);

               printf(" Enter the new first name: ");
               scanf("%s",stu->First_Name);

               printf(" Enter the new last name: ");
               scanf("%s",stu->Last_Name);

               printf(" Enter the new GPA: ");
               scanf("%f",&stu->GPA);

               printf(" Enter the new Courses IDs\n ");
               for(int i = 0 ; i < MAX_COURSES_NUM ; i++)
               {
                   printf(" Enter the course (%d) ID: ",i+1);
                   scanf("%d",&stu->Course_ID[i]);
               }
               printf(" The student data is updated successfully\n");
           }
           else
           {
                printf(" [ERROR] The student ID is not found\n");
           }

       }

}

void FIFO_UpadteStudentFile(FIFO_Buffer_t* FifoBuffer)
{
    Element_Type* stu;
    Update_Student = fopen("Student_data.txt","w");
    if(!Update_Student)
    {
        printf("\n [ERROR] File is not found\n [ERROR] Updating students file failed\n");
        return;
    }
    stu = FifoBuffer->tail;
    for(int i = 0 ;  i < FifoBuffer->count ; i++)
    {
        fprintf(Update_Student,"%d ",stu->ID);
        fprintf(Update_Student,"%s ",stu->First_Name);
        fprintf(Update_Student,"%s ",stu->Last_Name);
        fprintf(Update_Student,"%0.1f ",stu->GPA);
        for(int j = 0 ; j < MAX_COURSES_NUM ; j++)
        {
            fprintf(Update_Student,"%d ",stu->Course_ID[j]);
        }
        fprintf(Update_Student,"\n");

        if(stu == (FifoBuffer->base + (FifoBuffer->length * sizeof(Element_Type))))
            stu = FifoBuffer->base;
        else
            stu++;
    }
    printf(" [INFO] Students file updated successfully\n");
    fclose(Update_Student);
}

void FIFO_PrintAll(FIFO_Buffer_t* FifoBuffer)
{
    Student_t* temp;
    temp =FifoBuffer->base;
    printf("%d\n==================================\n",FifoBuffer->count);
    for(int i = 0 ; i < FifoBuffer->count ; i++)
    {
        printf("\nStudent [%d]:\n",i+1);
        printf("Name: %s %s\nID  : %d\nGPA : %.1f\n",temp->First_Name,temp->Last_Name,temp->ID,temp->GPA);
        for(int j = 0 ; j < 5 ; j++)
        {
            printf("Course[%d] ID is : %d\n",j+1,temp->Course_ID[j]);
        }
        temp++;
    }
    printf("\n==================================\n");
}
