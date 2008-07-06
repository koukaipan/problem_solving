#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char buf_card[3], buf_word[22];
	char card[53][2]; /* 0 is value, 1 is suit */
	int i, count, pos;
	bool pe_flag=false;
	freopen("10978.txt", "r", stdin);
	freopen("10978_out.txt", "w", stdout);

	for(scanf("%d", &n); n!=0; scanf("%d", &n))
	{
		/* initialize */
		for(i=0; i<53; i++)
			card[i][0] = card[i][1] = 0;
		pos = -1;

		/* input */
		for(i=0; i<n; i++)
		{
			scanf("%s %s", buf_card, buf_word);
			count = strlen(buf_word);
			while(count)
			{
				pos = (pos+1) % n;
				if(!card[pos][0])
					count--;
			}
			card[pos][0] = buf_card[0];
			card[pos][1] = buf_card[1];
		}

		/* output */
		for(i=0, pe_flag=false; i<n; i++)
		{
			if(!pe_flag)
				pe_flag = true;
			else
				putchar(' ');
			printf("%c%c", card[i][0], card[i][1]);
		}
		printf("\n");
	}

	return 0;
}
					




