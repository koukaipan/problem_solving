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
	unsigned int fib[100];
	int n;
	fib[0] = fib[1] = 1;
	for(int i=2; i<100; i++)
		fib[i] = fib[i-1] + fib[i-2];

	for(scanf("%d", &n); n!=-1; scanf("%d", &n))
		printf("%u %u\n", fib[n+1]-1, fib[n+2]-1);

	return 0;
}
