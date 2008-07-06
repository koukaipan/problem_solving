#include <stdio.h>

#define ABS(x) ((x)<0 ? -(x) : (x))

main()
{
	int num_case, length;
	int a,b,i;
	int dif, flag;
	
	freopen("10963.txt", "r", stdin);
	freopen("10963_out.txt", "w", stdout);

	for(scanf("%d", &num_case),i=0; i<num_case; i++)
	{
		if(i>0)
			putchar('\n');
		flag = 1;
		dif = -1;
		for(scanf("%d", &length); length; length--)
		{
			scanf("%d %d", &a, &b);
			if(dif == -1)
				dif = ABS(a-b);
			else if(dif != ABS(a-b))
				flag = 0;
		}
		if(flag)
			puts("yes");
		else
			puts("no");
	}
}
