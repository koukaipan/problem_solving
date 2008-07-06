#include <stdio.h>

int fn(int x, int degree)
{
	int ans=1;
	for(int i=0; i<degree; i++)
		ans*=x;

	return ans;
}

int main()
{
	int x,
		length;
	int c[1000];
	int i=0;
	int ans;
	bool pe_flag = false;
	char info;
	freopen("498.txt", "r", stdin);
	freopen("498_out.txt", "w", stdout);

	while(scanf("%d%c", &c[i++], &info) == 2)
	{
	//input cn......c1
	for(; info!='\n'; scanf("%d%c", &c[i++], &info));
	length = i-1;

	//compute
	for(scanf("%d%c", &x, &info); info!='\n'; scanf("%d%c", &x, &info))
	{
		ans=0;
		for(i=0; i<=length; i++)
			ans += (c[i] * fn(x, length-i));
		//output
		printf("%d ", ans);
	}
		//do the last time
		ans=0;
		for(i=0; i<=length; i++)
			ans += (c[i] * fn(x, length-i));
		//output
		printf("%d", ans);
		printf("\n");

	
		i=0;
	}//end of main while loop

	return 0;
}