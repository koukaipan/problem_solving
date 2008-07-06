#include <stdio.h>

int main()
{
    int n,block[50];
    int sum, avg, counts=0, move;
    int i;
    
    while(1)
    {
    scanf("%d", &n);
    
    if(n==0)
        break;
        
    for(sum=0, i=0; i<n; i++)
    {
        scanf("%d", &block[i]);
        sum += block[i];
    }
    avg = sum/n;
    
    for(move=0, i=0; i<n; i++)
        move += block[i]>avg ? block[i]-avg : 0;
    
    printf("Set #%d\n", ++counts);
    printf("The minimum number of moves is %d\n", move);
    }

    return 0;
}

