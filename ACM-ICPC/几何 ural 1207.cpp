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
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	int id;
	bool operator<(Point &a)const
	{
		return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
	}
	void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN],o;
bool cmp(Point a,Point b)
{
	double x = atan2(a.y-o.y,a.x-o.x);
	double y = atan2(b.y-o.y,b.x-o.x);
	return x<y;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	p[0].input();
	p[0].id = 1;
	for(int i = 1; i < n; i++)
	{
		p[i].input();
		p[i].id = i+1;
		if(p[i]<p[0]) swap(p[0],p[i]);
	}
	o = p[0];
	sort(p+1,p+n,cmp);
	printf("%d %d\n",p[0].id,p[n/2].id);
	return 0;
}
