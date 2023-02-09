 /*
 ============================================================================
 Name        : mid.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Mid term1 Q5, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Count(int num)
{
	int sum = 0  ;
	while(num != 0)
	{
		if(num & 1 == 1)
			sum++;
		num = num >> 1;
	}
	return sum;
}

int main(void) {
	int n1 ;
	scanf("%d",&n1);
	fflush(stdin); fflush(stdout);
	printf("%d",Count(n1));
	return EXIT_SUCCESS;
}
