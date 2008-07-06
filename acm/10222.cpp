#include <stdio.h>

int main()
{
	char map[128], ch;

	//initialize
	for(int i=0; i<128; i++)
		map[i] = i;

	//modify the char. locate
	map[91]=111;	map[93]=112;	map[46]=109;	map[44]=110;
	map[59]=107;	map[39]=108;	map[61]=48;		map[45]=57;
	map[48]=56;		map[57]=55;		map[56]=54;		map[55]=53;
	map[54]=52;		map[53]=51;		map[52]=50;		map[51]=49;
	map[50]=96;
	map[98]=99;		map[99]=122;	map[100]=97;	map[101]=113;
	map[102]=115;	map[103]=100;	map[104]=102;	map[105]=121;
	map[106]=103;	map[107]=104;	map[108]=106;	map[109]=98;
	map[110]=118;	map[111]=117;	map[112]=105;	map[114]=119;
	map[116]=101;	map[117]=116;	map[118]=120;	map[121]=114;


	while(scanf("%c", &ch) == 1)
	{
		if(ch>='A' && ch<='Z')
			ch += 32;
		printf("%c", map[ch]);
	}

	return 0;
}