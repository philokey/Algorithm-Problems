#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
const int INF = 1111111111;
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;

double dist(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
Point gao(Point p,bool tp,double l)
{
	Point ret;
	if(tp==0)
		ret = Point(p.x,2*l-p.y);
	else
		ret = Point(2*l-p.x,p.y);
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	double w,d;
	char ord[1005];
	Point s,t;
	scanf("%lf%lf",&w,&d);
	s.input();
	t.input();
	scanf("%s",ord);
	for(int i = 0; ord[i]; i++)
	{
		if(ord[i]=='B')
			s = gao(s,0,d);
		else if(ord[i]=='F')
			s = gao(s,0,0);
		else if(ord[i]=='L')
			s = gao(s,1,0);
		else if(ord[i]=='R')
			s = gao(s,1,w);
	}
	printf("%.4f\n",dist(s,t));
	return 0;
}
