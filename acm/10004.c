#include <stdio.h>

#define MAX	300
int map[MAX][MAX];
int color[MAX];
int flag,num_vertex;
void dfs(int go,int p);

main()
{
	int i, j, a, b;
	int n;
	while(scanf("%d", &num_vertex) && num_vertex)
	{
		scanf("%d", &n);
		flag = 1;
		for(i=0; i<n; i++)
		{
			color[i] = -1;
			for(j=0; j<n; j++)
				map[i][j] = 0;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d %d", &a, &b);
			map[a][b] = map[b][a] = 1;
		}
		dfs(0,1);
		if(flag) puts("BICOLORABLE.");
		else puts("NOT BICOLORABLE.");
	}
}


void dfs(int go,int p)		//go 是這個點 , p是這個顏色, 1是黑色, 0是白色
{
	int i;
	if(color[go]==-1)
		color[go]=p;
	else if(color[go]!=p)
		flag=0;
	if(flag==0) return;
	
	for(i=0;i<num_vertex;i++)
		if(map[go][i]==1)
			dfs(i,1-p);	

}
