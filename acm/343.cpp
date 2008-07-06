#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int po(int, int );

int main()
{
	char a[100], b[100];
	int base_a, base_b, length_a, length_b, val_a[37], val_b[37];
	char line[100];
	int i, j;
	freopen("343.txt", "r", stdin);
	while(gets(line))
	{
		/* initialize */
		memset(a, 0, sizeof(char)*10);
		memset(b, 0, sizeof(char)*10);
		base_a = base_b = 1;
		for(i=0; i<=36; i++)
			val_a[i] = val_b[i] = 0;
		
		for(i=strlen(line)-1,j=0; line[i]!=' '; i--)
		{
			if(line[i]<='9')
				b[j++] = line[i]-'0';
			else
				b[j++] = line[i]-'A'+10;
			if(b[j-1]>base_b)
				base_b = b[j-1];
		}
		length_b = j;
		while(line[i]==' ')		i--;

		for(j=0; line[i]!=' ' && i>=0; i--)
		{
			if(line[i]<='9')
				a[j++] = line[i]-'0';
			else
				a[j++] = line[i]-'A'+10;
			if(a[j-1]>base_a)
				base_a = a[j-1];
		}
		length_a = j;
		base_a++;	base_b++;
		//calculate value of a from base_a to 36
		for(i=base_a; i<=36; i++)
			for(j=0; j<length_a; j++)
				val_a[i] += a[j] * po(i, j);
		//calculate value of b from base_b to 36
		for(i=base_b; i<=36; i++)
			for(j=0; j<length_b; j++)
				val_b[i] += b[j] * po(i, j);
		
		i = base_a;		j = base_b;
		while(val_a[i]!=val_b[j] && i<37 && j<37)
		{
			if(val_a[i] > val_b[j])
				j++;
			else
				i++;
		}
		/* output */
		if(val_a[i]==val_b[j])
		{
			printf("%s", strtok( line, " " ));
			printf(" (base %d) = ", i);
			printf("%s", strtok( NULL, " " ));
			printf(" (base %d)\n", j);
		}
		else
		{
			printf("%s", strtok( line, " " ));
			printf(" is not equal to ");
			printf("%s", strtok( NULL, " " ));
			printf(" in any base 2..36\n");
		}

	}

	return 0;
}

int po(int n, int m) /*n^m*/
{
	int i, sum=1;
	for(i=0; i<m; i++)
		sum *= n;
	return sum;
}
