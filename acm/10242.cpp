#include <stdio.h>

class pt
{
public:
	double x;
	double y;
	bool operator == (const pt& p);
};

bool pt::operator==(const pt& p)
{
	return (x==p.x && y==p.y);
}

main()
{
	pt a, b, c, d;
	pt fourth;
	freopen("10242.txt", "r", stdin);

	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y)!=EOF)
	{
		if(a==c)		//a,c
		{
			fourth.x = d.x-a.x+b.x;
			fourth.y = d.y-a.y+b.y;
		}
		else if(a==d)	//a,d
		{
			fourth.x = c.x-a.x+b.x;
			fourth.y = c.y-a.y+b.y;
		}
		else if(b==c)	//b,c
		{
			fourth.x = d.x-b.x+a.x;
			fourth.y = d.y-b.y+a.y;
		}
		else			//b,d
		{
			fourth.x = c.x-b.x+a.x;
			fourth.y = c.y-b.y+a.y;
		}
		printf("%.3lf %.3lf\n", fourth.x, fourth.y);
	}
}

