#include <stdio.h>
#include <math.h>

int main()
{
	const double pi = 3.141592653589793238462643;
	double d, l;
	int i=0, num_case;
	for(scanf("%d", &num_case); i<num_case; i++)
	{
		scanf("%lf %lf", &d, &l);
		printf("%.3lf\n", pi*(l/2)*sqrt((l/2)*(l/2)-(d/2)*(d/2)));
	}

	return 0;
}