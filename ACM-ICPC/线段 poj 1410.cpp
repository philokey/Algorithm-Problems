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
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
	Point operator *(double k)const{return Point(x*k,y*k);}
	void input(){scanf("%lf%lf",&x,&y);}
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
Point getinter(Point a,Vector aa,Point b,Vector bb)
{
	Vector u = a-b;
	double t = cross(bb,u)/cross(aa,bb);
	return a+aa*t;
}
bool isinter(Point s1, Point e1, Point s2, Point e2)
{
    if( min(s1.x, e1.x) <= max(s2.x, e2.x) &&
        min(s1.y, e1.y) <= max(s2.y, e2.y) &&
        min(s2.x, e2.x) <= max(s1.x, e1.x) &&
        min(s2.y, e2.y) <= max(s1.y, e1.y) &&
        dcmp(cross(s2-s1,e2-s1))*dcmp(cross(s2-e1,e2-e1))<=0&&
        dcmp(cross(s1-s2,e1-s2))*dcmp(cross(s1-e2,e1-e2))<=0)
        return true;
    return false;
}
int main()
{
//	freopen("/home/qitaishui/code/in.txt","r",stdin);
//	freopen("/home/qitaishui/code/out1.txt","w",stdout);
	int n;
	Point s,t,p[4];
	scanf("%d",&n);
	while(n--)
	{
		s.input(),t.input();
		p[0].input(),p[2].input();
		if(dcmp(p[0].y-p[2].y)<0) swap(p[0],p[2]);
		p[1] = Point(p[2].x,p[0].y);
		p[3] = Point(p[0].x,p[2].y);
		bool flag=1;
		if(dcmp(min(s.x,t.x)-min(p[0].x,p[2].x))>=0&&dcmp(max(s.x,t.x)-max(p[0].x,p[2].x))<=0&&
		   dcmp(min(s.y,t.y)-min(p[0].y,p[2].y))>=0&&dcmp(max(s.y,t.y)-max(p[0].y,p[2].y))<=0) flag = 0;
		for(int i = 0; i <4&&flag; i++)
		{
			if(isinter(s,t,p[i],p[(i+1)%4])) flag = 0;
		}
		if(flag) printf("F\n");
		else printf("T\n");
	}
	return 0;
}
