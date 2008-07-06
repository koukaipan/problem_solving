#include <stdio.h>

main()
{
	int n, tmp, num_case;
	int b1, b2;
	const int arr[10] = {0,1,1,2,1,2,2,3,1,2};
	freopen("10019.txt", "r", stdin);

	for(scanf("%d", &num_case); num_case; num_case--)
	{
		scanf("%d", &n);
		/* calculate b1 */
		b1 = 0;
		tmp = n;
		while (tmp)
		{
			b1++;
			tmp = tmp & (tmp-1);
		}

		/* calculate b2 */
		b2 = 0;
		tmp = n;
		while(tmp)
		{
			b2 += arr[tmp%10];
			tmp /= 10;
		}

		/* output */
		printf("%d %d\n", b1, b2);
	}
}

