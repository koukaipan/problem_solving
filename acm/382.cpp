#include <stdio.h>

int main()
{
	int num, check, i;


	scanf("%d", &num);

	printf("PERFECTION OUTPUT\n");

	while(num)
	{
		check = 0;

		for(i=1; i<num; i++)
			if(num%i==0)
				check += i;

		printf("%5d", num);
		if(check<num)
			printf("  DEFICIENT\n");
		else if(check>num)
			printf("  ABUNDANT\n");
		else
			printf("  PERFECT\n");

		scanf("%d", &num);
	}

	printf("END OF OUTPUT\n");

	return 0;
}


