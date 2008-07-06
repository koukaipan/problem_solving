#include <stdio.h>

#define MAX 100000
#define YES 1
#define NO  0

int main()
{
	char s[MAX], t[MAX];
	int i, j, subString;

	while(scanf("%s %s", s, t)==2)
	{
		subString = YES;
		for(i=j=0; s[i]; i++)
		{
			while(t[j]!=s[i] && t[j])
				j++;
			if(s[i] == t[j] && t[j+1])
				j++;

			if(!t[j])
			{
				subString = NO;
				break;
			}
		}
		printf("%s\n", subString ? "Yes" : "No");
	}

	return 0;
}