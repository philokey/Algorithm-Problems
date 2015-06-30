#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Point{
	double x,y;
	Point(){};
	Point (double a,double b):x(a), y(b){}
	Point operator *(double c) {return Point(x*c,y*c);}
	Point operator -(const Point a){return Point (x-a.x,y-a.y);}
	Point operator +(const Point a){return Point (x+a.x,y+a.y);}
	void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
//typedef Point Angle;
Vector get_vector(Point a,Point b)
{
	return Point(b.x-a.x,b.y-a.y);
}
double Cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double Lenth(Vector a)
{
	return sqrt(dot(a,a));
}
double Angle(Vector a,Vector b)
{
	return acos(dot(a,b)/Lenth(a)/Lenth(b));
}
Vector Rotate(Vector a,double rad)
{
	Vector c;
	c.x = a.x*cos(rad)-a.y*sin(rad);
	c.y = a.x*sin(rad)+a.y*cos(rad);
	return c;
}
Point Getinter(Point a,Vector aa,Point b,Vector bb)
{
	Vector u = a-b;
	double t = Cross(bb,u)/Cross(aa,bb);
	return a+aa*t;
}
Point solve(Point a,Point b, Point c)
{
	Vector v1 = c-b,v2 = b-c;
	double rad1 = Angle(c-b,a-b);
	v1 = Rotate(v1,rad1/3.0);
	double rad2 = Angle(b-c,a-c);
	v2 = Rotate(v2,-rad2/3);
	return Getinter(b,v1,c,v2);
}
int main()
{
	//freopen("in.txt","r",stdin);
	int ca;
	Point a,b,c,d,e,f;
	scanf("%d",&ca);
	while(ca--)
	{
		a.input();b.input();c.input();
		d = solve(a,b,c);
		e = solve(b,c,a);
		f = solve(c,a,b);
		printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",d.x,d.y,e.x,e.y,f.x,f.y);
	}
	return 0;
}
