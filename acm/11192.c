#include <stdio.h>
#include <string.h>

void reverse(int begin, int end, char* str)
{
	char tmp;
	while(begin<end)
	{
		tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		begin++;
		end--;
	}
}

main()
{
	char line[102];
	int n, l;
	int i;
	char tmp;
	int begin, end;
	freopen("11192.txt", "r", stdin);

	while(scanf("%d", &n) && n)
	{
		scanf("%s", line);
		l = strlen(line);
		n = l / n;
		for(i=0; i<l; i+=n)
		{
			/*reverse(i, i+n-1, line);*/
			begin = i;
			end = i+n-1;
			while(begin<end)
			{
				tmp = line[begin];
				line[begin] = line[end];
				line[end] = tmp;
				begin++;
				end--;
			}
		}

		printf("%s\n", line);
	}
}

