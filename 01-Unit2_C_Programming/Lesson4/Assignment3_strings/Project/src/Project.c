/*
 ============================================================================
 Name        : Project.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Solution of Assignment3(Strings)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char data_string[100]={0} , ch ,ch1 , ch2;
	char str1[100],str2[100];
	int i = 0 , j , l ,count = 0 , temp;
	//EX1
		printf("Enter a string: ");
		fflush(stdout);  fflush(stdin);
		gets(data_string);
		printf("Enter a character to find frequency: ");
		fflush(stdout);  fflush(stdin);
		scanf("%c",&ch);

		for(i = 0 ; data_string[i]!='\0' ; i++)
		{
			if(data_string[i] == ch)
			{
				count++;
			}
		}
		if(count > 0)
		{
			printf("Frequency of %c = %d\n",ch,count);
		}
		else
			printf("%c is not found\n",ch);
		printf("########################################################################\n");
		//-----------------------------------------------------------------------------------
	//EX2
		printf("Enter a string: ");
		fflush(stdout);  fflush(stdin);
		gets(data_string);
		for( i = 0 ; data_string[i] != '\0' ; i++)
		{
			count++;
		}
		printf("Length of string : %d\n",count);
		printf("########################################################################\n");
		//-----------------------------------------------------------------------------------
//EX3
	printf("Enter a string: ");
	fflush(stdout);  fflush(stdin);
	gets(str1);
	l = strlen(str1);
	j = l - 1 ;
	for(i = 0 ; i < l/2 ; i++)
	{
		temp = str1[i];
		str1[i] = str1[j];
		str1[j] = temp;
		j--;
	}
	printf("Reverse string is :%s",str1);
	printf("########################################################################\n");
	//-----------------------------------------------------------------------------------
	return EXIT_SUCCESS;
}
