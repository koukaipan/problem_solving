/* GCD */

#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
	int x, y, r;
	x=a;y=b;r=x;

	while(r){x=y;y=r;r=x%y;}
	return y;
}

int pow2(int n)
{
	int ans;
	ans = 1;
	ans = ans<<n;

	return ans;
}

main()
{
	char n1[32], n2[32];
	int num_case;
	int a, b, i, j, n;
	freopen("10193.txt", "r", stdin);

	for(scanf("%d", &num_case), i=0; i<num_case; i++)
	{
		scanf("%s", n1);
		scanf("%s", n2);
		a = b = 0;
		/* conver n1 to decimal -> a */
		n = strlen(n1);
		for(j=0; j<n; j++)
		{
			if(n1[j]=='1')
				a += pow2(n-j-1);
		}
		/* conver n2 to decimal -> b */
		n = strlen(n2);
		for(j=0; j<n; j++)
		{
			if(n2[j]=='1')
				b += pow2(n-j-1);
		}
		/* compute gcd */
		if(a<b)
			n = gcd(a, b);
		else
			n = gcd(b, a);

		/* output */
		printf("Pair #%d: %s\n",i+1, n==1? "Love is not all you need!" : "All you need is love!");
	}
}
