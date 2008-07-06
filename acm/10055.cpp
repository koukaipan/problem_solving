/* @JUDGE_ID:  53413RJ  10055  C  */

#include <stdio.h>
#include <math.h>

int main()
{
    double army, enemy;
    
    while(scanf("%lf %lf", &army, &enemy)==2)
       printf("%.0lf\n", fabs(enemy - army));
    
    return(0);
}
/*@end_of_source_code*/
