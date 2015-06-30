#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 305;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return x < 0? -1:1;
}
struct Point{
	double x,y;
	Point(){};
	Point(double a,double b):x(a),y(b){}
	Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
	Point operator *(double c)const{return Point(x*c,y*c);}
	bool operator == (const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	bool operator <(const Point &a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2f %.2f\n",x,y);}
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
int ConvexHull(Point *p,int n,Point *ch)
{
	sort(p,p+n);
	n = unique(p,p+n)-p;
	int m = 0;
	for(int i = 0; i < n; i++)
	{
		while(m > 1&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)) --m;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-2; i>=0;i--)
	{
		while(m > k&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) --m;
		ch[m++] = p[i];
	}
	if(m>1) --m;
	return m;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,l;
	Point p[1005],ch[1005];
	scanf("%d%d",&n,&l);
	for(int i = 0; i < n; i++)
		p[i].input();
	n=ConvexHull(p,n,ch);
	double ans = 2*pi*l;
	ch[++n] = ch[0];

	for(int i = 0; i < n; i++)
		ans+=Length(ch[i+1]-ch[i]);
	printf("%.0f\n",ans);
	return 0;
}









