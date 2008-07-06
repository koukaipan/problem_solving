#include <stdio.h>

double square(double k)
{
	return k*k;
}

main()
{
	int n, m, i;
	double a, r2;
	double x, y;

	freopen("10589.txt", "r", stdin);

	while(scanf("%d %lf", &n, &a) && n)
	{
		r2 = a * a;	/* r^2 */
		for(m=i=0; i<n; i++)
		{
			scanf("%lf %lf", &x, &y);
			/* if the pt is in the striped region, then m++ */
			
			if( square(x)+square(y) <= r2				/* left down A(0,0) */
				&& square(x-a)+square(y) <= r2			/* right down B(a,0) */
				&& square(x-a)+square(y-a) <= r2		/* right up C(a,a) */
				&& square(x)+square(y-a) <= r2 )		/* left up D(0,a) */
				m++;
		}
		/*area = (double)m * r2 / (double)n;*/
		printf("%.5lf\n", (double)m * r2 / (double)n);
	}
}