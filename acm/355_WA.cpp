#include <stdio.h>

#define INT	__int64
char out[50];
int x;
char ch[16]= {'0', '1', '2', '3', '4', '5', '6', '7',
				'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void div(INT n, int base)
{
	/*if(n<base)
	{	
		if(n)
			printf("%c", ch[n]);
		return;
	}

	div(n/base, base);
	printf("%c", ch[n%base]);*/
	while (n) 
	{
		out[x++] = ch[n%base];
		n /= base;
	}
}

main()
{
	int m, n;
	INT num;
	int flag;
	int i, tmp;
	char line[12];

#ifdef WIN32
	freopen("355.txt", "r", stdin);
	//freopen("355_out.txt", "w", stdout);
#endif

	while(scanf("%d %d %s", &m, &n, line)==3)
	{
		i = 0;
		num = 0;
		flag = 1;
		while(line[i] && flag)
		{
			if(line[i]<='9')
				tmp = line[i] - '0';
			else
				tmp = line[i] - 'A' + 10;

			if(tmp > m)
				flag = 0;
			else
				num = num*m + tmp;

			i++;
		}
		x = 0;
		if(flag)
		{
			printf("%s base %d = ", line, m);
			if(num)
				div(num, n);
			else
				printf("0");
			for(x--; x>=0; x--)
				printf("%c", out[x]);
			printf(" base %d\n", n);
		}
		else
			printf("%s is an illegal base %d number\n", line, m);
	}
}
