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
double sqr(double x){return x*x;}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
	Point operator *(double k)const{return Point(x*k,y*k);}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.8f %.8f\n",x,y);}
};
typedef Point Vector;
double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double length(Vector a)
{
	return sqrt(dot(a,a));
}
Vector normal(Vector a)
{
	double l = length(a);
	return Vector(-a.y/l,a.x/l);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	Point p[10];
	for(int i = 0; i < 3; i++)
		p[i].input();
	p[3] = Point((p[0].x+p[1].x+p[2].x)/3,(p[0].y+p[1].y+p[2].y)/3);
	double d = length(p[0]-p[3]);
	p[4] = Point(p[3].x-1,p[3].y-sqrt(3));
	p[5] = Point(p[3].x+1,p[3].y-sqrt(3));
	for(int i = 6; i < 9; i++)
		p[i] = Point(p[3].x*2-p[i-6].x,p[3].y*2-p[i-6].y);
	for(int i = 3; i < 9; i++)
		p[i].output();
	return 0;
}
