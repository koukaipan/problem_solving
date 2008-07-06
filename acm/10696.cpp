#include <stdio.h>

int main()
{
	int num;
	
	scanf("%d", &num);
	
	while( num )	//num=0, exit
	{
	    if(num<=101)
	    	printf("f91(%d) = 91\n", num);
    	else
    		printf("f91(%d) = %d\n", num, num-10);
		scanf("%d", &num);
	}
	
	return 0;
} 
