#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 101

struct _team{
	int no;
	int solved;
	int time;
	int count_wa[10];
	unsigned char problem[10];
	unsigned char submit;
}team[MAX];

void init();
int sort_f( const void *a , const void *b ) ;

main()
{
	int num_case, i, j;
	char line[MAX], result;
	int t, p, time;

	freopen("10258.txt", "r", stdin);

	scanf("%d", &num_case);
	gets(line);
	for(i=0,gets(line); i<num_case; i++)
	{
		if(i>0)
			putchar('\n');

		
		init();

		while(gets(line) && strlen(line))
		{
			sscanf(line, "%d %d %d %c", &t, &p, &time, &result);
			if(!team[t].submit)
				team[t].submit = 1;
			switch(result)
			{
			case 'C':
				if(team[t].problem[p] != 1)
				{
					team[t].problem[p] = 1;
					team[t].solved++;
					team[t].time += team[t].count_wa[p]*20 + time;
				}
				break;
			case 'I':
				team[t].count_wa[p]++;
				break;
			default:
				break;
			}
		}
		qsort((void*)team, MAX, sizeof(team[0]), sort_f);
		for(j=0; j<MAX; j++)
			if(team[j].submit)
				printf("%d %d %d\n", team[j].no, team[j].solved, team[j].time);
	}
}

void init()
{
	int i;
	memset(team, 0, sizeof(struct _team)*10);
	for(i=0; i<MAX; i++)
	{
		team[i].no = i;
	}
}

int sort_f( const void *a , const void *b ) 
{
	/*if(!(*(struct _team*)a).submit && !(*(struct _team*)b).submit)
		return (*(struct _team*)a).no - (*(struct _team*)b).no;
	else if(!(*(struct _team*)b).submit)
		return 1;
	else if(!(*(struct _team*)a).submit)
		return -1;*/
	if(!(*(struct _team*)a).solved && !(*(struct _team*)b).solved)
		return (*(struct _team*)a).no - (*(struct _team*)b).no;

	else if((*(struct _team*)a).solved == (*(struct _team*)b).solved)
		return (*(struct _team*)a).time - (*(struct _team*)b).time;

	return (*(struct _team*)b).solved - (*(struct _team*)a).solved;
}