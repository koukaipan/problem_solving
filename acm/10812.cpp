/*===========================================================
=                  sum-diff                  sum-diff       =
=   large = sum - ----------    small = 0 + ----------      =
=                      2                         2          =
===========================================================*/

#include <stdio.h>

int main()
{
	int counts,
		sum, diff,
		large, small;
	int impossible;
	int i=0;

	scanf("%d", &counts);

	while(i++<counts)
	{
		impossible = 1;

		scanf("%d%d", &sum, &diff);
		
		//large = sum - (sum-diff)/2;
		large = (sum+diff)/2;
		small = (sum-diff)/2;

		if(large>=small && small>=0)
		if(large + small == sum)
		if(large - small == diff || small - large == diff)
			impossible = 0;

		if(impossible)
			printf("impossible\n");
		else
			printf("%d %d\n", large, small);
	}

	return 0;
}
		
