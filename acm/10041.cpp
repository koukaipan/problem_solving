#include <stdio.h>
#include <algorithm>
//using namespace std;

/*
int sort_f( const void *a , const void *b ) 
{
	return *(int *)a - *(int *)b ;
}*/

main()
{
	int num_case, n, i;
	int v[500];
	int median, dist;

	freopen("10041.txt", "r", stdin);

	for(scanf("%d", &num_case); num_case; num_case--)
	{
		for(scanf("%d", &n), i=0; i<n; i++)
			scanf("%d", &v[i]);
		std::sort(v, v+n);
		//qsort((void*)v, n, sizeof(int), sort_f);

		if(n%2)	/* odd */
			median = v[n/2];
		else	/* even */
			median = v[n/2-1] + v[n/2];

		for(i=0, dist=0; i<n/2; i++)
			dist += median - v[i];
		for(;i<n;i++)
			dist += v[i] - median;

		printf("%d\n", dist);
	}
}


