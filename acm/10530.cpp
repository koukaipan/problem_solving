#include <stdio.h>

int check[11];
void initial();
void clear(int begin, int direct);

int main()
{
	int num;
	char a[10], b[10];

	initial();

	for(scanf("%d", &num); num!=0; scanf("%d", &num))
	{

		scanf("%s %s", a, b);
		switch(b[0])	//check the information
		{
		//too high
		case 'h':	clear(num, 1);	break;	//clear up-side
		//too low
		case 'l':	clear(num, 0);	break;	//clear down-side
		//right on -> need check
		case 'o':	
			if(check[num])
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			initial();	//initialize
			break;
		}
	}

	return 0;
}

void initial()
{
	for(int i=1; i<=10; i++)
		check[i] = 1;
}

void clear(int begin, int direct)
{
	int i;
	if(direct)	//up-side
		for(i=begin; i<=10 && check[i]; i++)
			check[i] = 0;
	else
		for(i=begin; i>=1 && check[i]; i--)
			check[i] = 0;
}