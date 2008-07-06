#include <stdio.h>
#include <string.h>

#define ABS(x) (x<0 ? -x : x)

int main()
{
	int num_case,
		i, j, length,
		which;
	
	int coin[12];
	char left[7], right[7], info[6];

	scanf("%d", &num_case);

	for(; num_case>0; num_case--)
	{
		//initialize
		for(i=0; i<12; i++)
			coin[i] = 0;
		which = 99;

		//input 3 times
		for(i=0; i<3; i++)
		{
			scanf("%s %s %s", left, right, info);
			length = strlen(left);
			switch(info[0])
			{
			case 'e':	//even means these coins are true
				//left
				for(j=0; j<length; j++)
					coin[left[j]-'A'] = 99;
				//right
				for(j=0; j<length; j++)
					coin[right[j]-'A'] = 99;
				break;
			case 'u':	//up means the coins at right-side are light
				//left -> heavy
				for(j=0; j<length; j++)
					if(coin[left[j]-'A'] != 99)
						coin[left[j]-'A']++;
				//right -> light
				for(j=0; j<length; j++)
					if(coin[right[j]-'A'] != 99)
						coin[right[j]-'A']--;
				break;
			case 'd':	//down means the coins at right-side are heavy
				//left -> light
				for(j=0; j<length; j++)
					if(coin[left[j]-'A'] != 99)
						coin[left[j]-'A']--;
				//right -> heavy
				for(j=0; j<length; j++)
					if(coin[right[j]-'A'] != 99)
						coin[right[j]-'A']++;
				break;
			}//end of switch
		}//end of input

		//to find the fake
		for(i=0; i<12; i++)
		{
			if(coin[i]!=99)
			{
				if( which == 99)
					which = i;
				if( ABS(coin[which]) < ABS(coin[i]) )
					which = i;
			}
		}

		//output
		printf("%c is the counterfeit coin and it is %s.\n", 'A'+which, coin[which]<0?"light":"heavy");

	}//end of big for

	return 0;
}
