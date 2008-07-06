/* LCS */

#include <stdio.h>

#define MAX 11

main()
{
	int num_case, n1, n2;
	int i, j;
	int c[MAX][MAX], t1[MAX], t2[MAX];

	freopen("10066.txt", "r", stdin);

	for(scanf("%d %d", &n1, &n2),num_case=0; n1&&n2; scanf("%d %d", &n1, &n2))
	{
		/* initialize and input */
		for(i=0; i<n1; i++)
		{
			scanf("%d", &t1[i]);
			c[i][0]=0;
		}
		c[i][0] = 0;
		for(i=0; i<n2; i++)
		{
			scanf("%d", &t2[i]);
			c[0][i]=0;
		}
		c[0][i] = 0;

		/* find LCS */
		for(i=1; i<=n1 ; i++)
			for(j=1; j<=n2; j++)
				if(t1[i-1]==t2[j-1])
					c[i][j] = c[i-1][j-1]+1;
				else	/* choose the larger one */
					c[i][j] = c[i-1][j] >= c[i][j-1] ? c[i-1][j] : c[i][j-1];

		/* output */
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++num_case, c[n1][n2]);
	}
}