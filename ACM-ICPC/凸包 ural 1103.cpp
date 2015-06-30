#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 5005;
const int inf = 111111111;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return x<0? -1:1;
}
struct Point{
	double x,y;
	double ang;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
	Point operator *(double k)const{return Point(x*k,y*k);}
	bool operator ==(const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.0f %.0f\n",x,y);}
};
typedef Point Vector;
bool cmp1(const Point &a,const Point &b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
bool cmp2(const Point &a,const Point &b)
{
	return a.ang<b.ang;
}
double Cross(Vector a,Vector b)
{
	return a.x*b.y-b.x*a.y;
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
	sort(p,p+n,cmp1);
	n = unique(p,p+n)-p;
	int m = 0;
	for(int i = 0; i < n; i++)
	{
		while(m > 1&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])) <= 0) --m;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-2; i>=0; i--)
	{
		while(m > k && dcmp(Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) --m;
        ch[m++] = p[i];
	}
	if(m>1)--m;
	return m;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	Point p[maxn],ch[maxn],a,b,c;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		p[i].input();
	int m = ConvexHull(p,n,ch);
	a = ch[0], b = ch[1];
	for(int i = 0; i < n; i++)
	{
		if(p[i]==a||p[i]==b) p[i].ang = -inf;
		else p[i].ang = acos(Dot(a-p[i],b-p[i])/(Length(a-p[i])*Length(b-p[i])));
	}
	sort(p,p+n,cmp2);
	//for(int i = 0; i < n; i++)
		//p[i].output();
	a.output();
	b.output();

	p[n/2+1].output();
	return 0;
}




















