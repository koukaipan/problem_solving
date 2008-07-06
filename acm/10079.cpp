#include <stdio.h>

int main()
{
	//long long n;
	__int64 n;

	for(scanf("%I64d", &n); n>=0; scanf("%I64d", &n))
		printf("%I64d\n", (n*n+n)/2+1);

	return 0;
}
