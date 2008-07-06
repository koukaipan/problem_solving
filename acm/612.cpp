#include <stdio.h>

int main()
{
	char str[110][55];
	int sort[110];
	int num_data;
	int n,	/* length of string */
		m;	/* number of string */
	int min;
	int i, j, k;
	bool pe_flag = false;
	freopen("612.txt", "r", stdin);
	for(scanf("%d", &num_data); num_data; num_data--)
	{
		/* initialize */
		for(i=0; i<110; i++)
			sort[i] = 0;
		scanf("%d %d", &n, &m);
		for(i=0; i<m; i++)
		{
			scanf("%s", &str[i]);
			for(j=0; j<n-1; j++)
			{
				for(k=j+1; k<n; k++)
				{
					if(str[i][j]>str[i][k])
						sort[i]++;
				}
			}
		}
		for(i=0; i<m; i++)
		{
			min=0;
			for(j=0; j<m; j++)
				if(sort[j]<sort[min])
					min = j;
			printf("%s\n", str[min]);
			sort[min]=999999999;
		}
		if(num_data>1)
			printf("\n");
	}

	return 0;
}
