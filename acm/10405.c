/* LCS */

#include <stdio.h>
#include <string.h>

#define MAX 1002

main()
{
	int m, n, c[MAX][MAX];
	int i, j;
	char str1[MAX], str2[MAX];
	freopen("10405.txt", "r", stdin);
	while(gets(str1) && gets(str2))
	{
		/* initialize */
		m = strlen(str1);
		n = strlen(str2);

		for(i=0; i<=m; i++)	c[i][0]=0;
		for(i=0; i<=n; i++)	c[0][i]=0;

		for(i=1; i<=m ; i++)
			for(j=1; j<=n; j++)
				if(str1[i-1]==str2[j-1])
					c[i][j] = c[i-1][j-1]+1;
				else	/* choose the larger one */
					c[i][j] = c[i-1][j] >= c[i][j-1] ? c[i-1][j] : c[i][j-1];

		printf("%d\n", c[m][n]);

	}
}