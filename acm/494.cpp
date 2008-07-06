/* @JUDGE_ID:  53413RJ  494  C  */
#include <stdio.h>
#include <string.h>

int main()
{
    int amounts,
        word,
        i;
    char line[1000];
    
    while(gets(line))
    {
    
    amounts = 0;
    word = 0;
    for( i=0;
         line[i]!='\0';
         i++ )
        {
            if ('A'<=line[i] && line[i]<='Z' || 'a'<=line[i] && line[i]<='z')
                word = 1;
            else if (word == 1)
            {
                amounts++;
                word=0;
            }
            
            if (line[i] == '\n')
                break;
        }
    printf("%d\n", amounts);
    }
    return(0);
}
/*@end_of_source_code*/
