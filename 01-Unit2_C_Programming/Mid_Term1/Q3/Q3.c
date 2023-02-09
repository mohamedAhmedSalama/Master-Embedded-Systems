/*
 ============================================================================
 Name        : mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Mid term1 Q3, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int IsPrime(int num)
{
	if(num == 1)
		return 1;
	else if (num == 0)
		return 0;
	else
	{
		for(int i = 2 ; i < num ; i++)
		{
			if(num % i == 0)
				return 0;
		}
		return 1;
	}
}
void Prime(int num1 , int num2)
{
	for(int i =  num1 ; i <= num2 ; i++)
	{
		if(IsPrime(i) == 1)
			printf("%d ", i);
	}
}

int main(void) {
	int n1 , n2;
	scanf("%d%d",&n1,&n2);
	fflush(stdin); fflush(stdout);
	Prime(n1, n2);
	return EXIT_SUCCESS;
}
