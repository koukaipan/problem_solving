/* string and sorting */

#include <stdio.h>
#include <stdlib.h>

struct data_{
	char ch;
	int count;
}data[27];

int sort_f( const void *a , const void *b ) 
{
	if((*(struct data_*)b).count == (*(struct data_*)a).count)
		return (*(struct data_*)a).ch - (*(struct data_*)b).ch;
	else
		return(*(struct data_*)b).count - (*(struct data_*)a).count;
}


main()
{
	int num_case, i;
	char line[90];
	
	freopen("10008.txt", "r", stdin);

	/* intialize */
	for(i=0; i<27; i++)
	{
		data[i].ch = 'A' + i;
		data[i].count = 0;
	}

	for(scanf("%d ", &num_case); num_case; num_case--)
	{
		/* input */
		gets(line);

		/* process */
		for(i=0;line[i];i++)
		{
			line[i] = line[i] | 0x20;	/* to lower case */
			if(line[i]>='a' && line[i]<='z')
				data[line[i]-'a'].count++;
		}			
		
	}
	/* sort */
	qsort((void*)data, 26, sizeof(struct data_), sort_f);

	/* output*/
	for(i=0; data[i].count; i++)
		printf("%c %d\n", data[i].ch, data[i].count);
}

