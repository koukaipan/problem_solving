/* @JUDGE_ID:  53413RJ  10035  C  */

#include <stdio.h>

int main()
{
    int i=0,
        num_a[15], a=0,
        num_b[15], b=0,
        counts=0,
        buf;
    
    char one;
    
    
    
    while(1)
    {
    for(i=0; i<15; i++)
     {
         num_a[i] = 0;
         num_b[i] = 0;
     }    
    i=0;
    
    for( scanf("%c", &one);
         one != ' ' && one != '\n';
         scanf("%c", &one) )
        num_a[i++] = (int) one - 48;

    a = i-1;
    
    for( i=14; i>=(14-a); i--)
    {
        buf = num_a[i];
        num_a[i] = num_a[i-(14-a)];
        num_a[i-(14-a)] = buf;
    }    
 

    i = 0;
    
    for( scanf(" %c", &one);
         one != ' ' && one != '\n';
         scanf("%c", &one) )
        num_b[i++] = (int) one - 48;
     
    b = i-1;
    
 
    for( i=14; i>=(14-b); i--)
    {
        buf = num_b[i];
        num_b[i] = num_b[i-(14-b)];
        num_b[i-(14-b)] = buf;
    }    
    
    if (a==0 && b==0 && num_a[14]==0 && num_b[14]==0)
        break;
        
    counts = 0;
      

    for( i=14; i>=(14-a) || i>=(14-b); i--)
    {
        if (num_a[i] + num_b[i] >=10)
        {
            num_a[i] = (num_a[i] + num_b[i]) % 10;
            num_b[i-1] += 1;
            counts++;
        }
        else
            num_a[i] = num_a[i] + num_b[i];
    }    
     
    switch(counts)
    {
        case 0: printf("No carry operation.\n");break;
        case 1: printf("1 carry operation.\n");break;
        default : printf("%d carry operations.\n", counts);break;
    }
    
    }      
    return(0);
}
/*@end_of_source_code*/
