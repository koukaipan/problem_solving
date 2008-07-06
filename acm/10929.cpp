#include <stdio.h>

int main()
{
	int sum[2], flag, i;
	char ch[1010];

	for( scanf("%s", ch); ch[0]!='0' || ch[1]!='\0'; scanf("%s", ch))
	{
		sum[0] = sum[1] = 0;
		for(i=0; ch[i]!='\0'; i++)
			sum[i%2] += (ch[i]-'0');
		flag = (sum[0] - sum[1]) % 11;
		printf("%s is%sa multiple of 11.\n", ch, !flag?" ":" not ");
	}

	return 0;
}


