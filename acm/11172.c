#include <stdio.h>

main()
{
	int a, b, num_case;

	for(scanf("%d", &num_case); num_case; num_case--)
	{
		scanf("%d %d", &a, &b);
		if(a>b)
			puts(">");
		else if(a==b)
			puts("=");
		else
			puts("<");
	}
}
	