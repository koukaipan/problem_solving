#include <stdio.h>

unsigned int reverse(unsigned int n)
{
	unsigned int reverse = 0;
	while(n)
	{
		reverse = reverse*10 + n%10;
		n = n / 10;
	}

	return reverse;
}

main()
{
	int count;
	unsigned int reverse_number, n;
	int num_case;
	freopen("10018.txt", "r", stdin);

	for(scanf("%d", &num_case);num_case; num_case--)
	{
		/* input */
		scanf("%u", &n);
		/*process */
		
		n += reverse(n);
		for(reverse_number = reverse(n), count = 1;
			reverse_number != n;
			reverse_number = reverse(n))
		{
			n += reverse_number;
			count++;
		}
		/* output */
		printf("%d %u\n", count, reverse_number);
	}
}
