#include<stdio.h>
#include<string.h>

bool s1[10][10],		//該列的0-9有沒有被用過
	 s2[10][10],		//該行的0-9有沒有沒用過
	 s3[4][4][10];		//該區塊的0-9有沒有被用過
int map[10][10], last, answer;
int n, n_square;

void set(int i,int j,int v)
{
	s1[j][v] = s2[i][v] = true;
	s3[(i-1)/n][(j-1)/n][v] = true;
 	map[i][j] = v;
}

void del(int i,int j,int v)
{
	s1[j][v] = s2[i][v] = false;
	s3[(i-1)/n][(j-1)/n][v] = false;
	map[i][j] = 0;
}
void print()
{
	int i,j;
	for(i=1;i<=n_square;i++,putchar('\n'))
	{
		for(j=1;j<n_square;j++)
			printf("%d ", map[i][j]);
		printf("%d", map[i][j]);
	}
}

void find_solution()
{
	int i,j,v;
	if(answer>1)
		return ;
	for(i=1;i<=n_square;i++)
		for(j=1;j<=n_square;j++)
			if(!map[i][j])
			{
				for(v=1;v<=n_square;v++)
					if(!s1[j][v] && !s2[i][v] && !s3[(i-1)/n][(j-1)/n][v])
							set(i,j,v),find_solution(),del(i,j,v);
				return ;
			}
	answer++;
	if(answer==1) print();
}

int main()
{
	int i, j, v, Illegal, PE_flag=0;
	freopen("989.txt", "r", stdin);
	while(scanf("%d", &n)!=EOF)
	{	
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(s3,0,sizeof(s3));
		memset(s3,0,sizeof(map));
		n_square = n*n;
			Illegal=0;
   		for(i=1;i<=n_square;i++)
   			for(j=1;j<=n_square;j++)
   			{
   				scanf("%d",&v);
    				map[i][j]=v;
				if(v && !Illegal)
				{		
   					if(s1[j][v] || s2[i][v] || s3[(i-1)/n][(j-1)/n][v])
						Illegal=1;
					else 
						set(i,j,v);
				}
   			}
		if(PE_flag)
			printf("\n");
		else
			PE_flag = 1;
		if(Illegal)
			printf("NO SOLUTION\n");
		else
		{
			answer=0;
      			find_solution();
			if(answer==0)
				printf("NO SOLUTION\n");
		}
	}
	return 0;
}