/*
 ============================================================================
 Name        : L8.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Lesson8 Q3, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char str1[30] , str2[30];
	char *pstr1 = str1;
	char *pstr2 = str2;
	int len = -1;
	printf("Enter a string : ");
	fflush(stdout); fflush(stdin);
	gets(str1);
	while(*pstr1)
	{
		pstr1++;
		len++;
	}
	while(len >= 0)
	{
		pstr1--;
		*pstr2 = *pstr1;
		pstr2++;
		len--;
	}
	*pstr2 = 0;
	printf("Reverse of the string is : %s",str2);

	return EXIT_SUCCESS;
}
