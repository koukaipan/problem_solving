#include <stdio.h>
#include <string.h>

const char ch[16]= {'0', '1', '2', '3', '4', '5', '6', '7',
					'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

char out[9];
int x;

void div(int n, int base)
{
	if(n<base)
	{	
		if(n)
			out[x++] = ch[n];/* printf("%c", ch[n]); */
		return;
	}

	div(n/base, base);
	out[x++] = ch[n%base];		/*printf("%c", ch[n%base]);*/
}

main()
{
	int m, n;
	int num;
	int i, tmp;
	char line[8];

	freopen("389.in", "r", stdin);
	freopen("389_out.txt", "w", stdout);

	while(scanf("%s %d %d", line, &m, &n)==3)
	{
		i = num = 0;
		memset(out, 0, sizeof(char)*9);
		x = 0;

		while(line[i])
		{
			if(line[i]<='9')
				tmp = line[i] - '0';
			else
				tmp = line[i] - 'A' + 10;

			num = num*m + tmp;
			i++;
		}

		if(num)
		{
			div(num, n);
			if(strlen(out)>7)
				printf("  ERROR\n");
			else
				printf("%7s\n", out);
		}
		else
			printf("      0\n");
		
	}
}