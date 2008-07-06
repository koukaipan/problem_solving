/* Fibonacci series*/

#include <stdio.h>
main()
{
    long long fib[52];
    int i, j;
    
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    for(i=3; i<52; i++)
        fib[i] = fib[i-1] + fib[i-2];
    
    for(scanf("%d", &i); i; scanf("%d", &i))
        printf("%lld\n", fib[i+1]);

}

