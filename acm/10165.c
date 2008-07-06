/* http://xserve.math.nctu.edu.tw/people/cpai/carnival/game/202.htm 
   ©à (Nim)
*/

#include <stdio.h>

main()
{
	int n;
	int result;
	int i, tmp;

	freopen("10165.txt", "r", stdin);

	while(scanf("%d", &n) && n)
	{
		result = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &tmp);
			result = result ^ tmp;
		}

		if(result)
			puts("Yes");
		else
			puts("No");
	}
}