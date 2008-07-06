/* DP , LIS , sorting */
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIMENSION	10
#define MAX_BOX			30

struct box_t{
	int index;
	int size[MAX_DIMENSION];
}box[MAX_BOX];

int n_box, n_dime;
int best[MAX_BOX], prev[MAX_BOX];

void insertion_sort(int list[]);
int sort_f( const void *a , const void *b );
int lis();
int compare_box(int a, int b);
void output(int index);

main()
{
	int i, j, k;

	freopen("103.txt", "r", stdin);

	while(scanf("%d %d", &n_box, &n_dime)!=EOF)
	{
		/* input */
		for(i=0; i<n_box; i++)
		{
			box[i].index = i;
			for(j=0; j<n_dime; j++)
			{
				scanf("%d", &box[i].size[j]);
			}
			insertion_sort(&box[i].size[0]);
		}
		qsort((void*)box, n_box, sizeof(box[0]), sort_f);

		k = lis();
		printf("%d\n", best[k]);
		output(k);
	}
}

void insertion_sort(int list[])
{
	int i, j, tmp;
	
	for(i=1; i<n_dime; i++)
	{
		j = i;
		while((j>0) && (list[j] < list[j-1]))
		{
			tmp = list[j];
			list[j] = list[j-1];
			list[j-1] = tmp;

			j--;
		}
	}
}

int sort_f( const void *a , const void *b ) 
{
	return (*(struct box_t*)a).size[0] - (*(struct box_t*)b).size[0];
}

int lis() /* longest increase subsequence */
{
	int i, j, max;

	for ( i=0; i<n_box; i++ ) best[i] = 1, prev[i] = -1;

	for ( i=1; i<n_box; i++ )
		for ( j=0; j<i; j++ )
			if ( compare_box(i,j)==1 && best[i] < best[j] + 1 )
				best[i] = best[j] + 1, prev[i] = j;

	for ( max=0, i=1; i<n_box; i++ )
		if ( best[max] <= best[i] )
			max = i;

	return max; /* return value is the max length index of best[] */

}

void output(int max)/* max is index */
{
	unsigned char tmp[MAX_BOX];
	int i, p;
	for(i=0, p=max;prev[p]!=-1; p = prev[p])
		tmp[i++] = p;

	tmp[i] = p;

	for(; i>0; i--)
		printf("%d ", box[tmp[i]].index+1);
	printf("%d\n", box[max].index+1);

	
	return;	
}

/* return 1 iff box[a] > box[b] */
int compare_box(int a, int b)
{
	int i;
	for(i=0; i<n_dime && box[a].size[i] > box[b].size[i]; i++);

	if (i<n_dime)
		return 0;
	else
		return 1;
}

