#include <stdio.h>
#include <stdlib.h>

#define MAX 40000

struct ss{
	int n;
	int count;
	int seq;
}num[MAX];

int sort_f( const void *a , const void *b ) 
{
	return (*(struct ss*)a).seq - (*(struct ss *)b).seq ;
}

main()
{
	int n, i;
	int time;
	struct ss* nu = &num[MAX/2];

	/*freopen("484.txt", "r", stdin);*/

	for(i=0; i<MAX; i++)
	{
		num[i].seq = 2147483647;
		num[i].n = i;
	}
	time = 0;
	while(scanf("%d", &n)!=EOF)
	{
		if(nu[n].seq==2147483647)
		{
			nu[n].count = 0;
			nu[n].seq = ++time;
		}
		nu[n].count++;
	}

	qsort((void*)num, MAX, sizeof(num[0]), sort_f);
	n = 0;
	while(num[n].count)
	{
		printf("%d %d\n", num[n].n-MAX/2, num[n].count);
		n++;
	}
}