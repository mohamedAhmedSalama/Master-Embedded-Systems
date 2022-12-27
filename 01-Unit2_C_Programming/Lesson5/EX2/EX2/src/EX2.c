/*
 ============================================================================
 Name        : EX2.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int number)
{
	if( number == 0)
		return 1;
	return number * factorial(number-1);
}
int main(void) {

	int num ;
	printf("Enter an positive integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&num);
	printf("Factorial of %d = %d",num,factorial(num));

	return EXIT_SUCCESS;
}
