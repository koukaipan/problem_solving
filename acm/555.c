#include <stdio.h>
#include <stdlib.h>

struct card_
{
	char face;
	char suit;
};

struct people_
{
	struct card_ cards[13];
}people[4];

int sort_f( const void *a , const void *b );
char conv1(char face);
char unconv1(char face);
char conv2(char suit);
char unconv2(char suit);
/* 0:S, 1:W, 2:N, 3:E */

main()
{
	char begin, ch, face, suit;
	int pos, i;

	freopen("555.txt", "r", stdin);

	while(scanf("%c%c", &begin, &ch) && begin!='#')
	{
		switch(begin)
		{
		case 'S':	pos = 0;	break;
		case 'W':	pos = 1;	break;
		case 'N':	pos = 2;	break;
		case 'E':	pos = 3;	break;
		}

		pos = (pos+1) % 4;

		for(i=0; i<26; i++, pos=(pos+1)%4)
		{
			scanf("%c%c", &face, &suit);
			people[pos].cards[i/4].face = conv1(face);
			people[pos].cards[i/4].suit = conv2(suit);
		}
		scanf("%c", &ch);
		for(; i<52; i++, pos=(pos+1)%4)
		{
			scanf("%c%c", &face, &suit);
			people[pos].cards[i/4].face = conv1(face);
			people[pos].cards[i/4].suit = conv2(suit);
		}
		scanf("%c", &ch);
		qsort(people[0].cards, 13, sizeof(struct card_), sort_f);
		qsort(people[1].cards, 13, sizeof(struct card_), sort_f);
		qsort(people[2].cards, 13, sizeof(struct card_), sort_f);
		qsort(people[3].cards, 13, sizeof(struct card_), sort_f);

		printf("S:");
		for(i=0; i<13; i++)
			printf(" %c%c", unconv1(people[0].cards[i].face), unconv2(people[0].cards[i].suit));
		printf("\nW:");
		for(i=0; i<13; i++)
			printf(" %c%c", unconv1(people[1].cards[i].face), unconv2(people[1].cards[i].suit));
		printf("\nN:");
		for(i=0; i<13; i++)
			printf(" %c%c", unconv1(people[2].cards[i].face), unconv2(people[2].cards[i].suit));
		printf("\nE:");
		for(i=0; i<13; i++)
			printf(" %c%c", unconv1(people[3].cards[i].face), unconv2(people[3].cards[i].suit));
		printf("\n");
	}
}

int sort_f( const void *a , const void *b ) 
{
	if((*(struct card_*)a).face == (*(struct card_*)b).face)
		return (*(struct card_*)a).suit - (*(struct card_*)b).suit;
	else
		return (*(struct card_*)a).face - (*(struct card_*)b).face;
}

char conv1(char face)
{
	switch(face)
	{
	case 'S':		return 3;
	case 'H':		return 4;
	case 'D':		return 2;
	case 'C':		return 1;
	default:		return 0;
	}
}

char unconv1(char face)
{
	switch(face)
	{
	case 3:		return 'S';
	case 4:		return 'H';
	case 2:		return 'D';
	case 1:		return 'C';
	default:		return '0';
	}
}

char conv2(char suit)
{
	if(suit<='9')
		return suit-'0';
	switch(suit)
	{
	case 'T':		return 10;
	case 'J':		return 11;
	case 'Q':		return 12;
	case 'K':		return 13;
	}
}
char unconv2(char suit)
{
	if(suit<=9)
		return suit+'0';
	switch(suit)
	{
	case 10:		return 'T';
	case 11:		return 'J';
	case 12:		return 'Q';
	case 13:		return 'K';
	}
}