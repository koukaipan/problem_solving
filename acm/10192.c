/* LCS */

#include <stdio.h>
#include <string.h>

#define MAX 11

main()
{
	int num_case=1, m, n;
	int i, j;
	char c[MAX][MAX], t1[MAX], t2[MAX];

	freopen("10192.txt", "r", stdin);

	for(gets(t1); t1[0]!='#'; gets(t1))
	{
		/* input */
		gets(t2);
		/* initialize */
		m = strlen(t1);
		n = strlen(t2);

		for(i=0; i<=m; i++)	c[i][0]=0;
		for(i=0; i<=n; i++)	c[0][i]=0;

		for(i=1; i<=m ; i++)
			for(j=1; j<=n; j++)
				if(t1[i-1]==t2[j-1])
					c[i][j] = c[i-1][j-1]+1;
				else	/* choose the larger one */
					c[i][j] = c[i-1][j] >= c[i][j-1] ? c[i-1][j] : c[i][j-1];

		printf("Case #%d: you can visit at most %d cities.\n", num_case++, c[m][n]);

	}
}