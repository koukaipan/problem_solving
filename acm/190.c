#include <stdio.h>
#include <math.h>

main()
{
	double x1, x2, x3, y1, y2, y3;
	double x, y, r;
	double tmp;

	freopen("190.txt", "r", stdin);

	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3)!=EOF)
	{
		y = ( ((pow(x1,2) + pow(y1,2))*(x2-x3) - (x2-x1)*(pow(x3,2) + pow(y3,2)) - (x1-
		x3)*(pow(x2,2) + pow(y2,2)) ) / (2*(x1*y2-x1*y3+x2*y3-x2*y1+x3*y1-x3*y2)*(-1.0)
		) );
		if(x2-x1 == 0.000)
		{
			tmp=x1; x1=x3; x3=tmp;
			tmp=y1; y1=y3; y3=tmp;
		}
		x =  (pow(x2,2.0) - pow(x1,2.0) + 2.0*y1*y - 2.0*y2*y + pow(y2,2.0) - pow(y1,2.0)) / (2.0*(x2- x1));
		r = sqrt(pow(fabs(x1-x),2)+pow(fabs(y1-y),2));
		/*printf("%.3lf, %.3lf, %.3lf\n", x, y, r);*/
		if(x>0)
			printf("(x - %.3lf)^2 + ", x);
		else
			printf("(x + %.3lf)^2 + ", -x);
		if(y>0)
			printf("(y - %.3lf)^2 = %.3lf^2\n", y, r);
		else
			printf("(y + %.3lf)^2 = %.3lf^2\n", -y, r);

		if(x<0)
			printf("x^2 + y^2 + %.3lfx ", -x*2.0);
		else
			printf("x^2 + y^2 - %.3lfx ", x*2.0);
		if(y<0)
			printf("+ %.3lfy ", -2.0*y);
		else
			printf("- %.3lfy ", 2.0*y);

		if(pow(x,2.0)+pow(y,2.0)-pow(r,2.0)>0)
			printf("+ %.3lf = 0\n\n", pow(x,2.0)+pow(y,2.0)-pow(r,2.0));
		else
			printf("- %.3lf = 0\n\n", -(pow(x,2.0)+pow(y,2.0)-pow(r,2.0)));
		/*x^2 + y^2 - 6.000x + 4.000y - 12.000 = 0*/


	}
}