/* DP 
―绢硈尿计ヘ
1 0 0 1 0 0 1
5 4 3 2 1 0 1
0 5 4 3 2 1 0
1 0 4 3 2 1 0
0 0 3 2 1 0 1
0 0 1 0 0 2 1
硋碝т计璶よ┮ゲ斗耕祏非
eg. 3 2 1 0
    4 3 2 1
	璶3非
*/
#include <stdio.h>

#define MAX 100s

int main()
{
	int m, n, max_area;
	int i, j, k, width, height;
	int matrix[MAX][MAX];
	freopen("10074.txt", "r", stdin);
	for(scanf("%d %d", &m, &n); m!=0 && n!=0; scanf("%d %d", &m, &n))
	{
		/* input matrix */
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				scanf("%d", &matrix[i][j]);

		/*printf("k\n");*/
		/* pre process */
		max_area = 0;
		for (j=0;j<m;j++)
			for (k=0, i=n-1;i>=0;i--)
				matrix[j][i] = matrix[j][i]==0 ? ++k : k=0;

		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				if(matrix[i][j])
				{
					width = matrix[i][j];
					if(width > max_area)
						max_area = width;
					for(k=i+1, height=2; k<m; k++, height++)
						if(matrix[k][j])
						{
							if(width > matrix[k][j])	/*祏非 */
								width = matrix[k][j];
							if(width * height > max_area)
								max_area = width * height;
						}
						else
							break;
				}

		/*for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
				printf("%d ", matrix[i][j]);
			printf("\n");
		}*/
		printf("%d\n", max_area);

	}

	return 0;
}


