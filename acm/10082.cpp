#include <stdio.h>
#define MAXLENTH 1000


void init(char mirror[])
{
	for(int i=0; i<128; i++)
		mirror[i] = i;

	mirror[61] = 45 ;	mirror[45] = 48 ;	mirror[48] = 57 ;	mirror[57] = 56 ;
	mirror[56] = 55 ;	mirror[55] = 54 ;	mirror[54] = 53 ;	mirror[53] = 52 ;
	mirror[52] = 51 ;	mirror[51] = 50 ;	mirror[50] = 49 ;	mirror[49] = 96 ;
	mirror[92] = 93 ;	mirror[93] = 91 ;	mirror[91] = 80 ;	mirror[80] = 79 ;
	mirror[79] = 73 ;	mirror[73] = 85 ;	mirror[85] = 89 ;	mirror[89] = 84 ;
	mirror[84] = 82 ;	mirror[82] = 69 ;	mirror[69] = 87 ;	mirror[87] = 81 ;
	mirror[39] = 59 ;	mirror[59] = 76 ;	mirror[76] = 75 ;	mirror[75] = 74 ;
	mirror[74] = 72 ;	mirror[72] = 71 ;	mirror[71] = 70 ;	mirror[70] = 68 ;
	mirror[68] = 83 ;	mirror[83] = 65 ;	mirror[47] = 46 ;	mirror[46] = 44 ;
	mirror[44] = 77 ;	mirror[77] = 78 ;	mirror[78] = 66 ;	mirror[66] = 86 ;
	mirror[86] = 67 ;	mirror[67] = 88 ;	mirror[88] = 90 ;
}


int main()
{
	char str[MAXLENTH],
		 mirror[128];
	int i;
	
	init(mirror);

	while(gets(str))
	{
		for(i=0; str[i]; i++)
			printf("%c", mirror[str[i]]);
		printf("\n");
	}

	return 0;
}
