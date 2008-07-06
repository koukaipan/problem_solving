#include <stdio.h>
#define MAX(a,b)(a>b?a:b)
main()
{
    int n,cases=1;
    long long max,min,tt,t,ans;
    while(scanf("%d",&n)!=EOF &&n)
    {
        for(max=min=1,ans=-99999;n;n--)
        {
            scanf("%I64d",&t);
            ans=MAX(ans,t);
            if(t>0)
            {
                max*=t;    
                if(min!=1)
                    min*=t;
                ans=MAX(ans,max);
            }
            if(t<0)
            {
                tt=max;
                if(min!=1)
                    max=min*t,min=tt*t,ans=MAX(ans,max);
                else
                    min=max*t,max=1;
            }
            if(t==0)
                max=min=1;
        }    
        printf("Case #%d: The maximum product is %I64d.\n\n",cases++,MAX(ans,0));
    }
}
