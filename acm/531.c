#include <stdio.h>
#include <string.h>

#define MAX 101
#define MAXLENGTH 31

#define LEFT_UP		'a'
#define UP			'u'
#define LEFT		'l'

char b[MAX][MAX];
char text1[MAX][MAXLENGTH], text2[MAX][MAXLENGTH];
int first;
void print(int, int);

main()
{
	int m, n, c[MAX][MAX];
	int i, j;

#ifdef WIN32
	freopen("531.in", "r", stdin);
	freopen("531_out.txt", "w", stdout);
#endif 

	m = n = 0;
	while(scanf("%s", text1[m++])!=EOF)
	{
		/* input */
		while(scanf("%s", text1[m]) && text1[m][0]!='#')
			m++;
		while(scanf("%s", text2[n]) && text2[n][0]!='#')
			n++;

		for(i=0; i<=m; i++)	c[i][0]=0;
		for(i=0; i<=n; i++)	c[0][i]=0;

		for(i=1; i<=m ; i++)
			for(j=1; j<=n; j++)
				if(!strcmp(text1[i-1], text2[j-1]))
				{
					c[i][j] = c[i-1][j-1]+1;
					b[i][j] = LEFT_UP;
				}
				else if(c[i-1][j] >= c[i][j-1])/* choose the larger one */
				{
					c[i][j] = c[i-1][j];
					b[i][j] = UP;
				}
				else
				{
					c[i][j] = c[i][j-1];
					b[i][j] = LEFT;
				}
		first = 0;
		print(m, n);
		printf("\n", c[m][n]);
		m = n = 0;
	}
}

void print(int i, int j)
{
	if(i==0 || j==0)
		return;
	if(b[i][j] == LEFT_UP)
	{
		print(i-1, j-1);
		if(first)
			printf(" %s", text1[i-1]);
		else
		{
			first = 1;
			printf("%s", text1[i-1]);
		}
	}
	else if(b[i][j] == UP)
		print(i-1, j);
	else
		print(i, j-1);
}
