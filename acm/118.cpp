#include <stdio.h>
#include <string.h>

#define NORTH	0
#define EAST	1
#define SOUTH	2
#define WEST	3

#define MAX 51

main()
{
	int up_bound, right_bound;
	bool map[MAX][MAX];
	bool lost;
	char a, b, i;
	int dir;
	char command[102];
	int x, y;					/* current position */
	const int move[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

	freopen("118.txt", "r", stdin);
	freopen("118_out.txt", "w", stdout);
	memset(map, 0, sizeof(bool)*MAX*MAX);
	scanf("%d %d", &up_bound, &right_bound);
	while(scanf("%d %d %c", &x, &y, &a)==3)
	{
		gets(command);
		lost = false;
		switch(a)
		{
		case 'N':		dir = NORTH;	break;
		case 'E':		dir = EAST;		break;
		case 'S':		dir = SOUTH;	break;
		case 'W':		dir = WEST;		break;
		}

		for(i=0, gets(command); command[i] && !lost; i++)
		{
			switch(command[i])
			{
			case 'L':	/* turn left */
				dir = dir - 1;
				if(dir < 0)
					dir = 3;
				break;
			case 'R':
				dir = (dir+1) % 4;
				break;
			case 'F':
				a = x + move[dir][0];
				b = y + move[dir][1];
				if(a>=0 && a<=up_bound && b>=0 && b<=right_bound)	/*如果不會掉下去就走*/
				{
					x = a;
					y = b;
				}
				else if(!map[x][y])	/* 會掉下去 沒有記錄 就記錄 */
				{
					map[x][y] = true;
					lost = true;
				}
				/*else*/			/* 會掉下去 有紀錄 不幹 */	
				break;
			}
						
		}
		printf("%d %d ", x, y);
		switch(dir)
		{
		case NORTH:		putchar('N');	break;
		case EAST:		putchar('E');	break;
		case SOUTH:		putchar('S');	break;
		case WEST:		putchar('W');	break;
		}
		printf("%s\n", lost?" LOST":"");
	}
}


		



