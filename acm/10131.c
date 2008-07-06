/* sort (on weight) and then LIS (on IQ) */

#include <stdio.h>
#include <stdlib.h>

#define MAX 12

struct elephant{
	int weight;
	int iq;
	int index;
}data[MAX];

int best[MAX], prev[MAX];

int sort_f( const void *a , const void *b ) 
{
	return (*(struct elephant*)a).weight - (*(struct elephant *)b).weight ;
}

int lds(int n) /* longest decrease subsequence */
{
   int i, j, max;

   for ( i=0; i<n; i++ ) best[i] = 1, prev[i] = i;

   for ( i=1; i<n; i++ )
      for ( j=0; j<i; j++ )
         if ( data[i].iq < data[j].iq && best[i] < best[j] + 1 )
            best[i] = best[j] + 1, prev[i] = j;

   for ( max=0, i=1; i<n; i++ )
      if ( best[max] <= best[i] )
         max = i;

   return max; /* return value is the max length index of best[] */
}

void output(int index)
{
	if(prev[index]!=index)
		output(prev[index]);
	printf("%d\n", data[index].index+1);
	return;	
}

main()
{
	int i=0, k;
	freopen("10131.txt", "r", stdin);
	/* input */
	while(scanf("%d %d", &data[i].weight, &data[i].iq)==2)
		data[i].index = i++;

	/* sort on weight */
	qsort((void*)data, i, sizeof(struct elephant), sort_f);

	/* lds */
	k = lds(i);
	printf("%d\n", best[k]);
	output(k);

}

	
