 /*
 ============================================================================
 Name        : L8.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Lesson8 Q2, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char arr_alpha[27];
	char *ptr = arr_alpha;
	for (int i = 0 ; i < 26 ; i++)
	{
		*ptr = i + 'A';
		ptr++;
	}
	ptr = arr_alpha;
	printf("The Alphabets are :\n");
	fflush(stdout);
	for (int i = 0 ; i < 26 ; i++)
	{
		printf("%c ",*ptr); fflush(stdout);
		ptr++;
	}
	return EXIT_SUCCESS;
}
