#include <stdio.h>

main()
{
	double well_height, up, drop, f;
	double pos;
	int count;

#ifdef WIN32
	freopen("573.txt", "r", stdin);
#endif

	while(scanf("%lf %lf %lf %lf", &well_height, &up, &drop, &f) &&
		well_height && up && drop && f)
	{
		pos = up;
		count = 1;
		f = (f/100.00)*up;
		while(pos <= well_height)
		{
			/* at night */
			pos -= drop;
			if(pos < 0.000)
				break;
			if(up <= f)
				up = 0;
			else
				up -= f;
			/* at day */
			pos += up;
			count++;
		}

		if(pos <= 0.000)
			printf("failure on day %d\n", count);
		else
			printf("success on day %d\n", count);
	}
}
