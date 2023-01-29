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

#define Area(r)		(r*r*3.14)
int main(void) {
	int radius;
	printf("Enter radius: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&radius);
	printf("Area= %0.2lf",Area(radius));
	return EXIT_SUCCESS;
}
