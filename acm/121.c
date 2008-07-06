#include <stdio.h>
#include <math.h>

main()
{
	double a, b;
	const double l = sqrt(3)/2.0;
	int grid, skew, tmp;
	int height, width;

	freopen("121.txt", "r", stdin);
	freopen("121_out.txt", "w", stdout);

	while(scanf("%lf %lf", &a, &b) == 2)
	{
		if(a<1 || b<1)
			skew = grid = 0;
		else
		{
			/* number of pipes when sotred in grid */
			grid = (int)a * (int)b;

			/* number of pipes when sotred in skew */
			height = (int)((a-1.0) / l)+1;
			width = (int)b;

			if(b-width >= 0.5)
				skew = height * width;
			else
				skew = height * width - (int)(height/2);

			/* compare with b*a */
			height = (int)((b-1.0) / l)+1;
			width = (int)a;

			if(a-width >= 0.5)
				tmp = height * width;
			else
				tmp = height * width - (int)(height/2);

			if(tmp > skew)
				skew = tmp;
		}
		if(skew>grid)
			printf("%d skew\n", skew);
		else
			printf("%d grid\n", grid);
	}
}
