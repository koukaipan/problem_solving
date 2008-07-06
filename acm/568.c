#include <stdio.h>

main()
{
	int n;
	int result;
	int i;
#ifdef WIN32
	freopen("568.in", "r", stdin);
#endif

	while(scanf("%d", &n)!=EOF)
	{
		result = 1;

		for(i=n; i>=1; i--)
		{
			result = result * i;
			while(result%10 == 0)
				result = result / 10;

			if(result > 200000 )
				result = result % 10000;
		}

		printf("%5d -> %d\n", n, result%10);
	}
}
