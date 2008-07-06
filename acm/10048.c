/* Floyd Warshall all pair shortest path */

#include <stdio.h>

#define MAXNODE 102
#define INT_MAX 1073741823

int map[MAXNODE][MAXNODE];

int main()
{
	int i, j, k, n_case=1;
	int a, b, c;
	int n_vertex, n_street, n_problem;
	freopen("10048.txt", "r", stdin);

	for(scanf("%d %d %d", &n_vertex, &n_street, &n_problem);
		n_vertex!=0 || n_street!=0 || n_problem!=0;
		scanf("%d %d %d", &n_vertex, &n_street, &n_problem))
	{
		for(i=0; i<=n_vertex; i++)
			for(j=0; j<=i; j++)
				map[i][j] = map[j][i] = 0;

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
					if(i!=j && map[i][k] && map[k][j])
					/* 原本無路徑 || 原本路徑噪音比繞路大 */
					if(!map[i][j] || map[i][j]>( map[i][k]>map[k][j]?map[i][k]:map[k][j]))
					{
						/* 選大的 */
						map[i][j] = map[i][k]>map[k][j] ? map[i][k] : map[k][j] ;

					}
				}
		/* solve */
		if(n_case>1)
			printf("\n");
		printf("Case #%d\n", n_case++);
		for(i=0; i<n_problem; i++)
		{
			scanf("%d %d", &a, &b);
			if(map[a][b]) 
				printf("%d\n", map[a][b]) ;
			else
				printf("no path\n");

		}
	}
	return 0;
}