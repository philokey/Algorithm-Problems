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
const double PI = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
	Point operator*(double k)const{return Point(k*x,k*y);}
	Point trunc(double d)
    {
        double len = sqrt(x*x+y*y);
        return Point(x*d/len,y*d/len);
    }
	bool operator <(const Point&a)const
	{
		return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.3f %.3f\n",x,y);}
}light;
pair<double,double> p[2*MAXN];
typedef Point Vector;
struct Circle{
	Point o;
	double r;
}c;
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
Point getinter(Point a,Vector aa,Point b,Vector bb)
{
	Vector u = a-b;
	double t = cross(bb,u)/cross(aa,bb);
	return a+aa*t;
}
Vector rotate(Vector a,double rad)
{
	Vector c;
	c.x = a.x*cos(rad)-a.y*sin(rad);
	c.y = a.x*sin(rad)+a.y*cos(rad);
	return c;
}

void get_pc(Circle c, Point p,Point &s1,Point &s2)
{
    Vector u = p-c.o;
	Vector v = u.trunc(c.r);
    double dist = length(u);
    double ang = PI/2-asin(c.r/dist);
    s1 = rotate(v,-ang)+c.o;
    s2 = rotate(v,ang)+c.o;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m;
	Point s1,s2;
	while(scanf("%d",&n)!=EOF)
	{
		m = 0;
		light.input();
		for(int i = 0; i < n; i++)
		{
			c.o.input();
			scanf("%lf",&c.r);
			get_pc(c,light,s1,s2);
			//s1.output();
			//s2.output();
			p[m].FI = getinter(Point(0,0),Vector(1,0),s1,light-s1).x;
			p[m].SE = getinter(Point(0,0),Vector(1,0),s2,light-s2).x;
			if(dcmp(p[m].SE-p[m].FI)<0) swap(p[m].FI,p[m].SE);

			m++;
		}
		sort(p,p+m);
		pair<double,double> ans[MAXN];
		int an=0;
		for(int i = 0; i < m;)
		{
			double fi = p[i].FI,se = p[i].SE;
			++i;
			while(i<m&&p[i].FI<se) se = max(se,p[i].SE),i++;
			ans[an++] = make_pair(fi,se);
		}
		for(int i = 0; i < an; i++)
			printf("%.2f %.2f\n",ans[i].FI,ans[i].SE);
		printf("\n");
	}
	return 0;
}
