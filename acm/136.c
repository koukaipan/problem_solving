#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1600

int sort_f( const void *a , const void *b ) 
{
	return *(int *)a - *(int *)b ;
}

main()
{
	int arr[MAX], count;
	double m;
	int i, j, k;	/* 2, 3, 5, 7 */

	for(i=0; i<MAX; i++)
		arr[i] = 2147483647;

	count = 1;
	for(i=0; i<31; i++)
	{
		for(j=0; j<20; j++)
		{
			for(k=0; k<14; k++)
			{
				m = pow(2,i)*pow(3,j)*pow(5,k);
				if(m <= 1000000000.00)
					arr[count++] = (int)m;
			}
		}
	}
	qsort((void*)arr, MAX, sizeof(int), sort_f);

	printf("The 1500'th ugly number is %d.\n", arr[1500-1]);

}

