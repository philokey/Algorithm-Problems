#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
int dcmp(double x)
{
	if(fabs(x)<1e-8) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
	bool operator ==(const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	bool operator <(const Point &a)const
	{
		return x<a.x||(dcmp(x-a.x)==0&&y<a.y);
	}
	void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
double Cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double Dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double Length(Vector a)
{
	return sqrt(Dot(a,a));
}
int ConveHull(Point *p,int n,Point *ch)
{
	sort(p,p+n);
	n = unique(p,p+n)-p;
	int m = 0;
	for(int i = 0; i < n; i++)
	{
		while(m >1&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<0) --m;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-2; i >=0; i--)
	{
		while(m>k&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<0) --m;
		ch[m++] = p[i];
	}
	if(n>1) m--;
	return m;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int cas,n,m;
	double A,B,C,sx,sy;
	Point p[MAXN],ch[5*MAXN];
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas;ca++)
	{
		scanf("%d",&n);

		sx = sy = 0;
		for(int i = 0; i < n; i++)
		{
			p[i].input();
			sx += p[i].x;
			sy += p[i].y;
		}
		if(n<=2)
		{
			printf("Case #%d: 0.000\n",ca);
			continue;
		}
		m = ConveHull(p,n,ch);
		double ans = 1e30;
		for(int i = 0; i < m; i++)
		{
			Vector v = ch[(i+1)%m]-ch[i];
			A = v.y; B = -v.x;
			C = -ch[i].x*v.y+ch[i].y*v.x;
			ans = min(ans,fabs(A*sx+B*sy+C*n)/sqrt(A*A+B*B));
		}
		printf("Case #%d: %.3f\n",ca,ans/n);
	}
}
