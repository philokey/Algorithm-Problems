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
const int MAXN = 205;
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
	Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
	Point operator*(double k)const{return Point(x*k,y*k);}
	bool operator <(const Point &a)const
	{
		return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.x)<0);
	}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
};

typedef Point Vector;
struct Line{
	Point p;
	Vector v;
	double ang;
	Line(){}
	Line(Point a,Vector b):p(a),v(b)
	{
		ang = atan2(v.y,v.x);
	}
	bool operator <(const Line&l)const{
		return ang<l.ang;
	}
};
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
bool onleft(Line l,Point p)
{
	return cross(l.v,p-l.p)>=0;
}
Point getLineinter(Line a,Line b)
{
	Vector u = a.p-b.p;
	double t = cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
int HalfPlaneInter(Line* L, int n, Point* poly)
{
    sort(L, L+n);
    int first, last;
    Point *p = new Point[n];
    Line* q = new Line[n];
    q[first=last=0] = L[0];
    for(int i = 1; i < n; i++)
    {
        while(first < last && !onleft(L[i], p[last-1])) last--;
        while(first < last && !onleft(L[i], p[first])) first++;
        q[++last] = L[i];
        if(dcmp(cross(q[last].v, q[last-1].v)) == 0)
        {
            last--;
            if(onleft(q[last], L[i].p)) q[last] = L[i];
        }
        if(first < last) p[last-1] = getLineinter(q[last-1], q[last]);
    }
    while(first < last && !onleft(q[first], p[last-1])) last--;
    if(last - first <= 1)
	{
		poly[0] = p[0];
		return 0;
	}
    p[last] = getLineinter(q[last], q[first]);
    int m = 0;
    for(int i = first; i <= last; i++) poly[m++] = p[i];
    return m;
}
double area(Point *p,int n)
{
	double area = 0;
	for(int i = 1; i < n-1; i++)
		area+=cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
}
Vector normal(Vector a)
{
	double l = length(a);
	return Vector(-a.y/l,a.x/l);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m,r;
	Point p[MAXN],vn[MAXN],v[MAXN];
	Line l[MAXN];
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		for(int i = 0; i < n; i++)
			p[i].input();
		if(area(p,n)<0)
		{
			for(int i = 0; i < n; i++)
			{
				v[i] = p[i]-p[(i+1)%n];
				vn[i] = normal(v[i]);
			}
		}
		else
		{
			for(int i = 0; i < n; i++)
			{
				v[i] = p[(i+1)%n]-p[i];
				vn[i] = normal(v[i]);
			}
		}
		for(int i = 0; i < n; i++)
			l[i] = Line(p[i]+vn[i]*r,v[i]);
		m = HalfPlaneInter(l,n,p);
		if(m==0)
		{
			printf("%.6f %.6f %.6f %.6f\n",p[0].x,p[0].y,p[0].x,p[0].y);
			continue;
		}
		double len=-1;
		int a1,a2;
		for(int i = 0; i < m; i++)
			for(int j = i+1; j < m; j++)
				if(dcmp(length(p[i]-p[j])-len)>0)
					len = length(p[i]-p[j]), a1 = i,a2 = j;
		printf("%.6f %.6f %.6f %.6f\n",p[a1].x,p[a1].y,p[a2].x,p[a2].y);
	}
	return 0;
}
