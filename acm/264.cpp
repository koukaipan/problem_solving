/* @JUDGE_ID:  53413RJ  264  C  */


#include <stdio.h>

int main()
{
    long i, line;
    long k, l;
    long n;
    long p, q;
    
    while ( scanf("%d", &n)==1)
    {
        l = n;
        k = 1;
        
        for(i=1; i<l; i++)
        {
            k++;
            l = l - i;
        }
        
        if(k%2==1)
        {
            q = (k+1)-l;
            p = l;
        }
        else
        {
            q = l;
            p = (k+1)-l;
        }
        
        printf("TERM %d IS %d/%d\n", n, q, p);
    }

    return(0);
}
/*@end_of_source_code*/
