#include <stdio.h>

int main()
{
	int arr[4];
	int degree;

	while(scanf("%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3]) == 4)
	{
		if(arr[0]==0 && arr[1]==0 && arr[2]==0 && arr[3]==0)
			break;

		degree=0;
		//1. 720
		//2. clockwise
		degree += (arr[0]>=arr[1] ? (arr[0]-arr[1]) : (arr[0]-arr[1]+40));

		//3. 360
		//4. counter-clockwise
		degree += (arr[1]<arr[2] ? (arr[2]-arr[1]) : (arr[2]-arr[1]+40));
		//5. clockwise
		degree += (arr[2]>=arr[3] ? (arr[2]-arr[3]) : (arr[2]-arr[3]+40));

		printf("%d\n", 1080+9*degree);
	}// end of while-loop

	return 0;
}

