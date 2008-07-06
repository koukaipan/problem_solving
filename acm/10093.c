#include <stdio.h>
#include <string.h>

#define MAX 10000

main()
{
	char line[MAX];
	int num, base, len;
	int i;

	const unsigned char a[128]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 0, 0, 0, 0, 0, 0, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0};
	//freopen("10093.txt", "r", stdin);
	/*freopen("1.txt", "w", stdout);

	for(c=0; c<127; c++)		a[c] = 0;
	for(c='0'; c<='9'; c++)		a[c] = c-'0';
	for(c='A'; c<='Z'; c++)		a[c] = c-'A'+10;
	for(c='a'; c<='z'; c++)		a[c] = c-'a'+36;
	for(c=0; c<127; c++)		printf("%d, ", a[c]);*/

	while(gets(line)!=NULL)
	{
		len = strlen(line);
		for(num=i=0, base=2; i<len; i++)
		{
			num += a[line[i]];
			if(a[line[i]] >= base)
				base = a[line[i]]+1;
		}
		
		/* test all the possible base */
		for(; base<63; base++)
			if(num % (base-1) == 0)
				break;
		if(base>=63)
			printf("such number is impossible!\n");
		else
			printf("%d\n", base);
	}
}
