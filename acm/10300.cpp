/* @JUDGE_ID:  53413RJ  10300  C  */

#include <stdio.h>

int main()
{
    int counts;
    int i, j;
    int farmers;
    long area, animals, level;
    long money;
    
        
    scanf("%d", &counts);
    for (i=1; i<=counts; i++)
    {
        scanf("%d", &farmers);
        money = 0;
        for (j=1; j<=farmers; j++)
        {
            scanf("%ld %ld %ld", &area, &animals, &level);
            money = money + area * level;
        }
        printf("%ld\n", money);
    }        
    return(0);
}
/*@end_of_source_code*/
