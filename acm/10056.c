/* 機率、等比級數 */
#include <stdio.h>
#include <math.h>

main()
{
	double n, i;
	int num_case;
	double p, p2, r, a0;

	freopen("10056.txt", "r", stdin);

	for(scanf("%d", &num_case); num_case; num_case--)
	{
		scanf("%lf %lf %lf", &n, &p, &i);
		if(p==0.00)
			printf("0.0000\n");
		else
		{
			p2 = 1.0 - p;
			r = pow(p2, n);
			a0 = pow(p2, i-1) * p;

			printf("%.4lf\n", a0/(1.0-r) + 1e-7);
		}
	}
}



