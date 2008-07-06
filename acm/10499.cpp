#include <stdio.h>

int main()
{
	long long n;

	for(scanf("%lld", &n); n>0; scanf("%ld", &n))
		if(n==1)
			printf("0%%\n");
		else
			printf("%lld%%\n", n*25);

	return 0;
}
