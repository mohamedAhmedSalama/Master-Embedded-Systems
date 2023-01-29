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

struct Number{
	float real;
	float img;
};
struct Number add(struct Number n1 , struct Number n2)
{
	struct Number s;
	s.real = n1.real + n2.real ;
	s.img = n1.img + n2.img;
	return s;
}
int main(void) {
	struct Number num1, num2,sum;
	printf("Enter 1st complex number:\n");
	fflush(stdout); fflush(stdin);
	scanf("%f%f",&num1.real,&num1.img);
	printf("Enter 2nd complex number:\n");
	fflush(stdout); fflush(stdin);
	scanf("%f%f",&num2.real,&num2.img);
	sum = add(num1,num2);
	printf("Sum = %.1f+%.1f i",sum.real,sum.img);
	return EXIT_SUCCESS;
}
