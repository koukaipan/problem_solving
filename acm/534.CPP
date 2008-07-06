#include<stdio.h>
#include<math.h>

#define MAX 201

struct s{
	int x,y;
}stone[MAX];

double find_max(double x,double y)
{
	return x>y ? x : y;
}

double find_min(double x,double y)
{
	if(x==0.0)
		return y;
	else
		return x<y ? x : y;
}


double dis[MAX][MAX];

double Dis(double x1,double x2,double y1,double y2)
{
	double  x = x1>x2 ? (x1-x2) : (x2-x1),
			y = y1>y2 ? (y1-y2) : (y2-y1);

	return pow( (x*x)+(y*y),0.5);

}

void main()
{
	int i,j,k,num_stone,cases=1;
//	freopen("d:\\test.txt","w",stdout);
	while(scanf("%d",&num_stone) && num_stone!=0)
	{
		//stone data input
		for(i=0;i<num_stone;i++)
			scanf("%d %d",&stone[i].x,&stone[i].y);
		
		//calculate all distance between one stone to another
		for(i=0;i<num_stone;i++)
			for(j=i+1;j<num_stone;j++)
				dis[i][j]=dis[j][i]=Dis(stone[i].x, stone[j].x, stone[i].y, stone[j].y);

		for(k=0;k<num_stone;k++)
			for(i=0;i<num_stone;i++)
				for(j=0;j<num_stone;j++)
					if(dis[i][k] && dis[k][j])
						dis[i][j]=find_min(dis[i][j],find_max(dis[i][k],dis[k][j]));

		//display
		printf("Scenario #%d\n",cases++);
		printf("Frog Distance = %.3lf\n",dis[0][1]);
		puts("");
	}

}