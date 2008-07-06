/*=================================================
  對角線公式: n(n-3)/2
  n(n-3)/2 > x
  n^2  -  3n  -  2x  >  0
           3 + sqrt(9+8x)
  -> n > ------------------
                 2
=================================================*/

#include <stdio.h>
#include <math.h>

int main()
{
	long long int n;
	int num_of_case=0;

	for(scanf("%lld", &n); n; scanf("%lld", &n))
		printf("Case %d: %d\n", ++num_of_case, (int)ceil((3.0+sqrt(9.0+8.0*n))/2.0-1e-10));

	return 0;
}
	