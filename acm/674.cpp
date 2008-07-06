#include <stdio.h>

int main()
{
	int arr[7590];
	int i; 
		//value;
	int num;
	//build the table
	//1 cent
	for(i=0; i<7590; i++)
		arr[i] = 1;

	//5 cents
	for(i=5; i<7590; i++)
		arr[i] += arr[i-5];

	//10 cents
	for(i=10; i<7590; i++)
		arr[i] += arr[i-10];

	//25 cents
	for(i=25; i<7590; i++)
		arr[i] += arr[i-25];

	//50 cents
	for(i=50; i<7590; i++)
		arr[i] += arr[i-50];

	while(scanf("%d", &num) == 1)
		printf("%d\n", arr[num]);
	return 0;
}
