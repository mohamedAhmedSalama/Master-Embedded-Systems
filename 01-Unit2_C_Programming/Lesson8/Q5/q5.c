 /*
 ============================================================================
 Name        : L8.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Lesson8 Q5, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Employee
{
	char Name[30];
	int ID;
};
int main(void) {
	struct Employee E = {"Alex" , 1002};
	struct Employee* ptr = &E;
	printf("Employee Name: %s\n", ptr->Name);
	fflush(stdout);
	printf("Employee ID: %d\n", ptr->ID);
	fflush(stdout);




	return EXIT_SUCCESS;
}
