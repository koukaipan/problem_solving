#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5860

int sort_f( const void *a , const void *b ) 
{
	return *(int *)a - *(int *)b ;
}

main()
{
	int arr[MAX], count, n;
	double m;
	int i, j, k, l;	/* 2, 3, 5, 7 */

	freopen("443.in", "r", stdin);
	freopen("443_out.txt", "w", stdout);

	count = 1;
	for(i=0; i<MAX; i++)
		arr[i] = 2147483647;
	for(i=0; i<31; i++)
	{
		for(j=0; j<20; j++)
		{
			for(k=0; k<14; k++)
			{
				for(l=0; l<12; l++)
				{
					m = pow(2,i)*pow(3,j)*pow(5,k)*pow(7,l);
					if(m <= 2000000000.00+1e7)
						arr[count++] = (int)m;
				}
			}
		}
	}
	qsort((void*)arr, MAX, sizeof(int), sort_f);

	while(scanf("%d", &n) && n)
	{
		if(n%10==1 && n%100!=11)
			printf("The %dst humble number is %d.\n", n, arr[n-1]);
		else if(n%10==2 && n%100!=12)
			printf("The %dnd humble number is %d.\n", n, arr[n-1]);
		else if(n%10==3 && n%100!=13)
			printf("The %drd humble number is %d.\n", n, arr[n-1]);
		else
			printf("The %dth humble number is %d.\n", n, arr[n-1]);
		
	}
}

