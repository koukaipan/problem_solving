#include <stdio.h>

int main()
{
	int n_cows, n_cars, n_doors;
	double a, b, c, ans;

	while(scanf("%lf %lf %lf", &a, &b, &c)!=EOF)
		printf("%.5lf\n", b*(a+b-1)/((a+b-c-1)*(a+b)));

	return 0;
}