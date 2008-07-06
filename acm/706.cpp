/* brute force */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	freopen("706.txt", "r", stdin);
	freopen("706_out.txt", "w", stdout);
	bool pe_flag = 0;
	char arr[10][7] = {
	  /*0  1  2  3  4  5  6 */
		1, 1, 1, 1, 1, 1, 0, /*0*/
		0, 1, 1, 0, 0, 0, 0, /*1*/
		1, 1, 0, 1, 1, 0, 1, /*2*/
		1, 1, 1, 1, 0, 0, 1, /*3*/
		0, 1, 1, 0, 0, 1, 1, /*4*/
		1, 0, 1, 1, 0, 1, 1, /*5*/
		1, 0, 1, 1, 1, 1, 1, /*6*/
		1, 1, 1, 0, 0, 0, 0, /*7*/
		1, 1, 1, 1, 1, 1, 1, /*8*/
		1, 1, 1, 1, 0, 1, 1, /*9*/	};
	int length;
	int i, j, index;
	char line[100];

	for(scanf("%d ", &length); length; scanf("%d ", &length))
	{
		index = 0;
		gets(line);
		
		if(!pe_flag)
			pe_flag = 1;
		else
			printf("\n");
		/* the top line */
		for(index=0; line[index]; index++)
		{
			printf(" ");
			for(i=0; i<length; i++)
				if(arr[line[index]-'0'][0])
					printf("-");
				else
					printf(" ");
			printf("  ");
		}
		printf("\n");
			
		/* middle-up line */
		for(i=0; i<length; i++)	
		{
			for(index=0; line[index]; index++)//length+2
			{
				if(arr[line[index]-'0'][5])
					printf("|");
				else
					printf(" ");
				for(j=0; j<length; j++)
					printf(" ");
				if(arr[line[index]-'0'][1])
					printf("|");
				else
					printf(" ");
				printf(" ");
			}
			printf("\n");
		}
		/* middle line */
		for(index=0; line[index]; index++)
		{
			printf(" ");
			for(i=0; i<length; i++)
				if(arr[line[index]-'0'][6])
					printf("-");
				else
					printf(" ");
			printf("  ");
		}
		printf("\n");
		/* middle-down line */
		for(i=0; i<length; i++)	
		{
			for(index=0; line[index]; index++)//length+2
			{
				if(arr[line[index]-'0'][4])
					printf("|");
				else
					printf(" ");
				for(j=0; j<length; j++)
					printf(" ");
				if(arr[line[index]-'0'][2])
					printf("|");
				else
					printf(" ");
				printf(" ");
			}
			printf("\n");
		}
		/* the button line */
		for(index=0; line[index]; index++)
		{
			printf(" ");
			for(i=0; i<length; i++)
				if(arr[line[index]-'0'][3])
					printf("-");
				else
					printf(" ");
			printf("  ");
		}
		printf("\n");
	}
	return 0;
}