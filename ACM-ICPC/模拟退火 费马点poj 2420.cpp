#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <ctime>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1005;
const double INF = 1e50;
const int NUM = 20;
int n;
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y,val;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN],may[NUM];
double frand()
{
	return rand()%1000/1000.0;
}

double dist(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double judge(Point a)
{
	double ret = 0;
	for(int i = 0; i < n; i++)
		ret+=dist(a,p[i]);
	return ret;
}
Point get(Point a,Point b)
{
	Point p;
	double x = a.x+(b.x-a.x)*frand();
	double y = a.y+(b.y-a.y)*frand();
	p = Point(x,y);
	p.val = judge(p);
	return p;
}
double solve(double x,double y)
{
	for(int i = 0; i < NUM; i++)
		may[i] = get(Point(0,0),Point(x,y));
	double step = max(x,y);
	while(step>0.1)
	{
		for(int i = 0; i < NUM; i++)
			for(int j = 0; j < NUM; j++)
			{
				Point p1,p2,tmp;
				p1 = Point(max(0.0,may[i].x-step),max(0.0,may[i].y-step));
				p2 = Point(min(x,may[i].x+step),min(y,may[i].y+step));
				tmp = get(p1,p2);
				if(dcmp(may[i].val-tmp.val)>0)
					may[i] = tmp;
			}
		step*=0.9;
	}
	double ans = INF;
	for(int i = 0; i < NUM; i++)
		ans = min(ans,may[i].val);
	return ans;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	srand(time(NULL));
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0; i < n; i++)
			p[i].input();
		printf("%.0f\n",solve(10000,10000));
	}
	return 0;
}
