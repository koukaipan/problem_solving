/* geometry */

#include <stdio.h>

#define MAX 1001
#define ABS(x) ((x)<0 ? -(x) : (x))

struct coord_t
{
	double x;
	double y;
};

double dist_square(double x1, double y1, double x2, double y2)
{
	double  x = ABS(x1-x2), 
			y = ABS(y1-y2);
	return x * x + y * y;
}

main()
{
	struct coord_t coord[MAX];
	int n;
	double x1, y1, x2, y2;
	int ok,i;

	freopen("10310.txt", "r", stdin);
	
	while(scanf("%d %lf %lf %lf %lf", &n, &x1, &y1, &x2, &y2)!=EOF)
	{
		for(ok=-1,i=0; i<n; i++)
		{
			scanf("%lf %lf", &coord[i].x, &coord[i].y);
			if(ok==-1 && dist_square(x2, y2, coord[i].x, coord[i].y) >= 4*dist_square(x1, y1, coord[i].x, coord[i].y))
				ok = i;
		}
		if(ok!=-1)
			printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", coord[ok].x, coord[ok].y);
		else
			printf("The gopher cannot escape.\n");
	}
}
	