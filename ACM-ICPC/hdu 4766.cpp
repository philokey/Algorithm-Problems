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
const double INF = 1e40;
const double PI = acos(-1.0);
inline int dcmp(double a)
{
	if(fabs(a)<EPS) return 0;
	return a<0?-1:1;
}
inline double sqr(double x){return x*x;}
double r;
int n;
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point&a)const {return Point(x+a.x,y+a.y);}
	Point operator-(const Point&a)const {return Point(x-a.x,y-a.y);}
	Point operator * (double c) {return Point (x * c , y * c );}
    Point operator / (double c) {return Point (x / c , y / c );}
	Point trunc(double d)
	{
		double len = sqrt(x*x+y*y);
		return Point(x*d/len,y*d/len);
	}
	bool operator <(const Point&a)const
	{
		return dcmp(x-a.x)<0;
	}
	bool operator==(const Point&a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN];
typedef Point Vector;
struct Circle{
	Point o;
	double r;
	Circle(){}
	Circle(Point a,double b):o(a),r(b){}
};

inline double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
inline double length(Vector a)
{
	return sqrt(dot(a,a));
}
inline double dist(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline Vector rotate(Vector a,double rad)
{
	Vector c;
	c.x = a.x*cos(rad)-a.y*sin(rad);
	c.y = a.x*sin(rad)+a.y*cos(rad);
	return c;
}
int inter_c_and(Circle c1,Circle c2,Point &p1,Point &p2)
{
	Vector v = c2.o-c1.o;
	double len = length(v);
	if(dcmp(len-c1.r-c2.r)>0) return 0;

	double s = (sqr(c1.r)-sqr(c2.r)+sqr(len))/len/2;
	double h = sqrt(sqr(c1.r)-sqr(s));
	Point p0 = c1.o+v.trunc(s);
	Point tmp = rotate(v,PI/2).trunc(h);
	p1 = p0+tmp;
	p2 = p0-tmp;
	return 1;
}
inline bool check(Point a)
{
	for(int i = 1; i <= n; i++)
		if(length(p[i]-a)>r&&abs(length(p[i]-a)-r)>EPS) return 0;
		//if(dcmp(dist(a,p[i])-r)>0) return 0;
	return 1;
}

Point s[MAXN*MAXN];
int sn;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	double x,y,d;
	bool flag;
	Point a,b;
	Circle c1,c2;
	while(scanf("%lf%lf%lf",&x,&y,&r)!=EOF)
	{
		flag = 1;
		p[0] = Point(x,y);
		scanf("%d",&n);
		for(int i = 1; i <= n;i++)
		{
			p[i].input();
			if(dcmp(length(p[i]-p[0])-r)>0) flag = 0;
		}
		if(flag)
		{
			printf("0.00\n");
			continue;
		}
		flag = 1;
		sn = 0;
		for(int i = 1; i <= n&&flag; i++)
			for(int j = i+1; j <= n&&flag; j++)
			{
				c1 = Circle(p[i],r);
				c2 = Circle(p[j],r);
				if(inter_c_and(c1,c2,a,b))
				{
					s[sn++] = a;
					s[sn++] = b;
				}
				else flag = 0;
			}
		double ans = INF;
		if(!flag)
		{
			printf("X\n");
			continue;
		}

		for(int i = 1; i <= n; i++)
		{
			Vector v = p[0]-p[i];
			double len = length(v);
			Point tmp = p[i]+v/len*r;
			d =  dist(tmp,p[0]);
			if(dcmp(ans-d)>0&&check(tmp))
				ans = d;
		}
		for(int i = 0; i < sn; i++)
		{
			d = dist(s[i],p[0]);
			if(dcmp(d-ans)<0&&check(s[i]))
				ans = d;
		}
		printf("%.2f\n",ans);
	}

	return 0;
}
