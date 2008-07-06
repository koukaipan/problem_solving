/* lcs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10


int sort_f( const void *a , const void *b ) 
{
	return *(char *)a - *(char *)b ;
}

#define LEFT_UP 0
#define UP		1
#define LEFT	2


void print_lcs(int b[][MAX], char str[], int i, int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==LEFT_UP)
	{
		print_lcs(b, str, i-1, j-1);
		printf("%c", str[i-1]);
	}
	else if(b[i][j]==UP)
		print_lcs(b, str, i-1, j);
	else
		print_lcs(b, str, i, j-1);
}

int lcs(char str1[], char str2[])
{
	int m = strlen(str1);
	int n = strlen(str2);
	int b[MAX][MAX], c[MAX][MAX];
	int i, j;

	for(i=0; i<=m; i++)	c[i][0]=0;
	for(i=0; i<=n; i++)	c[0][i]=0;

	for(i=1; i<=m ; i++)
		for(j=1; j<=n; j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = LEFT_UP;
			}
			/* choose the larger one */
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = UP;
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = LEFT;
			}
		}

	print_lcs(b, str1, strlen(str1), strlen(str2));
	return c[m][n];
}


main()
{
	char str1[MAX], str2[MAX];
	freopen("10252.txt", "r", stdin);
	while(gets(str1))
	{
		gets(str2);

		/* sort */
		qsort((void*)str1, strlen(str1), sizeof(char), sort_f);
		qsort((void*)str2, strlen(str2), sizeof(char), sort_f);

		/* LCS */
		lcs(str1, str2);
		putchar('\n');
	}
}