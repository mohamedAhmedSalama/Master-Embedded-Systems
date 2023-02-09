/*
 ============================================================================
 Name        : mid.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Mid term1 Q10, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int Count(int num)
{
	int max = 0 , sum = 0;
	while(num!= 0)
	{
		if( num & 1)
		{
			sum++;
		}
		else
		{
			if(sum > max)
			{
				max = sum ;

			}

			sum = 0 ;
		}
		 num >>= 1 ;
	}
	if(sum > max)
	{
		max = sum ;

	}
	return max;
}

int main(void) {
	int number;
	scanf("%d",&number);
	printf("%d",Count(number));


	return EXIT_SUCCESS;
}
