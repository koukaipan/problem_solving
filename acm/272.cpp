/* @JUDGE_ID:  53413RJ  272 C */

#include <stdio.h>

int main()
{
    char one;
    int counts=1;

    while( scanf("%c", &one) == 1)
    {
        if(one == '"')
          {
              switch(counts%2)
              {
                  case(1):printf("``");counts++;break;
                  case(0):printf("''");counts++;break;
              }
          }
          
          
        else
          printf("%c", one);
        
    }    

    return(0);
}
/*@end_of_source_code*/
