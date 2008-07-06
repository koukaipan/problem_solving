#include <stdio.h>
#include <math.h>

int main()
{
	double n;
	int num_case=1;

	while(scanf("%lf", &n) && n!=0)
		printf("Case %d: %d\n", num_case++, (int)ceil((3.0+sqrt(9.0+8.0*n))/2.0 - 1e-10));

	return 0;
}
