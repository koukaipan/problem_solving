#include <stdio.h>
#include <string.h>

void main()
{
	char str[200], ch;
	int i, length;
	freopen("483.txt", "r", stdin);

	while(scanf("%s%c", str, &ch)!=EOF)
	{
		length = strlen(str);
		for(i=strlen(str)-1; i>=0; i--)
			printf("%c", str[i]);
		printf("%c", ch);
	}
}