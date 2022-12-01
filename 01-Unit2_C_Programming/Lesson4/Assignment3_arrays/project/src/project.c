/*
 ============================================================================
 Name        : project.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Solution of assignment 3(arrays)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float arr1[2][2] = {0}, arr2[2][2] = {0} ;
	int original_matrix[20][20] = {0} , Transpose_matrix[20][20] = {0};
	int i = 0, j = 0 , no_data = 0 , Rows , Cols , Matrix[20] = {0} , Matrix_copy[20] ={0} , num , pos;
	float arr[20]={0} , sum = 0 , Average = 0;
	//Ex1
		printf("Enter Elements of 1st matrix\n");
		fflush(stdout); fflush(stdin);
		for( i  = 0 ; i < 2 ; i++ )
		{
			for(j = 0 ; j < 2 ; j++)
			{
				printf("Enter a%d%d : ",i+1,j+1);
				fflush(stdout);
				scanf("%f",&arr1[i][j]);
				fflush(stdin);
			}
		}
		printf("Enter Elements of 2nd matrix\n");
		fflush(stdout); fflush(stdin);
		for( i  = 0 ; i < 2 ; i++ )
			{
				for(j = 0 ; j < 2 ; j++)
				{
					printf("Enter b%d%d : ",i+1,j+1);
					fflush(stdout);
					scanf("%f",&arr2[i][j]);
					fflush(stdin);
				}
			}
		printf("Sum Of Matrix : \n");
		for( i  = 0 ; i < 2 ; i++ )
			{
				for(j = 0 ; j < 2 ; j++)
				{
					printf("%.1f\t",arr1[i][j]+arr2[i][j]);
					fflush(stdout);
				}
				printf("\n");
			}
		printf("########################################################################\n");
		//-----------------------------------------------------------------------------------
	//EX2
		printf("Enter the numbers of data : ");
		fflush(stdout); fflush(stdin);
		scanf("%d",&no_data);
		for(i = 0 ; i <  no_data ; i++)
		{
			printf("%d. Enter Number: ",i+1);
			fflush(stdout); fflush(stdin);
			scanf("%f",&arr[i]);
			sum += arr[i];
		}
		Average =  sum / no_data ;
		printf("Average = %.2f",Average);
		printf("########################################################################\n");
		//-----------------------------------------------------------------------------------
	//EX3
		printf("Enter rows and column of matrix : ");
		fflush(stdout);	 fflush(stdin);
		scanf("%d%d",&Rows,&Cols);
		fflush(stdout);	 fflush(stdin);
		printf("Enter elements of matrix: \n");
		fflush(stdout);
		for( i = 0 ; i < Rows ;  i++)
		{
			for ( j = 0 ; j < Cols ; j++)
			{
				printf("Enter element of a%d%d : ",i+1,j+1);
				fflush(stdout);	 fflush(stdin);
				scanf("%d",&original_matrix[i][j]);
			}
		}
		printf("Entered matrix: \n");
		fflush(stdout);
		for( i = 0 ; i < Rows ;  i++)
		{
			for ( j = 0 ; j < Cols ; j++)
			{
				printf("%d\t",original_matrix[i][j]);
				fflush(stdout);
			}
			printf("\n");
		}

		for( i = 0 ; i < Rows ;  i++)
		{
			for( j = 0 ; j < Cols ; j++)
			{
				Transpose_matrix[j][i] = original_matrix[i][j];
			}
		}
		printf("Transpose matrix: \n");
		fflush(stdout);
		for (i = 0 ; i < Cols ; i++)
		{
			for (j = 0 ; j < Rows ; j++)
			{
				printf("%d\t",Transpose_matrix[i][j]);
			}
			printf("\n");
		}
		printf("########################################################################\n");
		//-----------------------------------------------------------------------------------
	//EX4
		printf("Enter no of elements : ");
		fflush(stdout);  fflush(stdin);
		scanf("%d",&no_data);
		for(i = 0 ; i < no_data ; i++)
		{
			scanf("%d",&Matrix[i]);
		}
		printf("Enter the element to be inserted : ");
		fflush(stdout);  fflush(stdin);
		scanf("%d",&num);
		printf("Enter the location : ");
		fflush(stdout);  fflush(stdin);
		scanf("%d",&pos);
		pos--;
		j=0;
		for(i = 0 ; i < no_data ; i++)
		{
			if(pos == i)
			{
				Matrix_copy[i]= num;
				i--;
				pos=-9;
			}
			else
				Matrix_copy[j] = Matrix[i];
			j++;

		}
		for(i = 0 ; i <= no_data ; i++)
		{
			printf("%d\t",Matrix_copy[i]);
		}
		printf("########################################################################\n");
		//-----------------------------------------------------------------------------------
	//EX5
		printf("Enter no of elements : ");
		fflush(stdout);   fflush(stdin);
		scanf("%d",&no_data);
		printf("Enter elements : \n");
		fflush(stdout);   fflush(stdin);
		for(i = 0 ; i < no_data ; i++)
		{
			scanf("%d",&Matrix[i]);
		}
		printf("Enter the elements to be searched: ");
		fflush(stdout);   fflush(stdin);
		scanf("%d",&num);
		pos = -1;
		for(i = 0 ; i < no_data ; i++)
		{
			if(Matrix[i] == num)
			{
				pos = i+1;
			}
		}
		if( pos > 0)
		{
			printf("Number found at the location = %d",pos);
		}
		else
		{
			printf("Number is not found");
		}
		printf("########################################################################\n");
		//-----------------------------------------------------------------------------------

	return EXIT_SUCCESS;
}
