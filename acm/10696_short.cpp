#include <stdio.h>

int main()
{
	int num;
	
	for(scanf("%d", &num); num!=0; scanf("%d", &num))
		printf("f91(%d) = %d\n", num, ((num-100)>0 ? num-10:91));

	return 0;
} 
