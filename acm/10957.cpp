#include<stdio.h>
#include<string.h>

int s1[10][10],s2[10][10],s3[4][4][10];
int map[10][10],last,answer=0;

void set(int i,int j,int v)
{
	s1[j][v]=1;
	s2[i][v]=1;
	s3[(i-1)/3][(j-1)/3][v]=1;
 	map[i][j]=v;
}

void del(int i,int j,int v)
{
	s1[j][v]=0;
 	s2[i][v]=0;
  	s3[(i-1)/3][(j-1)/3][v]=0;
 	map[i][j]=0;
}
/*void print()
{
	int i,j;
	printf("\n¸Ñ:%d",answer);
	for(i=1;i<=9;i++)	
		for(j=1,puts("");j<=9;j++)
			printf("%d ",map[i][j]);    
	puts("");
}*/

void dfs()
{
	int i,j,v;
	if(answer>1)
		return ;
	for(i=1;i<=9;i++)
		for(j=1;j<=9;j++)
			if(!map[i][j])
			{
				for(v=1;v<=9;v++)
					if(!s1[j][v] && !s2[i][v] && !s3[(i-1)/3][(j-1)/3][v])
							set(i,j,v),dfs(),del(i,j,v);
				return ;
			}
	answer++;
	//print();
}
int main()
{
	int i, j, v, Illegal, cases=1;
	freopen("10957.txt","r",stdin);
	while(1)
	{	
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(s3,0,sizeof(s3));
		memset(s3,0,sizeof(map));

		Illegal=0;
    	for(i=1; i<=9; i++)
    		for(j=1; j<=9; j++)
    		{
    			if(scanf("%d",&v)==EOF)
    				return 0;
    			map[i][j]=v;
				if(v && !Illegal)
				{		
     				if(s1[j][v] || s2[i][v] || s3[(i-1)/3][(j-1)/3][v])
						Illegal=1;
					else 
						set(i,j,v);
				}				
    		}   
		printf("Case %d: ", cases++);
    	if(Illegal)
    		puts("Illegal.");
    	else
    	{
    		answer=0 , dfs();
			switch(answer)
			{
			case 0:	puts("Impossible.");	break;
			case 1:	puts("Unique.");		break;
			default:	puts("Ambiguous.");	break;
			}
		}

	}
}