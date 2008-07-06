/* geometry 三角形內切圓半徑
   面積相等 
   sqrt(s(s-a)(s-b)(s-c)) = 0.5 (ra + rb + rc);
*/ 
#include <stdio.h>
#include <math.h>

main()
{
	double a, b, c;
	double s, r;
	
	freopen("10195.txt", "r", stdin);
	freopen("10195_out.txt", "w", stdout);
	
	while(scanf("%lf %lf %lf", &a, &b, &c)!=EOF)
	{
		s = 0.5 * (a+b+c);
		if(s==0)
			r = 0.000;
  		else
			r = sqrt((s-a)*(s-b)*(s-c)/s);
		printf("The radius of the round table is: %.3lf\n", r);
	}
}
		
