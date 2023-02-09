/*
 ============================================================================
 Name        : mid.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Mid term1 Q9, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void Reverse(char* str)
{
	char TempArr[50];
	int i , j ,k, temp;
	for(i = 0 ;  str[i] ; i++)
	{
		if( str[i] == ' ')
		{
			temp = i ;
			temp++;
			for(j = 0 ; str[temp] ; j++ )
			{
				TempArr[j] = str[temp];
				temp++;
			}
			TempArr[j] = ' ';
			j++;
			for(k = 0 ; str[k] != ' ' ; k++ )
			{
				TempArr[j] = str[k];
				j++;
			}
			TempArr[j] = 0;
			break;
		}
	}
	for( i = 0 ; TempArr[i] ; i++)
	{
		str[i] = TempArr[i];
	}
	str[i] = 0;



}

int main(void) {
	char str[50];
	gets(str);
	fflush(stdout); fflush(stdin);
	Reverse(str);
	printf("%s",str);


	return EXIT_SUCCESS;
}
