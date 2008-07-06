#include <stdio.h>

int main()
{
	int m, //num_of_datasets,	//M
		n, //num_of_coins,		//N
		k, //num_of_weighting,	//k
		pi, //num_of_placed,		//Pi
		i, j, h;
	int coin[101], left[51], right[51];
	char c;
	int num_of_false, point;
	freopen("665.txt", "r", stdin);

	//input the number of datasets
	scanf("%d", &m);

	for(h=0; h<m; h++)
	{
		//input
		scanf("%d %d", &n, &k);
		//initialize
		for(i=1; i<=n; i++)
			coin[i] = 0;
		num_of_false = 0;
		point = 0;

		for(i=0; i<k; i++)
		{
			scanf("%d", &pi);
			for(j=0; j<pi; j++)
				scanf("%d", &left[j]);
			for(j=0; j<pi; j++)
				scanf("%d", &right[j]);
			scanf(" %c", &c);

			if(c == '=')
				for(j=0; j<pi; j++)
					coin[left[j]] = coin[right[j]] = 1;
		}

		//search
		for(i=1; i<=n; i++)
			if(!coin[i])
			{
				num_of_false++;
				point = i;
			}

		//print result
		if(h>0)
			printf("\n");
		printf("%d\n", num_of_false!=1 ? 0 : point);
	}//end of big forloop


	return 0;
}