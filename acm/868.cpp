#include <stdio.h>
#include <stack> 
using namespace std;

#define MAX 50

typedef struct{
	int x;
	int y;
}coord_;

int map[MAX][MAX];
int num_col, num_row;
int count, v;
//int v;
int i, j, x, y, end;
int num_case;
coord_ p;
stack <coord_> s;
bool finished;
const int val[210] = { 1, 1, 2, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 4, 5, 1, 2, 3, 
4, 5, 6, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 
9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1, 2, 3,
4, 5, 6, 7, 8, 9, 10, 11, 12,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 
3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 
12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 1, 2, 
3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 1, 2, 3, 4, 5, 6, 7, 8, 
9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
13, 14, 15, 16, 17, 18, 19, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
15, 16, 17, 18, 19, 20};

void go();

main()
{
#ifdef WIN32
	freopen("868.txt", "r", stdin);
#endif
	scanf("%d", &num_case);
	while(num_case--)
	{
		/* input */
		scanf("%d %d", &num_row, &num_col);

		for(i=0; i<num_row; i++)
			for(j=0; j<num_col; j++)
				scanf("%d", &map[i][j]);

		finished = false;
		//count = v = 1;
		while(!s.empty())	s.pop();

		for(p.x=0; p.x<num_col && !finished; p.x++)	//先找起點
		{
			if(map[0][p.x] == 1)
			{
				v = p.y = 0;
				go();
				if(finished)
					printf("%d %d\n%d %d\n", 1, p.x+1, num_row, end+1);
			}
		}

		if(num_case > 0)
			printf("\n");

	}
}

void go()
{
	if(p.y == num_row-1)
	{
		if(!finished)
		{
			finished = true;
			end = p.x;
		}
		else
			if(p.x < end)
				end = p.x;
		return;
	}

	//更新要找的值
	/*if(v==count)	++count, v=1;
	else			++v;*/
	v++;
	
	s.push(p);

	if(p.x>0 && map[p.y][p.x-1]==val[v])			//左邊
	{
		p.x--;
		go();
	}
	if(p.x<num_col-1 && map[p.y][p.x+1]==val[v])	//右邊
	{
		p.x++;
		go();
	}
	if(p.y>0 && map[p.y-1][p.x]==val[v])			//上面
	{
		p.y--;
		go();
	}
	if(p.y<num_row-1 && map[p.y+1][p.x]==val[v])	//下面
	{
		p.y++;
		go();
	}
	s.pop();
	if(!s.empty())	p = s.top();
	/*if(v==1)	--count, v=count;
	else		--v;*/
	v--;
}