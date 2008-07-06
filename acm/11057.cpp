/* sort, binary search */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int compare( const void *x , const void *y ) 
{
	if(*(int *)x<*(int *)y)			return -1;
	else if(*(int *)x==*(int *)y)	return 0;
	else							return 1;
}

int b_search(int list[], int key, int n)
{
	int left=0, right=n, middle;
	while(left<=right)
	{
		middle = (right + left) / 2;
		switch(compare(&list[middle], &key))
		{
		case -1:	left = middle + 1;	break;
		case  0:	return middle;
		case  1:	right = middle - 1;
		}
	}
	return -1;
}

int main()
{
	int n, target, i, j, k, min_difference, key;
	int p;
	int price[MAX];
	freopen("11057.txt", "r", stdin);

	while(scanf("%d", &n) != EOF)
	{
		/* input */
		for(i=0; i<n; i++)
			scanf("%d", &price[i]);
		scanf("%d", &target);

		/* sort it */
		qsort((void*)price, n, sizeof(int), compare);

		min_difference = target;
		/* find solution */
		for(k=0; k<n && price[k]<=target/2; k++)
		{
			key = target - price[k];
			p = b_search(price, key, n);
			if(p!=-1 && (price[p]-price[k])<min_difference)
			{
				min_difference = price[p]-price[k];
				i = price[k];
				j = price[p];
			}
		}
		/* output */
		printf("Peter should buy books whose prices are %d and %d.\n\n", i, j);		
	}

	return 0;
}