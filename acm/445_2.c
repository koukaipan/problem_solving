#include <stdio.h>
#include <string.h>
main()
{
	char line[134];
	int i, j;
	int count, ch;

	freopen("445.txt", "r", stdin);

	while(gets(line))
	{
		count = 0;
		for(i=0; line[i]; i++)
		{
			if(line[i] == '!')
				printf("\n");
			else if(line[i]<='9' && line[i]>='0')
				count += line[i]-'0';
			else
			{
				if(line[i] == 'b')
					ch = ' ';
				else
					ch = line[i];
				for(j=0; j<count; j++)
					printf("%c", ch);
				count = 0;
			}
		}
		printf("\n");
	}
}
