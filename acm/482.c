#include <stdio.h>
#include <stdlib.h>

#define MAX 4000

struct data_{
	int index;
	char v[20];
}data[MAX];

int sort_f( const void *a , const void *b ) 
{
	return (*(struct data_*)a).index - (*(struct data_*)b).index;
}

main()
{
	int num_case;
	char ch;
	int i, j;

#ifdef WIN32
	freopen("482.txt", "r", stdin);
#endif

	for(scanf("%d", &num_case); num_case; num_case--)
	{
		i=0;
		while(1)
		{
			scanf("%d%c", &data[i].index, &ch);
			i++;	/* i is number of values */
			if(ch=='\n')
				break;
		}

		for(j=0; j<i; j++)
			scanf("%s", &data[j].v);

		qsort(data, i, sizeof(data[0]), sort_f);

		for(j=0; j<i; j++)
			printf("%s\n", data[j].v);
		if(num_case>1)
			printf("\n");
	}
}

