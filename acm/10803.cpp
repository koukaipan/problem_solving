/* all pair shortest path floyd Warshall */

#include <stdio.h>
#include <math.h>

#define INFINITE 2147483647
#define MAX 102
int main()
{
	int arr[MAX][2];
	double distance[MAX][MAX], tmp;
	int i, j, k, n, l, num_case;
	scanf("%d", &l);
	for(num_case=1; num_case<=l; num_case++)
	{
		scanf("%d", &n);
		for(i=1; i<=n; i++)
			scanf("%d %d", &arr[i][0], &arr[i][1]);

		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(i>j)
					distance[i][j] = distance[j][i];
				else if(i==j)
					distance[i][j] = 0;
				else
				{
					tmp = sqrt((arr[i][0]-arr[j][0])*(arr[i][0]-arr[j][0])+(arr[i][1]-arr[j][1])*(arr[i][1]-arr[j][1]));
					if(tmp>10)
						distance[i][j] = INFINITE;
					else
						distance[i][j] = tmp;
				}
			}
		}
	
		/* calculate shortest path using floyd*/
		for(k=1; k<=n; k++)
			for(i=1; i<=n; i++)
				for(j=1; j<=n; j++)
					if(distance[i][k] + distance[k][j] < distance[i][j])
						distance[i][j] = distance[i][k] + distance[k][j];


		tmp = distance[1][2];
		for(i=1; i<=n; i++)
			for(j=i+1; j<=n; j++)
				if(distance[i][j] > tmp)
					tmp = distance[i][j];

		printf("Case #%d:\n", num_case);
		if(tmp < INFINITE)
			printf("%.4lf\n\n", tmp);
		else
			printf("Send Kurdy\n\n");
	}/* end of for*/

	return 0;
}

