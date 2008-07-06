/* @JUDGE_ID: 53413RJ 579 C */
#include <stdio.h>

int main()
{
    int hour, min;
    float angle;
    
    while(scanf("%d:%d", &hour, &min)==2)
    {
        if (hour==0&&min==0)
           break;
        
        angle=hour*30.0+min*0.5-min*6.0;
        if (angle<0)
            angle = -angle;
        if (angle>180)
            angle = 360 - angle;
        
        printf("%.3f\n", angle);
    }        
return 0;
}
/*@end_of_source_code*/

