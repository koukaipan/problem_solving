/* 列出某集合中含有K個元素的所有子集合 */

#include <stdio.h>

#define MAXSIZE	13

int main()
{
	int set[6],
		n,	//未知   6<n<13
		k=6,	//k=6挑六個
		position,
		i, j,
		value[MAXSIZE];
	bool pe_flag=false;
	freopen("441.txt", "r", stdin);

	for(scanf("%d", &n); n!=0; scanf("%d", &n))
	{
		for(j=1; j<=n; j++)
			scanf("%d", &value[j]);

		for(i=0; i<k; i++)	//initialize the subset to {1,2,3.....k}
			set[i] = i+1;

		//pe modify
		if(!pe_flag)
			pe_flag=true;
		else
			printf("\n");
		//display the 1st time
		for(j=0; j<k-1; j++)
			printf("%d ", value[set[j]]);
		printf("%d\n", value[set[j]]);

		position = k-1;
		while(1)
		{
			if(set[k-1] == n)
				position--;
			else
				position = k-1;

			set[position]++;
			for(i=position+1; i<k; i++)
				set[i] = set[i-1] + 1;

			//display
			for(j=0; j<k-1; j++)
				printf("%d ", value[set[j]]);
			printf("%d\n", value[set[j]]);

			if(set[0]>=n-k+1) break;
		}
	}

	return 0;
}