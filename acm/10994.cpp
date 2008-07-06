#include <stdio.h>

const int arr[10] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};

long long compute(int n)
{
	long long sum = 0, n1, n2;
	while(n>0)
	{
		n1 = n/10;
		n2 = arr[n%10];
		n1 *= 45;
		sum += n1+n2;
		n /= 10;
	}
	return sum;
}


int main()
{
	int p, q;
	long long sum;
	int n;
	for(scanf("%d %d", &p, &q); p!=-1&&q!=-1; scanf("%d %d", &p, &q))
	{
		sum = compute(q);
		sum -= compute(p-1);

		printf("%lld\n", sum);
	}

	return 0;
}
