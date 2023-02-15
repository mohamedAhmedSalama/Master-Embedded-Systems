/*
 ============================================================================
 Name        : L8.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Lesson8 Q1, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *ab , m = 29 ;
	 ab = &m;
	 printf("Now ab is assigned with the address of m\n");
	 fflush(stdout);
	 printf("Address of pointer ab : %p\n",ab);
	 fflush(stdout);
	 printf("content of pointer ab : %d\n\n",*ab);
	 fflush(stdout);
	 m = 34;
	 printf("The value of m assigned to 34 now\n");
	 fflush(stdout);
	 printf("Address of pointer ab : %p\n",ab);
	 fflush(stdout);
	 printf("content of pointer ab : %d\n\n",*ab);
	 fflush(stdout);
	 *ab = 7;
	 printf("The pointer variable ab is assigned with the value 7 now\n");
	 fflush(stdout);
	 printf("Address of pointer ab : %p\n",ab);
	 fflush(stdout);
	 printf("content of pointer ab : %d\n\n",*ab);
	 fflush(stdout);

	return EXIT_SUCCESS;
}
