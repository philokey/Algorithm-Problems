#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
# define eps 1e -8
# define MAX_P 2000
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
const double INF = 1e50;
const int NUM = 140;
int n;

struct Point
{
	double x,y;
	Point() {} ;
    Point (double a , double b) : x(a) , y(b) {}
    Point operator +(const Point a)const {return Point(x+a.x,y+a.y);}
    Point operator -(const Point a)const {return Point(x-a.x,y-a.y);}
	Point operator *(double k)const {return Point(k*x,k*y);}
	Point operator /(double k)const {return Point(x/k,y/k);}
};
typedef Point Vector;
struct Circle
{
	double r ;
	Point o ;
};
struct Triangle
{
	Point t [3];
};
Point pt [MAX_P];
Circle c ;

double cross( Point a , Point b )
{
	return a.x * b.y - b.x * a.y ;
}
double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double length(Vector a)
{
	return sqrt(dot(a,a));
}

Point getinter(Point a,Vector aa,Point b,Vector bb)
{
	Vector u = a-b;
	double t = cross(bb,u)/cross(aa,bb);
	return a+aa*t;
}
Vector normal(Vector a)
{
	double l = length(a);
	return Vector(-a.y/l,a.x/l);
}
Circle tri_oc(Triangle tri)//三角形的外接圆
{
	Point p1,p2;
	Circle res;
	Vector v1,v2;
	p1 = (tri.t[0]+tri.t[1])/2;
	p2 = (tri.t[2]+tri.t[1])/2;
	v1 = normal(tri.t[0]-tri.t[1]);
	v2 = normal(tri.t[1]-tri.t[2]);
	res.o = getinter(p1,v1,p2,v2);
	res.r = length(res.o-tri.t[0]);
	return res;
}

Circle mincircle_triangle( int trinum , Triangle tri )
{
	Circle res ;
	if (trinum ==0) res.r = -1;
	else if (trinum ==1)
	{
		res.o = tri.t [0];
		res.r =0;
	}
	else if (trinum ==2)
	{
		res.o.x=(tri.t[0].x+tri.t[1].x)/2;
		res.o.y=(tri.t[0].y+tri.t[1].y)/2;
		res.r=length(tri.t[0]-tri.t[1])/2;
	}
	else if (trinum ==3) res=tri_oc(tri);
	return res ;
}
void mincircle_pointset (int m ,int trinum , Triangle tri)
{
	Point tmp ;
	c=mincircle_triangle(trinum,tri);
	if (trinum ==3) return ;
	for(int i =0; i < m ; i++)
		if(length(pt[i]-c.o)>c.r)
		{
			tri.t[trinum]=pt[i];
			mincircle_pointset(i,trinum+1,tri);
			tmp=pt[i];
			//小优化
			for(int j=i;j>=1;j--) pt[j]=pt[j-1];
			pt[0]=tmp;
		}
}
int main ()
{
	//freopen("in.txt","r",stdin);
	int n ,i ;
	Triangle tri ;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		scanf("%lf%lf",&pt[i].x,&pt[i].y);
		mincircle_pointset(n,0,tri);
		printf("%.2f %.2f %.2f\n",c.o.x,c.o.y,c.r);
	}
}
