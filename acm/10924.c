#include <stdio.h>

main()
{
	int prime[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
	int n[59] = {
				27/*A*/, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 
				40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52/*Z*/, 
				0, 0, 0, 0, 0, 0,
				1/*a*/, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
				18, 19, 20, 21, 22, 23, 24, 25, 26/*z*/};
	int num, i;
	char str[21];

	freopen("10924.txt", "r", stdin);
	freopen("10924_out.txt", "w", stdout);

	while(scanf("%s", str) != EOF)
	{
		/* conver to number */
		for(num=i=0; str[i]; i++)
			num += n[str[i] - 'A'];

		/* test num is a prime or not */
		for(i=0; prime[i]*prime[i] < num; i++)
			if(num % prime[i] == 0)
				break;

		/* output */
		if(prime[i]*prime[i]>num)
			printf("It is a prime word.\n");
		else
			printf("It is not a prime word.\n");
	}
}