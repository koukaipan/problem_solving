//c style

#include <stdio.h>

int main()
{
	int arr[10][4] ={	{0,0,0,0}, {1,1,1,1}, {6,2,4,8}, {1,3,9,7},
						{6,4,6,4}, {5,5,5,5}, {6,6,6,6}, 
						{1,7,9,3}, {6,8,4,2}, {1,9,1,9} };

	char m[100], n[100];
	int m2, n2, length_m, length_n;

	while(1)
	{
		length_m = length_n = 0;
		for(scanf("%c", &m[length_m]); m[length_m]!='\n' && m[length_m]!=' '; scanf("%c", &m[length_m]))
			length_m++;
		m[length_m] = '\0';

		m2 = m[length_m-1] - '0';

		for(scanf("%c", &n[length_n]); n[length_n]!='\n' && m[length_m]!=' '; scanf("%c", &n[length_n]))
			length_n++;
		n[length_n] = '\0';
		if(length_n > 1)
			n2 = (n[length_n-2]-'0')*10 + (n[length_n-1]-'0');
		else
			n2 = (n[length_n-1]-'0');

		if(length_m==1 && length_n==1 && m[0]=='0' && n[0]=='0')
			break;

		if(length_n==1 && n2==0)
			printf("1\n");
		else
			printf("%d\n", arr[m2][n2%4]);
		
		//printf("%s %s", m, n);
	}


	return 0;
}

