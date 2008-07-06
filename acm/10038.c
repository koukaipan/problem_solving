#include <stdio.h>

#define MAX 10

int main()
{
	int n, 
		arr[MAX], check[MAX],
		i, tmp;

	while(scanf("%d", &n)==1)
	{
		//support ther are jolly

		for(i=0; i<n; i++)
		{
			check[i] = 0;
			scanf("%d", &arr[i]);
		}

		for(i=1; i<n; i++)
		{
			tmp = (arr[i]-arr[i-1]) > 0 ? (arr[i]-arr[i-1]) : (arr[i-1]-arr[i]);
			check[tmp] = 1;
		}

		for(i=1; i<n && check[i]; i++);
		if(i>=n)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}

	return 0;
}