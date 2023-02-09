/*
 ============================================================================
 Name        :
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : MidTerm 1 Q1, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
unsigned int sum(unsigned int num)
{
	unsigned int sum= 0 ;
	while(num!=0)
	{
		sum += num%10;
		num/=10;
	}
	return sum;
}

int main(void) {
	int num;
	scanf("%d",&num);
	fflush(stdout); fflush(stdin);
	printf("%d\n",sum(num));





	return EXIT_SUCCESS;
}
