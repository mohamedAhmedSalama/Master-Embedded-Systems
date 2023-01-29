 /*
 ============================================================================
 Name        : lesson6.c
 Author      : Mohamed Ahmed Salama
 Version     :
 Copyright   : Your copyright notice
 Description : Lesson 6, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Distance{
	int feet;
	float inch;
};
int main(void) {
	struct Distance d1,d2,sum;
	printf("Enter information for 1st distance\n");
	fflush(stdout);
	printf("Enter feet: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&d1.feet);
	printf("Enter inch: ");
	fflush(stdout); fflush(stdin);
	scanf("%f",&d1.inch);
	printf("Enter information for 2nd distance\n");
	fflush(stdout);
	printf("Enter feet: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&d2.feet);
	printf("Enter inch: ");
	fflush(stdout); fflush(stdin);
	scanf("%f",&d2.inch);
	sum.feet = d1.feet + d2.feet;
	sum.inch = d1.inch + d2.inch;
	if(sum.inch > 12)
	{
		sum.inch -=12;
		sum.feet++;
	}
	printf("Sum of distances = %d feet - %.1f inches",sum.feet,sum.inch);
	return EXIT_SUCCESS;
}
