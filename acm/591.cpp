/* @JUDGE_ID:  53413RJ  591  C  */

#include <stdio.h>
#include <conio.h>

int main()
{
    int num[50],
        n,
        i,
        ave,
        amounts,
        acounts;
    
    acounts = 1;
    while( scanf("%d", &n) == 1)
    {
        if(n==0)
          break;

        i=0;
        ave=0;
        amounts=0;
        
        for(i=0; i<n; i++)
        {
            scanf("%d", &num[i]);
            ave += num[i];
        }    
        
        ave /= n;
        
        for(i=0; i<n; i++)
          if(num[i]>ave)
            amounts += (num[i]-ave);
            
        printf("Set #%d\n", acounts++);
        printf("The minimum number of moves is %d.\n\n", amounts);
    }    




    getch();
    return(0);
}

