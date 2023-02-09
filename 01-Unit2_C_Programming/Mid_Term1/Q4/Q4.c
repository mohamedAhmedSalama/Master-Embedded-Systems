/*
 ============================================================================
 Name        : mid.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Mid term1 Q4, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Reverse(int num)
{
	int NewNum =0 , rem;
	while(num != 0)
	{
		rem = num%10;
		NewNum = NewNum*10 + rem;
		num/=10;
	}
	return NewNum;
}

int main(void) {
	int n1 ;
	scanf("%d",&n1);
	fflush(stdin); fflush(stdout);
	printf("%d",Reverse(n1));
	return EXIT_SUCCESS;
}
