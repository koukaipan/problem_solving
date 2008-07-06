/* @JUDGE_ID:  53413RJ  100  C  */

/*
  Compiled by Dev-Cpp 4.9.9.0
  2004.11.11 koukai NCKU_CSIE
*/

#include <stdio.h>

long compute(long);

int main()
{
    long i, j, i_j_buf, count, count_buf, k;
    

    while(scanf("%ld %ld", &i, &j) == 2)
    {
        printf ("%ld %ld", i,j);
        
        //計數器 
        count = 0;
        
        //將i更改為小的值 
        if(i>j)
        {
            i_j_buf = i;
            i = j;
            j = i_j_buf;
        }
        
        //計算每一個值的次數 
        for(k = i; k <= j; k++)
        {
            count_buf = compute(k);
            
            //如果新的值較舊的為大則替代 
            if(count_buf > count)
              count = count_buf;
        }    

        printf(" %ld\n", count);
    }
    return(0);
}

//計算3n+1次數的副函式 
long compute(long n)
{
    long count = 1;
    while(n!=1)
    {
        if(n % 2 == 0)
           n = n / 2;
        else
           n = 3 * n + 1;
           
        count++;
    }
    return(count);
}    
/*@end_of_source_code*/
