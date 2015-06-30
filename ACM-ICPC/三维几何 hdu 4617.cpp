#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 505;
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0? -1:1;
}
struct Point3{
	double x,y,z;
	Point3(){}
	Point3(double a,double b,double c):x(a),y(b),z(c){}
	Point3 operator+(const Point3 &a)const
	{
		return Point3(x+a.x,y+a.y,z+a.z);
	}
	Point3 operator-(const Point3 &a)const
	{
		return Point3(x-a.x,y-a.y,z-a.z);
	}
	Point3 operator*(double c)const
	{
		return Point3(x*c,y*c,z*c);
	}
	void input(){scanf("%lf%lf%lf",&x,&y,&z);}
	void output(){printf("%lf %lf %lf",x,y,z);}
};
typedef Point3 Vector3;
struct Line{
	Point3 a,b;
	double r;
};
Vector3 Cross(Vector3 a,Vector3 b)
{
	return Vector3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
double Dot(Vector3 a,Vector3 b)
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
double Length(Vector3 a)
{
	return sqrt(Dot(a,a));
}
double Distoplane(Point3 p, Point3 p0, Vector3 n)
{
	return fabs(Dot(p-p0,n)/Length(n));
}
double Distoline(Point3 p, Point3 a, Point3 b)
{
	Vector3 v1 = b-a,v2 = p-a;
	return Length(Cross(v1,v2))/Length(v1);
}
double Dislinetoline(Point3 a, Point3 b, Point3 c, Point3 d)
{
	Vector3 n = Cross(a-b,c-d);
 	if(dcmp(Length(n))==0)
		return Distoline(b,c,d);
	else
		return Distoplane(a,c,n);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,n;
	Line l[35];
	Point3 a,b,c;
	Vector3 v;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			a.input(),b.input(),c.input();
			l[i].r = Length(a-b);
			l[i].a = a;
			v = Cross(b-a,c-a);
			l[i].b = a+v;
		}
		bool flag = 1;
		double ans = 1e300,tmp;
		for(int i = 0; i < n&&flag; i++)
			for(int j = i+1; j < n&&flag; j++)
			{
				tmp = Dislinetoline(l[i].a,l[i].b,l[j].a,l[j].b);
				if(dcmp(tmp-l[i].r-l[j].r)<=0) flag = 0;
				else ans = min(ans,tmp-l[i].r-l[j].r);
			}
		if(!flag) printf("Lucky\n");
		else printf("%.2f\n",ans);
	}
	return 0;
}
