// Eng. Mohamed Ahmed Salama
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FIFO.h"

#define MAX_STUDENTS_NUMBER 50


int main()
{

    Element_Type stu , Student_Data[MAX_STUDENTS_NUMBER];
    FIFO_Buffer_t Student_FIFO;
    FIFO_Status_t status;
    int flag = 0;
    int choice;


    printf("\n       * * * * * * * * * * * * * * * * * * * * * * * * *\n       * Welcome sir to the Student Management System  *\n       * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n");
    FIFO_Init(&Student_FIFO,Student_Data,MAX_STUDENTS_NUMBER);
    //FIFO_AddStudent_FromFile(&Student_FIFO);
    while(1)
    {
       printf("\n Choose one of the following :\n");
		printf("\n\t 1: Add Student Manually");
		printf("\n\t 2: Add Student From Text File");
		printf("\n\t 3: Find Student by ID Number");
		printf("\n\t 4: Find Student by First Name");
		printf("\n\t 5: Find Student by Course ID");
		printf("\n\t 6: Print Students Count");
		printf("\n\t 7: Delete Student by ID Number");
		printf("\n\t 8: Update Student by ID Number");
		printf("\n\t 9: View All Students");
		printf("\n\t 10: Exit");
		printf("\n\n Enter option number: ");
		scanf("%d",&choice);
        printf(" >>>\n\n\n");
		switch(choice)
		{
		    case 1:       //Add Student Manually
                FIFO_AddStudent_Manually(&Student_FIFO);
                break;
			case 2:      //Add Student From Text File
			    FIFO_AddStudent_FromFile(&Student_FIFO);
                break;
			case 3:     //Find Student by ID Number
			    FIFO_FindStudent_ByID(&Student_FIFO);
                break;
			case 4:     //Find Student by First Name
			    FIFO_FindStudent_ByFirstName(&Student_FIFO);
                break;
			case 5:     //Find Student by Course ID
			    FIFO_FindStudent_ByCourse(&Student_FIFO);
                break;
			case 6:     //Print Students Count
			    FIFO_PrintStudent_Count(&Student_FIFO);
                break;
			case 7:     //Delete Student by ID Number
			    FIFO_DeleteStudent_ByID(&Student_FIFO);
                break;
			case 8:     //Update Student by ID Number
			    FIFO_UpdateStudent_ByID(&Student_FIFO);
                break;
			case 9:     //View All Students
			    FIFO_PrintAll(&Student_FIFO);
                break;
			case 10:    //Exit
			    FIFO_UpadteStudentFile(&Student_FIFO);
			    printf(" [INFO] If you make any operation it has been saved in students file successfully\n");
			    printf(" See you soon :)\n");
			    flag = 1 ;
                break;
			default:
			    printf("\n Wrong Option!! Try Again \n\n");
			    break;
		}
        printf("_______________________________________________________________\n");
        if(flag)
            break;
    }


    return 0;
}
