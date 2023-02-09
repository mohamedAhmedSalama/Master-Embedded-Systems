 /*
 ============================================================================
 Name        : mid.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Mid term1 Q6, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Unique(int arr[], int size)
{
	int FreqArr[50] = {0} , i , least = 9999 , num;
	for( i = 0 ; i < size ; i++)
	{
		FreqArr[arr[i]]++;
	}
	for( i = 0 ; i < size ; i++)
	{
		if(FreqArr[arr[i]] < least)
		{
			least = FreqArr[arr[i]];
			num = arr[i];
		}
	}
	return num ;
}

int main(void) {
	int arr1[7] = {4,2,5,2,5,7,4} ;
	int arr2[3] = {4,2,4};

	printf("%d\n",Unique(arr1,7));
	fflush(stdin); fflush(stdout);
	printf("%d",Unique(arr2,3));
	fflush(stdin); fflush(stdout);
	return EXIT_SUCCESS;
}
