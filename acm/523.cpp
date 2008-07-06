/* Floyd Warshall */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNODE 200
#define INT_MAX 536870912
int p[MAXNODE][MAXNODE];
void output_path(int i, int j);

int main()
{
	int map[MAXNODE][MAXNODE];
	int tmp, num_case, n, i, j, k;
	int tax[MAXNODE];
	char c, line[MAXNODE];
	bool pe_flag=false;
	freopen("523.txt", "r", stdin);
	for(scanf("%d", &num_case);num_case; num_case--)
	{
		//input the first line
		n=0;
		do{
			++n;
			scanf("%d%c", &tmp, &c);
			map[1][n] = tmp>=0 ? tmp:INT_MAX;
			p[1][n] = 0;
		}while(c!='\n');
		//input the other line
		for(i=2; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf(" %d", &tmp);
				map[i][j] = tmp>=0 ? tmp:INT_MAX;
				p[i][j] = 0;
			}
		}
		//input the tax
		for(j=1; j<=n; j++)
			scanf(" %d", &tax[j]);

		//shortest path
		for(k=1; k<=n; k++)
			for(i=1; i<=n; i++)
				for(j=1; j<=n; j++)
					if(map[i][j] > map[i][k] + map[k][j] + tax[k])
					{
						map[i][j] = map[i][k] + map[k][j] + tax[k];
						p[i][j] = k;
					}

		gets(line);
		//output path
		while(gets(line)&&strlen(line))
		{
			if(!pe_flag)
				pe_flag = true;
			else
				printf("\n");
			i = atoi(strtok( line, " " ));
			j = atoi(strtok( NULL, " " ));
			printf("From %d to %d :\nPath: %d", i, j, i);
			output_path(i, j);
			printf("\nTotal cost : %d\n", map[i][j]);
		}
	}
	return 0;
}

void output_path(int i, int j)
{
	if(p[i][j]==0)
		printf("-->%d", j);
	else
	{
		output_path(i, p[i][j]);
		
		output_path(p[i][j], j);
	}
}
