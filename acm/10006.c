#include <stdio.h>

main()
{
	int carmichael_number[]={561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};
	int n;
	int i;

	for(scanf("%d", &n); n; scanf("%d", &n))
	{
		for(i=0; i<16; i++)
		{
			if(n==carmichael_number[i])
				break;
		}
		if(i<16)
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);
	}
}

