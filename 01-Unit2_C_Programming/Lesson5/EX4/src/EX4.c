/*
 ============================================================================
 Name        : EX4.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Power( int base , int power)
{
	if( power == 1)
		return base;
	return base * Power(base , power-1);
}

int main(void) {

	int num1, num2;
	printf("Enter base number: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&num1);
	printf("Enter power number(positive integer) :");
	fflush(stdout); fflush(stdin);
	scanf("%d",&num2);
	printf("%d^%d = %d",num1,num2,Power(num1,num2));
	return EXIT_SUCCESS;
}
