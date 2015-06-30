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
const double PI = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	else return x < 0? -1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point&a)const{Point(x+a.x,y+a.y);}
	Point operator-(const Point&a)const{Point(x-a.x,y-a.y);}
	void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
double Cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double Dot(Vector a, Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double Length(Vector a)
{
	return sqrt(Dot(a,a));
}

Vector Rotate(Vector a,double rad)
{
	Vector c;
	c.x = a.x*cos(rad)-a.y*sin(rad);
	c.y = a.x*sin(rad)+a.y*cos(rad);
	return c;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	Point p,a,b;
	scanf("%d",&n);
	while(n--)
	{
		p.input();
		a = Rotate(p,2*PI/3);
		b = Rotate(p,-2*PI/3);
		if(dcmp(a.y-b.y)>0||(dcmp(a.y-b.y)==0&&dcmp(a.x-b.x)>0)) swap(a,b);
		printf("%.3f %.3f %.3f %.3f\n",a.x+EPS,a.y+EPS,b.x+EPS,b.y+EPS);
	}
	return 0;
}
