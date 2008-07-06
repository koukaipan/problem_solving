/* number theory 
   to check if n is a perfect square
*/
#include <stdio.h>
#include <math.h>

main()
{
	unsigned int n;
	double t;

	freopen("10110.txt", "r", stdin);

	while(scanf("%u", &n) && n)
	{
		t = sqrt((double)n);
		if(ceil(t) == floor(t))
			puts("yes");
		else
			puts("no");
	}
}