#include <stdio.h>


int main()
{
	int num_testdata,		//���굧��
		num_people,			//�H��
		num_people_2,		//�W�L�������H��
		grades[1000],		//���ư}�C
		sum;				//�`��
	int i, j;
	double percentage,		//�W�L�����H�ƪ��ʤ���
			avg;			//��������

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