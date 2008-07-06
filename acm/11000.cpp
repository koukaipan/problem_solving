/*===============================================
year    1   2   3   4   5   6   7   8   9   10
male    1   2   4   7  12  20  33  54  88  143
famale  1   2   3   5   8  13  21  34  55   89
->fib
  male(n) = female(n-1) + male(n-1)
female(n) = 1 + male(n-1)

actually, male(n) = fib(n)-1
total = fib(n+1)-1
===============================================*/
#include <stdio.h>

int main()
{
	unsigned int male[100], female[100];
	int num;
	male[0] = 0;
	female[0] = 1;
	for(int i=1; i<100; i++)
	{
		male[i] = female[i-1] + male[i-1];
		female[i] = 1 + male[i-1];
	}

	for(scanf("%d", &num); num!=-1; scanf("%d", &num))
		printf("%u %u\n", male[num], female[num] + male[num]);

	return 0;
}