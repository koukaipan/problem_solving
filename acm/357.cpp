#include <stdio.h>

int main()
{
	long long arr[30001];
	int i; 
		//value;
	int num;
	//build the table
	//1 cent
	for(i=0; i<30001; i++)
		arr[i] = 1;

	//5 cents
	for(i=5; i<30001; i++)
		arr[i] += arr[i-5];

	//10 cents
	for(i=10; i<30001; i++)
		arr[i] += arr[i-10];

	//25 cents
	for(i=25; i<30001; i++)
		arr[i] += arr[i-25];

	//50 cents
	for(i=50; i<30001; i++)
		arr[i] += arr[i-50];

	while(scanf("%d", &num) == 1)
		if(arr[num]==1)
			printf("There is only 1 way to produce %d cents change.\n", num);
		else
			printf("There are %lld ways to produce %d cents change.\n", arr[num], num);


	return 0;
}
