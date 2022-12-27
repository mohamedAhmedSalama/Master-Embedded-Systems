/*
 ============================================================================
 Name        : EX3.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void reverseString()
{
	char ch;
	scanf("%c",&ch);
	if(ch != '\n')
	{
		reverseString();
		printf("%c",ch);
	}
}

int main(void) {

	printf("Enter a sentence: ");
	fflush(stdout); fflush(stdin);
	reverseString();

	return EXIT_SUCCESS;
}
