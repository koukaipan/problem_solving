#include <stdio.h>

const char ch[2]= {'0', '1'};

char out[14];

void div2(int n)
{
	out[12] = n&1 ? '1' : '0';
	out[11] = n&2 ? '1' : '0';
	out[10] = n&4 ? '1' : '0';
	out[9] = n&8 ? '1' : '0';
	out[8] = n&16 ? '1' : '0';
	out[7] = n&32 ? '1' : '0';
	out[6] = n&64 ? '1' : '0';
	out[5] = n&128 ? '1' : '0';
	out[4] = n&256 ? '1' : '0';
	out[3] = n&512 ? '1' : '0';
	out[2] = n&1024 ? '1' : '0';
	out[1] = n&2048 ? '1' : '0';
	out[0] = n&4096 ? '1' : '0';
}

int convert10(char str[], int base)
{
	int tmp;
	int num=0, i=0;
	while(str[i])
	{
		if(str[i]<='9')
			tmp = str[i] - '0';
		else
			tmp = str[i] - 'A' + 10;
		num = num*base + tmp;
		i++;
	}
	return num;
}

main()
{
	char str_a[5], str_b[5], op;
	int num_case;
	int num_a, num_b;
	
	freopen("446.txt", "r", stdin);
	out[14] = 0;
	for(scanf("%d", &num_case); num_case; num_case--)
	{
		scanf("%s %c %s", str_a, &op, str_b);
		num_a = convert10(str_a, 16);
		num_b = convert10(str_b, 16);

		div2(num_a);
		printf("%s %c ", out, op);
		div2(num_b);
		printf("%s = %d\n", out, op=='+' ? num_a+num_b : num_a-num_b);
	}
}
