#include <stdio.h>

int main()
{
	int i, j, f, k=0,	//fro loop
		count,			//counts
		freq,			//frequency
		amp;			//amplitude
	bool pe_flag = false;
	freopen("488.txt", "r", stdin);
	scanf("%d", &count);

	for(k=0; k<count; k++)
	{
		//input the info
		scanf("%d %d", &amp, &freq);
		
		//draw
		for(f=0; f<freq; f++)
		{
			if(pe_flag)
				putchar('\n');
			else
				pe_flag=true;
			for(i=1; i<=amp; i++)
			{
				for(j=1; j<=i; j++)
					printf("%d", i);
				putchar('\n');
			}
			for(i-=2; i>=1; i--)
			{
				for(j=1; j<=i; j++)
					printf("%d", i);
				putchar('\n');
			}
		}
	}

	return 0;
}




