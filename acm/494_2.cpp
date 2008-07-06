/* @JUDGE_ID:  53413RJ  494  C  */
#include <stdio.h>

int main()
{
    int amounts=0,
        word=0,
        i;
    char one;
    
    while(scanf("%c", &one) ==1 )
    {
        if ('A'<=one && one<='Z' || 'a'<=one && one<='z')
            word = 1;
        else if (word == 1)
            {
                amounts++;
                word=0;
            }
            
        if (one == '\n')
            {
                printf("%d\n", amounts);
                word = 0;
                amounts = 0;
            }    
            
    }
    return(0);
}
/*@end_of_source_code*/
