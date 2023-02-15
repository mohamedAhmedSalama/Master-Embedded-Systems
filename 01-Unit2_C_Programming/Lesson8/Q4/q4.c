/*
 ============================================================================
 Name        : L8.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Lesson8 Q4, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 15
int main(void) {
	int arr[MAX] , n;
	int *ptr = arr;
	printf("Input the number of elements to store in the array (max 15) :");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);
	printf("Input %d number of elements in the array: \n",n);
	for(int i = 0 ; i < n ; i++)
	{
		printf("element - %d :",i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d",ptr);
		ptr++;
	}
	printf("The elements of array in reverse order are :\n");
	ptr = &arr[n-1];
	for(int i = 0 ; i < n ; i++)
	{
		printf("element - %d : %d\n",i+1,*ptr);
		ptr--;
	}


	return EXIT_SUCCESS;
}
