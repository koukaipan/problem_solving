/* brute force */

#include <stdio.h>
#include <string.h>

int main()
{
	int row, col;
	char ch;
	char map[110][110];
	int i, j;
	int num_case=0;
	bool pe_flag=0;

	for(scanf("%d %d", &row, &col);row!=0 && col!=0;scanf("%d %d", &row, &col))
	{
		memset(map, 0, sizeof(char)*110*110);
		scanf("%c", &ch);
		/* input */
		for(i=1; i<=row; i++)
		{
			for(j=1; j<=col; j++)
			{
				scanf("%c", &ch);
				if(ch=='*')
				{
					map[i][j]=99;
					map[i-1][j-1]++;	map[i-1][j]++;	map[i-1][j+1]++;
					map[i][j-1]++;		map[i][j]++;	map[i][j+1]++;
					map[i+1][j-1]++;	map[i+1][j]++;	map[i+1][j+1]++;
				}
			}
			scanf("%c", &ch);
		}
	
		/* output */
		if(!pe_flag)
			pe_flag = true;
		else
			printf("\n");
		printf("Field #%d:\n", ++num_case);
		for(i=1; i<=row; i++)
		{
			for(j=1; j<=col; j++)
				if(map[i][j]<99)
					printf("%d", map[i][j]);
				else
					printf("*");
			printf("\n");
		}
	}
	return 0;
}