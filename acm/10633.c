/* math */
#include <stdio.h>

main()
{
	/*unsigned __int64 n,m,n_minus_m; visual c++­n¥Î%I64u*/
	unsigned long long n,m,n_minus_m;

	freopen("10633.txt", "r", stdin);
	freopen("10633_out.txt", "w", stdout);

	while(scanf("%llu", &n_minus_m) && n_minus_m)
	{
		n = n_minus_m * 10 / 9;
		m = n / 10;
		if ((n-m)%9==0)
			printf("%llu %llu\n", n-1, n);
		else
			printf("%llu\n", n);
	}

}