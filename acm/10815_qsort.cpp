/*使用陣列  然後排序*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char buf[100000],word[100000][201];
int sort_f( const void *a, const void *b)
{
	return( strcmp((char *)a,(char *)b) );
}
main()
{
	int k=0,l,i,j,t;
	while(scanf("%s",buf)!=EOF)
	{	
		for(i=t=0,l=strlen(buf);i<l;i++)
	        if(isalpha(buf[i]))
    	        word[k][t++]=tolower(buf[i]);
	        else 
				word[k][t]='\0',k++,t=0;
		word[k][t]='\0',k++;
	}
	qsort(word,k,sizeof(word[0]),sort_f);
	printf("%s\n",word[0]),strcpy(buf,word[0]);
	for(i=0;i<k;i++)
		if(strcmp(buf,word[i]))
			printf("%s\n",word[i]),strcpy(buf,word[i]);
}

