#include <stdio.h>

main()
{
	int num;
	char line[12];
	int i, tmp, base;

	while(gets(line))
	{
		base = 10;
		if(line[0]!='0')
			sscanf(line, "%d", &num);
		else
		{
			num = 0;
			base = 16;
			i=2;
			while(line[i])
			{
				if(line[i]<='9')
					tmp = line[i] - '0';
				else
					tmp = line[i] - 'A' + 10;

				num = num*16 + tmp;
				i++;
			}
		}
		if(num<0)
			break;

		if(base == 10)
			printf("0x%X\n", num);
		else
			printf("%d\n", num);
	}
}
