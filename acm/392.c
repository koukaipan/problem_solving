#include <stdio.h>

main()
{
	int coef[9];
	int i;
	int first;

	freopen("392.in", "r", stdin);
	freopen("392_out.txt", "w", stdout);

	while(scanf("%d", &coef[8]) == 1)
	{
		for(i=7; i>=0; i--)
			scanf("%d", &coef[i]);

		first = 0;
		for(i=8; i>1; i--)
		{
			if(coef[i])	/* 要印 */
			{
				if(first == 0)	/* 第一個尚未出現 可以印負號 */
				{
					first = 1;
					if(coef[i] == -1)
						printf("-x^%d", i);
					else if(coef[i] == 1)
						printf("x^%d", i);
					else 
						printf("%dx^%d", coef[i], i);
				}
				else	/*已經印過*/
				{
					if(coef[i] == -1)
						printf(" - x^%d", i);
					else if(coef[i] == 1)
						printf(" + x^%d", i);
					else if(coef[i] > 1)
						printf(" + %dx^%d", coef[i], i);
					else
						printf(" - %dx^%d", -coef[i], i);
				}
			}
		}
		/* 有1次項 */
		if(coef[1])
		{
			if(first == 0)	/* 第一個尚未出現 可以印負號 */
			{
				first = 1;
				if(coef[i] == -1)
					printf("-x");
				else if(coef[i] == 1)
					printf("x");
				else 
					printf("%dx", coef[i]);
			}
			else	/*已經印過*/
			{
				if(coef[i] == -1)
					printf(" - x", -i);
				else if(coef[i] == 1)
					printf(" + x", i);
				else if(coef[i] > 1)
					printf(" + %dx", coef[i]);
				else
					printf(" - %dx", -coef[i]);
			}
		}
		
		/* 有常數項 */
		if(coef[0])
		{
			if(first == 0)					/* 之前沒印過 */
				printf("%d\n", coef[0]);
			else if(coef[0]<0 && first==1)	/* 負數 之前有印過 */
				printf(" - %d\n", -coef[0]);
			else							/* 正數 之前有印過 */
				printf(" + %d\n", coef[0]);
		}
		else if(first==0)
			printf("0\n");
		else
			printf("\n");
	}
}


			
