/* dp, from right to left */

#include <stdio.h>

int min(int, int);

int m,n;
int map[15][100], cost[15][100];
unsigned char pi[10][100];			/*predecessor*/

main()
{
	int i, j, k;
	freopen("116.txt", "r", stdin);
	//freopen("116_out.txt", "w", stdout);

	while(scanf("%d %d", &m, &n)!=EOF)
	{
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				scanf("%d", &map[i][j]);

		for (i=0,j=n-1; i<m; i++) 
			cost[i][j] = map[i][j];

		for (j=n-2; j>=0; j--)
		{
			for (i=0; i<m; i++)
			{
				k = min(i,j);
				cost[i][j] = map[i][j] + cost[k][j+1];
			}
		}
		for(k=0, i=1, j=0; i<m; i++)
			if(cost[k][j] > cost[i][j])
				k = i;
		/*print(k,j);*/
		for(i=k, j=0; j<n-1; j++)
		{
			printf("%d ", i+1);
			i=pi[i][j];
		}
		printf("%d\n%d\n", i+1, cost[k][0]);
	}
}

int min(int i, int j)
{
	int k;
	k = (i+m-1)%m;
	if(cost[k][j+1] > cost[i][j+1] || (cost[k][j+1] == cost[i][j+1] && i<k))
		k = i;
	if(cost[k][j+1] > cost[(i+1)%m][j+1] || (cost[k][j+1] == cost[(i+1)%m][j+1] && (i+1)%m<k))
		k = (i+1)%m;
	
	pi[i][j] = k;
	return k;
}

