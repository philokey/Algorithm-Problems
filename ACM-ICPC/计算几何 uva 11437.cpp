#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const int maxn = 3005;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	else return x < 0? -1:1;
}
struct Point{
    double x,y;
    Point() {} ;
    Point (double a , double b) : x(a) , y(b) {}
    Point operator * (double c) {return Point (x * c , y * c );}
    Point operator / (double c) {return Point (x / c , y / c );}
	Point operator - (const Point a) {return Point (x - a.x , y - a.y );}
	Point operator + (const Point a) {return Point (x + a.x , y + a.y );}
	bool operator == (const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	bool operator <(const Point &a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
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
Point Getinter(Point a,Vector aa,Point b,Vector bb)//要保证两条直线有唯一交点
{
	Vector u = a-b;
	double t = Cross(bb,u)/Cross(aa,bb);
	return a+aa*t;
}
double Area2(Point a, Point b, Point c)//三角形面积的两倍
{
	return Cross(b-a,c-a);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int ca;
	Point a,b,c,d,e,f,r,p,q;
	scanf("%d",&ca);
	while(ca--)
	{
		a.input();b.input();c.input();
		d = b+(c-b)/3;
		e = c+(a-c)/3;
		f = a+(b-a)/3;
		r = Getinter(a,d-a,c,f-c);
		p = Getinter(a,d-a,b,e-b);
		q = Getinter(b,e-b,c,f-c);
		printf("%.0f\n",Area2(r,p,q)/2);
	}
	return 0;
}
