#include <stdio.h>
#include <math.h>

int main()
{
	double lenth;
	double area1, area2, area3;


	while(scanf("%lf", &lenth)==1)
	{
		//calculate
		area1 = (2.0*acos(0.0)/3+1-sqrt(3.0))*lenth*lenth;
		area2 = ((1.0*acos(0.0)-1)*lenth*lenth - area1)*2;
		area3 = lenth*lenth - area1 - area2;

		//print
		printf("%.3lf %.3lf %.3lf\n", area1, area2, area3);
	}

	return 0;
}
