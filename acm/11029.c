#include <stdio.h>
#include <math.h>

int bigmod(int, int);

main()
{
	int num_case;
	int base, power;	/* n^k */
	int l, i;
	double a, b;		/* a*10^b */
	const double k = log(10);

#ifdef WIN32
	freopen("11029.txt", "r", stdin);
#endif

	for(scanf("%d", &num_case); num_case; num_case--)
	{
		scanf("%d %d", &base, &power);
		
		b = power * log10(base);
		a = exp(k*(b-ceil(b)));
		
		while (a<100.0) 
			a *= 10.00;

		/*l = bigmod(base, power);*/
		for(l=1, i=1073741824; i>0; i=i>>1)
		{
			l = ((l%1000) * (l%1000)) % 1000;
			if(i&power)
				l = ((l%1000)*(base%1000)) %1000;
		}
		/*for(l=1, i=0; i<power; i++)	//too low
			l = (l*c)%1000;*/
		printf("%.0lf...%03d\n", floor(a), l);
	}
}

int bigmod(int b, int p)
{
	int i, n;
	for(n=1, i=1073741824; i>0; i=i>>1)
	{
		n = ((n%1000) * (n%1000)) % 1000;
		if(i&p)
			n = ((n%1000)*(b%1000)) %1000;
	}
	return n;
}
