/* disjoint set */
#include <stdio.h>

#define MAXINT		2147483647
#define MAXV		50000

int set[MAXV];	/* for disjoint set */
int indegree[MAXV];
bool used[MAXV];
int n_vertices;
int n_edges;

main()
{
	int num_case = 1;
	int x, y, i, j;
	bool flag;
	int root;

	//freopen("615.in", "r", stdin);
	//freopen("615_out.txt", "w", stdout);

	while(scanf("%d %d", &x, &y)&& x>=0 && y>=0)
	{
		/* initialize */
		flag = 1;
		root = n_vertices = n_edges = 0;
		for(i=0; i<MAXV; i++)
		{
			set[i] = i+1;
			used[i] = indegree[i] = 0;
		}

		/* input */
		for(; x && y; scanf("%d %d", &x, &y))
		{
			if(x > n_vertices || y > n_vertices)
				n_vertices = x>y ? x : y;
			//map[x][y] = 1;
			indegree[y]++;
			used[x] = used[y] = 1;
			if(set[x]!=set[y])
			{
				/* ��Ҧ���y�I�ۦP��set �s��a�I��set */
				j = set[y];	/*�������קK���set[y] */
				for(i=1;i<=n_vertices;i++)
					if(set[i]==j)
						set[i]=set[x];
			}
		}
		
		/* check */
		/* ��root, �䦳�S��indegree>1 */
		for(i=1; i<=n_vertices && flag; i++)
		{
			if(indegree[i]==0 && used[i])
				x=i, root++;
			if(indegree[i] > 1 || root > 1)
				flag = false;
		}
		/* �W�L1��root �άOroot��0 �ӥB�S�������I */
		if(root > 1 || (n_vertices!=0 && root==0))
			flag = false;
		/* �Ҧ����I�n��root (x)�P�@��set */
		if(flag)
		{
			for(i=1;i<=n_vertices;i++)
				if(used[i] && set[x]!=set[i])
					flag = 0;			
		}


		printf("Case %d is %s\n", num_case++, flag? "a tree." : "not a tree.");
	}
}


