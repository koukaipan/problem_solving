#include <stdio.h>

main()
{
	long long int k, n, ans;
	const int a0 = 15;

	while(scanf("%lld", &k)!=EOF)
	{
		n = (k-3) / 2;
		ans = a0 + (n)*30;
		if(n>1)
			ans += ((1+(n-1))*(n-1)/2)*12;

		printf("%lld\n", ans);
	}
}