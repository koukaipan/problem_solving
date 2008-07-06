/* @JUDGE_ID:  53413RJ  424  C  */


#include <stdio.h>

int swap(char k);

int main()
{
  int i, kk=0, buffer, lenth=0;
  int num[111] = {0}, total[111]={0};
  char a[111]={0};
  

do
{  

  lenth = 0;
  for(i=1; i<=110; i++)
  {
    scanf("%c", &a[i]);
    if (a[i]=='\n')
       break;
    else
      lenth++;
  }
  
  if(a[1] =='0' && a[2]=='\n')
   kk=-1;

  for(i=1; i<=110; i++)
  {
      num[i] = swap(a[i]);
      if (a[i]=='\n')
	break;
  }

  if (kk == -2)
   for(i=1; i<=110; i++)
    num[i] = 0;

  if (lenth == 110)
    kk = -2;
  
  for(i=110; i >= 1; i--)
  {
    if (kk == -2)
      break;
    else if(i > 110-lenth && lenth != 0)
           num[i] = num[i-(110-lenth)];
         else
           num[i] = 0;
  }

   for (i=110; i>=1; i--) 
   {
      total[i] = total[i] + num[i];
      
      if(total[i] >= 10)
        {
            total[i] = total[i] % 10;
            total[i-1] = total[i-1] + 1;
        }
    }
  
}while(kk!=-1);

  for(i=0; i<=110; i++) 
  {
      if (total[i]==0 && total[i+1]==0)
        total[i] = -1;
      else 
        {
            total[i] = -1;
            break;
        }    
  }    

  for (i=0; i<=110; i++)
  {
    if (total[i] != -1)
      printf("%d", total[i]);
  }
  
  printf("\n");

  return(0);
}

int swap(char k)
{
    int x;
    switch(k)
    {
        case '0': x=0;break;
        case '1': x=1;break;
        case '2': x=2;break;
        case '3': x=3;break;
        case '4': x=4;break;
        case '5': x=5;break;
        case '6': x=6;break;
        case '7': x=7;break;
        case '8': x=8;break;
        case '9': x=9;break;
        case '\n': x=-1;break;
    }
    
    return(x);
}
/*@end_of_source_code*/
