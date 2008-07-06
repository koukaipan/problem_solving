#include <stdio.h>

#define MAX 10000

void insertionSort(int val[], int mount)
{
	int buf;
	for(int i=mount-1; i>0; i--)
		if( val[i] < val[i-1])
		{
			buf=val[i]; val[i]=val[i-1]; val[i-1]=buf;
		}

		
}


int main()
{
	int value[MAX],
		mount=0;

	//the first
	scanf("%d", &value[mount++]);
	printf("->%d\n", value[0]);

	while(scanf("%d", &value[mount++]) == 1)
	{
		//input the number

		//check if it need to sort
		if (value[mount-1] < value[mount-2])
			insertionSort(value, mount);
		
		//calculate the median and print
		if(mount%2)		//odd
			printf("%d\n", value[mount/2]);
		else			//even
			printf("%d\n", (int)((value[mount/2-1]+value[mount/2])/2));

	}

	return 0;
}
