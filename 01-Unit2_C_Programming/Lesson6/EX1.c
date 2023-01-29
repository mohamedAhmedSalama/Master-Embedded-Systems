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
	struct Student stu;
	printf("Enter information of students:\n");
	fflush(stdout); fflush(stdin);
	printf("Enter Name: ");
	fflush(stdout); fflush(stdin);
	scanf("%s",stu.Name);
	printf("Enter roll number: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&stu.RollNo);
	printf("Enter marks: ");
	fflush(stdout); fflush(stdin);
	scanf("%f",&stu.Marks);
	printf("Displaying information of students:\n");
	fflush(stdout);
	printf("Name: %s\n",stu.Name);
	fflush(stdout);
	printf("Roll: %d\n",stu.RollNo);
	fflush(stdout);
	printf("Marks: %.1f\n",stu.Marks);
	return EXIT_SUCCESS;
}
