#include <stdio.h>

int main()
{
	long long int a, b;
	int num_of_case=0;

	while(scanf("%lld %lld", &a, &b) && a || b)
		printf("Case %d: %lld\n", ++num_of_case, a*b*(a-1)*(b-1)/4);

	return 0;
}