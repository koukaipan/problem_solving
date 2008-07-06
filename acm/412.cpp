#include <stdio.h>
#include <math.h>

#define MAX 50

int gcd(int a, int b)
{
	int x, y, r;
	x=a;y=b;r=x;

	while(r){x=y;y=r;r=x%y;}
	return y;
}

main()
{
	int num[MAX], n;
	int count;
	int i, j, k;
#ifdef WIN32
	freopen("412.in", "r", stdin);
#endif

	while(scanf("%d", &n) && n)
	{
		count = 0;
		for(i=0; i<n; i++)
			scanf("%d", &num[i]);

		for(i=0; i<n; i++)
			for(j=i+1; j<n; j++)
			{
				if(num[i]<num[j])
					k = gcd(num[i], num[j]);
				else
					k = gcd(num[j], num[i]);

				if(k==1)
					count++;
			}
		if(count == 0)
			printf("No estimate for this data set.\n");
		else
			printf("%.6lf\n", sqrt(6.0*(n*(n-1)/2.0)/count));
	}
}

