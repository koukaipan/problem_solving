#include <stdio.h>
#include <math.h>

#define ABS(x) ((x)<0 ? -(x) : (x))

double dist(double x1, double y1, double x2, double y2)
{
	double  x = ABS(x1-x2), 
			y = ABS(y1-y2);
	return sqrt(x * x + y * y);
}

main()
{
	double x1, y1, x2, y2, a1, a2;
	double ab;
	const double PI = 2*acos(0);
	
	freopen("10210.txt", "r", stdin);

	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &a1, &a2)!=EOF)
	{
		ab = dist(x1, y1, x2, y2);
		printf("%.3lf\n", ab/tan(a1*PI/180.0)+ab/tan(a2*PI/180.0));
	}


}
