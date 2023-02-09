 /*
 ============================================================================
 Name        : mid.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Mid term1 Q7, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Sum(int num)
{
	int sum = 0;
	sum  = (num * (num + 1))/2 ;
	return sum;
}

int main(void) {
	int n ;
	scanf("%d",&n);
	fflush(stdin); fflush(stdout);
	printf("%d",Sum(n));
	fflush(stdin); fflush(stdout);
	return EXIT_SUCCESS;
}
