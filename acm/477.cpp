#include <iostream>

using namespace std;

struct figure_t
{
	char sign;
    double x1, //left-top X
           y1, //left-top Y 
           x2, //right-bottom X 
           y2; //right-bottom Y
	double radius;
};

struct coordinate_t
{
	double x,y;
};

int main()
{
    struct figure_t fig[10];
	struct coordinate_t pt;
    char sign;
    int i, 
		noneFlag,
        NumOfFig=0,
		NumOfPt=0;
    
    //input the figures' data
    //scanf("%c", &sign);
	for(cin>>sign; sign!='*'; cin>>sign)
    {
		fig[NumOfFig].sign = sign;
		switch(sign)
		{
		case 'r':
			cin >> fig[NumOfFig].x1
				>> fig[NumOfFig].y1
				>> fig[NumOfFig].x2
				>> fig[NumOfFig].y2;

			break;
		case 'c':
			cin >> fig[NumOfFig].x1
				>> fig[NumOfFig].y1
				>> fig[NumOfFig].radius;
			break;
		}
        NumOfFig++;
    }
    //cout << NumOfFig;

	//input the points' data
	for(cin>>pt.x>>pt.y; pt.x!=9999.9 || pt.y!=9999.9; cin>>pt.x>>pt.y)
	{
		noneFlag=0;
		NumOfPt++;

		//analysis
		for(i=0; i<NumOfFig; i++)
		{
			if(fig[i].sign == 'r')
			{
				if(pt.x>fig[i].x1)
				if(pt.y<fig[i].y1)
				if(pt.x<fig[i].x2)
				if(pt.y>fig[i].y2)
				{
					cout << "Point " <<NumOfPt <<" is contained in figure " <<i+1<<endl;
					noneFlag=1;
				}
			}
			else//circle
			{
				if( (pt.x-fig[i].x1)*(pt.x-fig[i].x1) + (pt.y-fig[i].y1)*(pt.y-fig[i].y1) <= fig[i].radius*fig[i].radius)
				{
					cout << "Point " <<NumOfPt <<" is contained in figure " <<i+1<<endl;
					noneFlag=1;
				}
			}				

		}

		if(!noneFlag)
			cout<<"Point "<<NumOfPt <<" is not contained in any figure" <<endl;
	}//End of while loop

    return 0;
}

