/* geometry calculus 
   �C�X��n�����A�@���L���䷥��
   */

#include <stdio.h>
#include <math.h>

#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

main()
{
	double a, b;
	double x1;
	freopen("10215.txt", "r", stdin);

	while(scanf("%lf %lf", &a, &b) != EOF)
	{
		x1 = ((a+b)-sqrt(( double )( a*a-a*b+b*b))) / 6.0;
		printf("%.3lf 0.000 %.3lf\n", x1+1e-7, MIN(a,b)/2.0+1e-7);
	}
}

