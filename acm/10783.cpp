#include <stdio.h>


int main()
{
	int total_case, num_case,
		begin, end, sum;

	int high;

	scanf("%d", &total_case);

	for(num_case=1; num_case<=total_case; num_case++)
	{
		scanf("%d %d", &begin, &end);
		//check begin and end are both odd
		if(!(begin%2))
			begin += 1;
		if(!(end%2))
			end -= 1;

		high = (end-begin)/2 +1;
		sum = (begin+end)*high/2;

		printf("Case %d: %d\n", num_case, sum);
	}

	return 0;
}