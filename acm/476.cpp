#include <iostream>

using namespace std;

struct rectangle_t
{
    double x1, //left-top X
           y1, //left-top Y 
           x2, //right-bottom X 
           y2; //right-bottom Y
};

struct coordinate_t
{
	double x,y;
};

int main()
{
    struct rectangle_t fig[10];
	struct coordinate_t pt;
    char sign;
    int i, 
		noneFlag,
        NumOfRect=0,
		NumOfPt=0;
    
    //input the rectangles' data
    //scanf("%c", &sign);
	cin>>sign;

    while( sign != '*')
    {
        cin >> fig[NumOfRect].x1
			>> fig[NumOfRect].y1
			>> fig[NumOfRect].x2
			>> fig[NumOfRect].y2;
        NumOfRect++;
        cin >> sign;
    }
    //cout << NumOfRect;

	//input the points' data
	while(1)
	{
		cin >> pt.x
			>> pt.y;
		
		if(pt.x==9999.9 && pt.y==9999.9)
			break;
		
		noneFlag=0;
		NumOfPt++;

		//analysis
		for(i=0; i<NumOfRect; i++)
		{
			//if(pt.x>fig[i].x1 && pt.y<fig[i].y1 && pt.x<fig[i].x2 && pt.y>fig[i].y2)
			if(pt.x>fig[i].x1)
			if(pt.y<fig[i].y1)
			if(pt.x<fig[i].x2)
			if(pt.y>fig[i].y2)
			{
				cout << "Point " <<NumOfPt <<" is contained in figure " <<i+1<<endl;
				noneFlag=1;
			}
		}

		if(!noneFlag)
			cout<<"Point "<<NumOfPt <<" is not contained in any figure" <<endl;
	}//End of while loop

    return 0;
}

