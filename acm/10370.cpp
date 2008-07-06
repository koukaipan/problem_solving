#include <stdio.h>


int main()
{
	int num_testdata,		//代戈掸计
		num_people,			//计
		num_people_2,		//禬筁キА计
		grades[1000],		//だ计皚
		sum;				//羆だ
	int i, j;
	double percentage,		//禬筁キА计κだゑ
			avg;			//キАだ计

	scanf("%d", &num_testdata);
	for(i=0; i<num_testdata; i++)
	{
		scanf("%d", &num_people);
		sum=0;
		for(j=0; j<num_people; j++)
		{
			scanf("%d", &grades[j]);
			sum += grades[j];
		}

		//compute the average
		avg = sum / num_people;

		num_people_2 = 0;
		//compute the percentage
		for(j=0; j<num_people; j++)
			if(grades[j]>avg)
				num_people_2++;

		percentage = (double)num_people_2 / (double)num_people;

		printf("%.3lf%%\n", percentage*100);
	}//end of for-loop

	return 0;
}