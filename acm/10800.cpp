/* @JUDGE_ID:  53413RJ  10800  C++  */

#include <stdio.h>
#include <string.h>

void print_space(int count)
{
	for(int i=0; i<count; i++)
		putchar(' ');
}

int main()
{
	int i, j,	//var for loop
		n,		//number of 
		lenth,	//lenth of string
		height,	//height of the pic
		buf,	//buffer
		value[50],
		min, max;
	//bool pe_flag=false;
	int space_count;
	char str[50];
	freopen("10800.txt", "r", stdin);
	//freopen("10800_out.txt", "w", stdout);
	scanf("%d", &n); //input the number
	for(i=0; i<n; i++)
    {
		//clear the string
        for(j=0; j<50; j++)
            str[j]=0;

		//input the info
		scanf("%s", str);
		lenth = strlen(str);

		//analys
		//1.find the height
		lenth = strlen(str);
		max=min=buf=height=0;

		//find the min and their value
		for(j=0; j<lenth; j++)
		{
			switch(str[j])
			{
				case 'R':buf++;break;
				case 'F':buf--;break;
				case 'C':break;
			}
			value[j] = buf;
			min = buf<min ? buf : min;
		}
		//all value minus min and find the max
		for(j=0; j<lenth; j++)
		{
			value[j] -= min;
			if(str[j] == 'R')
				value[j]--;
			if(value[j] > max)
				max = value[j];
		}
        
		//output
		printf("Case #%d:\n", i+1);

        for(buf=max; buf>=0; buf--)
		{
			printf("| ");
			for(j=0,space_count=0; j<lenth; j++)
			{
				if(value[j]==buf)
				{
					print_space(space_count);
					switch(str[j])
					{
					case 'R': printf("/");break;
					case 'C': printf("_");break;
					case 'F': printf("\\");break;
					}
					space_count = 0;
				}
				else
					space_count++;
			}
			printf("\n");
		}

		printf("+-");
		for(j=0; j<lenth; j++)
			printf("-");
		printf("-");
		/*if(i<n-1)*/
			printf("\n\n");

	}
    return 0;
}
/*@end_of_source_code*/ 
