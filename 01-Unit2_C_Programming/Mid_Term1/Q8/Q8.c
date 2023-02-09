/*
 ============================================================================
 Name        : mid.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Mid term1 Q8, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void Reverse(int arr[],int size)
{
	int TempArr[50] , i , j = 0;
	for(i = size-1 ; i >= 0 ; i--)
	{
		TempArr[j] = arr[i];
		j++;
	}
	for(i = 0 ; i < size ; i++)
	{
		arr[i] = TempArr[i];
	}
}

int main(void) {
	int arr[5] = {1,2,3,4,5};
	Reverse(arr,5);
	for(int i = 0 ; i< 5 ;i++)
	{
		printf("%d ",arr[i]);
		fflush(stdin); fflush(stdout);
	}

	return EXIT_SUCCESS;
}
