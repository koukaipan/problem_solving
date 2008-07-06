#include <stdio.h>
#include <string.h>

main()
{
	const int p[31]={1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191,
		16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 
		8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 
		1073741823, 2147483647};
	int i, num, l;
	char line[35];
#ifdef WIN32
	freopen("575.txt", "r", stdin);
#endif
	while(gets(line) && (line[0]!='0'||strlen(line)!=1))
	{
		num = 0;
		l = strlen(line);
		for(i=0; i<l; i++)
			num += p[l-i-1] * (line[i]-'0');

		printf("%d\n", num);
	}			
}

	