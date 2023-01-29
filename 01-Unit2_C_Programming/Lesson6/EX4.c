/*
 ============================================================================
 Name        : lesson6.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Lesson 6, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Student{
	char Name[30];
	int RollNo;
	float Marks;
};
int main(void) {
	struct Student stu[10];
	printf("Enter information of students:\n");
	fflush(stdout); fflush(stdin);
	for(int i = 0 ; i < 10 ; i++)
	{
		printf("Enter Name: ");
		fflush(stdout); fflush(stdin);
		scanf("%s",stu[i].Name);
		printf("Enter roll number: ");
		fflush(stdout); fflush(stdin);
		scanf("%d",&stu[i].RollNo);
		printf("Enter marks: ");
		fflush(stdout); fflush(stdin);
		scanf("%f",&stu[i].Marks);
	}
	printf("Displaying information of students:\n");
	fflush(stdout);
	for(int i = 0 ; i < 10 ; i++)
	{
		printf("Name: %s\n",stu[i].Name);
		fflush(stdout);
		printf("Roll: %d\n",stu[i].RollNo);
		fflush(stdout);
		printf("Marks: %.1f\n",stu[i].Marks);
	}
	return EXIT_SUCCESS;
}
