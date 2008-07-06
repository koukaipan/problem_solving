/*
	x = 2^-n
	log x = -n log 2
	      = k + p (k是正整數, 表幾個小數位數, 再由p去求log x)
	
	log x = y = ln x / ln 10
	(1)10^logx = 10^y, x = 10^y
	(2)exp(ln x) = x = exp(y * ln 10)
*/

#include <stdio.h>
#include <math.h>

main()
{
	double n;
	double a, b;	/* a* 10 ^ b */
	const double k = log(10),
				 p = log10(2);
/* k = 2.3025850929940459 */
/* p = 0.30102999566398120 */
	freopen("474.txt", "r", stdin);

	while(scanf("%lf", &n)!=EOF)
	{
		b = ceil(n * p);
		a = exp(k * (b+(-n)*p));/*faster*/
		/*a = pow(10, (b+(-n)*p));*/
		printf("2^-%.0lf = %.3lfe-%.0lf\n", n, a, b);
	}
}


