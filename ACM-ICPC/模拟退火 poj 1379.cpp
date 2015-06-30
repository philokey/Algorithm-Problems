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
}p[MAXN],may[MAXN];
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
	double val=INF;
	for(int i = 0; i < n; i++)
		val = min(val,dist(a,p[i]));
	return val;
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
void solve(double x,double y)
{
	may[0] = Point(0,0),may[0].val = judge(may[0]);
	may[1] = Point(0,y),may[1].val = judge(may[1]);
	may[2] = Point(x,0),may[2].val = judge(may[2]);
	may[3] = Point(x,y),may[3].val = judge(may[3]);
	for(int i = 4; i < NUM; i++)
		may[i] = get(may[0],may[3]);
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
				if(dcmp(may[i].val-tmp.val)<0)
					may[i] = tmp;
			}
		step*=0.9;
	}
	Point ans;
	ans.val=0;
	for(int i = 0; i < NUM; i++)
	{
		if(dcmp(ans.val-may[i].val)<0)
			ans = may[i];
	}
	printf("The safest point is (%.1f, %.1f).\n",ans.x,ans.y);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	double x,y;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%lf%lf%d",&x,&y,&n);
		for(int i = 0; i < n; i++)
			p[i].input();
		solve(x,y);
	}
	return 0;
}
