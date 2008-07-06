/* big mod */
#include <stdio.h>

int main()
{
	int n, b, p, m;
	int i;

	while(scanf("%d %d %d", &b, &p, &m)==3)
	{
		for(n=1, i=1073741824; i>0; i=i>>1)
		{
			n = ((n%m) * (n%m)) % m;
			if(i&p)
				n = ((n%m)*(b%m)) %m;
		}
		printf("%d\n", n);
	}

	return 0;
} 
