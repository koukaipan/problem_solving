#include <stdio.h>
#include <math.h>

int main()
{
	double num_edge, radius;
	double area;
	const double PI = 3.1415926535;

	while(scanf("%lf %lf", &radius, &num_edge)==2)
	{
		//area = 0.5*num_edge*radius*radius*sin( 2.0*acos(-1.0)/num_edge);
		area = 0.5*radius*radius*sin( acos(-1.0)*2.0/num_edge)*num_edge;
		//printf("%.3lf\n",0.5*r*r*sin(acos(-1.0)*2.0/n)*n); 

		printf("%.3lf\n", area);
	}

	return 0;
}
