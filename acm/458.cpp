/* @JUDGE_ID:  53413RJ  458 C */

#include <stdio.h>

int main()
{
    char one;
        
    while( scanf("%c", &one) == 1)
    {
        if(one != '\n')
          printf("%c", one-7);
        else
          printf("%c", one);
    }    

    return(0);
}
/*@end_of_source_code*/
