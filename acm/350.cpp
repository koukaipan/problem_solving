#include <stdio.h>
#include <string.h>

#define MAX 10000

main()
{
	int num[MAX];
	int z, i, m, l;
	int count, num_case;

	freopen("350.txt", "r", stdin);

	for(num_case=0, scanf("%d %d %d %d", &z, &i, &m, &l);
		z || i || m || l;
		scanf("%d %d %d %d", &z, &i, &m, &l))
	{
		count = 1;
		memset(num, false, sizeof(int)*(m+1));
		while(num[l] == 0)
		{
			num[l] = count;
			//l = ( (z % m * l % m) % m + i ) % m;
			l = ( z * l + i ) % m;
			//printf("%d: %d\n", count, l);
			count++;
		}
		printf("Case %d: %d\n", ++num_case, count-num[l]);
	}
}

