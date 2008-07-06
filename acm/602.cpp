#include <stdio.h>

int Compute1(int, int, int);
int Compute2(int, int, int);
int check(int, int, int);
void output(int, int, int, int);

int main()
{
	//freopen("out.txt", "w", stdout);
	int month, date, year;
	int validate;
	int week;
    for(scanf("%d %d %d", &month, &date, &year);
		month||date||year;
		scanf("%d %d %d", &month, &date, &year))
    {
		validate = check(year, month, date);
		
		if(validate)
		{
			output(validate, year, month, date);
			continue;
		}

		if((year>1752) || (year==1752 && month>9) || (year==1752 && month==9 && date>=14))
			week = Compute2(year, month, date);
		else
			week = Compute1(year, month, date);
		output(validate, year, month, date);
        switch(week)
        {
            case 0:
            case 7:
                printf("Sunday\n");
                break;
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            case 6:
                printf("Saturday\n");
                break;
        }
    }    

    return 0;
}

int Compute1(int year, int month, int date)
{
	int days = 0;
    int bissextile = (year-1)/4;
    days += bissextile*366 + (year-1-bissextile)*365 ;

	switch(month)
	{
		case 2:
			days += 31;	break;
		case 3:
			days += 31; break;
		case 4:
			days += 62; break;
		case 5:
			days += 92; break;
		case 6:
			days += 123;	break;
		case 7:
			days += 153;	break;
		case 8:
			days += 184;	break;
		case 9: 
			days += 215;	break;
		case 10:
			days += 245;	break;
		case 11: 
			days += 276;	break;
		case 12:
			days += 306;	break;
		default:
			break;
	}
	if(month>2 && year%4==0)
		days += 29;
	else if(month > 2)
		days += 28;

	days += date-1;

	return (days+6)%7;	
}

int Compute2(int Year, int Month, int Day)
{
int TempYear, TempMonth, i, j;

if (Month >= 3)
{
   TempMonth = Month - 2;
   TempYear = Year;
}
else
{
   TempMonth = Month + 10;
   TempYear = Year - 1;
}

j = TempYear + (int)(TempYear / 4) - (int)(TempYear / 100) +
    (int)(TempYear / 400) + (int)(2.6 * TempMonth - 0.2) + Day;
i = j - 7*(int)(j / 7);

return (i);
}

int check(int year, int month, int date)
{
	int error=0;

	if( year<=0 )
		return 1;

	if( month<1 || month >12)
		return 1;
	
	if( year==1752 && month==9 && date>2 && date <14)
		return 1;

	switch(month)
	{
		case 1: case 3: case 5: case 7:
		case 8: case 10: case 12:
			if(date<1 || date>31)
				error=1;
			break;
		case 4: case 6: case 9: case 11:
			if(date<1 || date>30)
				error=1;
			break;
		case 2:
			if(year%4!=0)
			{
				if(date<1 || date>28)
					error=1;
			}
			else if(year<=1752 && year %4==0)
			{
				if(date<1 || date>29)
					error=1;
			}
			else if(year%100==0)
			{
				if(year%400==0)
				{
					if(date<1 || date>29)
						error=1;
				}
				else
				{
					if(date<1 || date>28)
						error=1;
				}
			}
			else 
			{
				if(date<1 || date>29)
					error=1;
			}
			break;
	}
	return error;
}

void output(int validate, int year, int month, int date)
{
	if(validate)
	{
		printf("%d/%d/%d is an invalid date.\n", month, date, year);
		return;
	}
	else
	{
		switch(month)
		{
		case 1:
			printf("January");	break;
		case 2:
			printf("February");	break;
		case 3:
			printf("March");	break;
		case 4:
			printf("April");	break;
		case 5:
			printf("May");		break;
		case 6:
			printf("June");		break;
		case 7:
			printf("July");		break;
		case 8:
			printf("August");	break;
		case 9:
			printf("September");	break;
		case 10:
			printf("October");	break;
		case 11:
			printf("November");	break;
		case 12:
			printf("December");	break;
		}
		printf(" %d, %d is a ", date, year);

	}
}