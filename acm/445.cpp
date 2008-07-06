#include <stdio.h>

int main()
{
	char ch;
	int times=0, i;
	freopen("445.txt", "r", stdin);

	while(scanf("%c", &ch)!=EOF)
	{
		if(ch>='0' && ch<='9')   //digit
			times += ch-'0';
		else if(ch!='!' && ch!='\n')
		{
			if(ch=='b')
				ch = ' ';
			for(i=0; i<times; i++)
				printf("%c", ch);
			times = 0;
		}
		else
			printf("\n");
	}
	
	return 0;
}

		
			