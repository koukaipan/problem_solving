#include <stdio.h>

#define MAX 20

void div(int n)
{
	if(n<3)
	{	
		if(n)
			printf("%d", n);
		return;
	}

	div(n/3);
	printf("%d", n%3);
}

main()
{
	int n;

	while(scanf("%d", &n) && n>=0)
	{
		if(n)
			div(n);
		else
			printf("0");
		printf("\n");
	}
}