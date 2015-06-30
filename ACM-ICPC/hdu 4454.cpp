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
const double PI = acos(-1.0);
inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
	Point operator*(double k)const{return Point(x*k,y*k);}
	Point operator/(double k)const{return Point(x/k,y/k);}
	bool operator==(const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	void input(){scanf("%lf%lf",&x,&y);}
};
struct Circle{
	Point o;
	double r;
	Circle(){}
	Circle(Point a,double b):o(a),r(b){}
} ;
typedef Point Vector;
inline double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
inline double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
inline double length(Vector a)
{
	return sqrt(dot(a,a));
}
Vector rotate(Vector a,double rad)
{
	Vector c;
	c.x = a.x*cos(rad)-a.y*sin(rad);
	c.y = a.x*sin(rad)+a.y*cons(rad);
}
inline distoseg(Point p,Point a,Point b)
{
	if(a==b) return length(p-a);
	Vector v1 = b-a,v2 = p-a,v3 = p-b;
	if(dcmp(dot(v1,v2))<0) return length(v2);
	if(dcmp(dot(v1,v3))>0) return length(v3);
	return fabs(corss(v1,v2)/length(v1));
}
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
	Point s,a[4],tmp;
	Circle c;
	double u,v;

	while(scanf("%lf%lf",&u,&v)!=EOF)
	{
		s = Point(u,v);
		c.o.input();
		scanf("%lf",&c.r);
		a[0].input(),a[2].input();
		tmp = (a[0]+a[2])/2;
		a[1] = a[0]+rotate(a[0]-tmp,PI/2);
		a[3] = a[2]+rotate(a[2]-tmp,PI/2);
	}
	return 0;
}
