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
const int MAXN = 1005;
const int INF = 1111111111;
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point a)const{return Point(x-a.x,y-a.y);}
	Point operator*(double k)const{return Point(x*k,y*k);}
	Point operator/(double k)const{return Point(x/k,y/k);}
	void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN];
struct Circle{
	Point o;
	double r;
}c;
struct Triangle{
	Point p[3];
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
Point getinter(Point a,Vector aa,Point b,Vector bb)
{
	Vector u = a-b;
	double t = cross(bb,u)/cross(aa,bb);
	return a+aa*t;
}
Circle tri_oc(Triangle tri)//求外接圆
{
	Point p1,p2;
	Circle res;
	Vector v1,v2;
	p1 = (tri.p[0]+tri.p[1])/2;
	p2 = (tri.p[2]+tri.p[1])/2;
	v1 = normal(tri.p[0]-tri.p[1]);
	v2 = normal(tri.p[1]-tri.p[2]);
	res.o = getinter(p1,v1,p2,v2);
	res.r = length(res.o-tri.p[0]);
	return res;
}
Circle minc_t(int trinum,Triangle tri)
{
	Circle ret;
	if(trinum==0) ret.r = -1;
	else if(trinum==1)
	{
		ret.o = tri.p[0];
		ret.r = 0;
	}
	else if(trinum==2)
	{
		ret.o.x=(tri.p[0].x+tri.p[1].x)/2;
		ret.o.y=(tri.p[0].y+tri.p[1].y)/2;
		ret.r=length(tri.p[0]-tri.p[1])/2;
	}
	else ret = tri_oc(tri);
	return ret;
}
void minc(int m,int trinum,Triangle tri)
{
	Point tmp;
	c = minc_t(trinum,tri);
	if(trinum==3) return;
	for(int i = 0; i < m; i++)
		if(length(p[i]-c.o)>c.r)
		{
			tri.p[trinum] = p[i];
			minc(i,trinum+1,tri);
			tmp = p[i];
			for(int j = i; j>=1; j--)
				p[j] = p[j-1];
			p[0] = tmp;
		}
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,a,b;
	Triangle tri;
	while(scanf("%d%d%d",&a,&b,&n)!=EOF)
	{
		for(int i = 0; i < n; i++)
			p[i].input();
		minc(n,0,tri);
		printf("(%.1f,%.1f).\n%.1f\n",c.o.x,c.o.y,c.r);
	}
	return 0;
}
