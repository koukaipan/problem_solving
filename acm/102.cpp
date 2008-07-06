/* enumerate all the permutation of bins, 
   and calculate their count of movement,
   find the min*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define INT_MAX 2147483647

using namespace std;

main()
{
	int b[3], g[3], c[3];
	int min, move, i;
	char t[4], d[4];

	freopen("102.txt", "r", stdin);

	t[3] = d[3] = 0;
	while(scanf("%d %d %d %d %d %d %d %d %d", 
		&b[0], &g[0], &c[0], &b[1], &g[1], &c[1], &b[2], &g[2], &c[2])!=EOF)
	{
		min = INT_MAX;
		strcpy(d, "BCG");
		do{
			move = 0;
			for(i=0; i<3; i++)
			{
				switch(d[i])
				{
				case 'B':
					move += b[0] + b[1] + b[2] - b[i];
					break;
				case 'C':
					move += c[0] + c[1] + c[2] - c[i];
					break;
				case 'G':
					move += g[0] + g[1] + g[2] - g[i];
					break;
				}
			}
			if(move < min)
			{
				min = move;
				strcpy(t,d);
			}		
		
		}while(next_permutation(d,d+3));
		printf("%s %d\n", t, min);
	}
}
