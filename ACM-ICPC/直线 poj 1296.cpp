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
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	Point a,b,c,d,e;
	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--)
	{
		a.input(),b.input(),c.input(),d.input();
		if(dcmp(cross(a-b,c-d))==0)
		{
			if(dcmp(cross(a-c,a-d))==0) printf("LINE\n");
			else printf("NONE\n");
		}
		else
		{
			e = getinter(a,b-a,c,d-c);
			printf("POINT %.2f %.2f\n",e.x+EPS,e.y+EPS);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
