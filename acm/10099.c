/* floyd warshall with variation */
#include <stdio.h>
#include <math.h>

#define MAXNODE 102
#define NO_PATH -1
#define MIN(x,y) ( x<y ? x : y )
int map[MAXNODE][MAXNODE];

int main()
{
	int i, j, k, n_case=1;
	int a, b, c;
	int n_vertex, n_street;
	int ans;
	freopen("10099.txt", "r", stdin);

	for(scanf("%d %d", &n_vertex, &n_street);
		n_vertex!=0 || n_street!=0;
		scanf("%d %d", &n_vertex, &n_street))
	{
		/* initialize */
		for(i=0; i<=n_vertex; i++)
			for(j=0; j<=i; j++)
				map[i][j] = map[j][i] = 0;

		/* input */
		for(i=0; i<n_street; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			map[a][b] = map[b][a] = c;
		}

		/*shortest path*/
		for(k=1; k<=n_vertex; k++)
			for(i=1; i<=n_vertex; i++)
				for(j=1; j<=n_vertex; j++)
				{
					if(MIN(map[i][k], map[k][j])>map[i][j])
						map[i][j] = MIN(map[i][k], map[k][j]);
				}
		/* process */
		scanf("%d %d %d", &a, &b, &c);/* a is start, b is end, c is num. of pessengers */
		ans = (int)ceil((double)c / (double)(map[a][b]-1));
		/* solve */
		printf("Scenario #%d\n", n_case++);
		printf("Minimum Number of Trips = %d\n\n", ans);
	}
	return 0;
}