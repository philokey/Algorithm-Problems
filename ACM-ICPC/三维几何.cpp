#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-5;
const int MAXN = 10005;
const int INF = 1111111111;
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
	Point3 operator*(double k)const
	{
		return Point3(x*k,y*k,z*k);
	}
	void input(){scanf("%lf%lf%lf",&x,&y,&z);}
	void output(){printf("%lf %lf% lf\n",x,y,z);}
};
typedef Point3 Vector3;
Vector3 cross(Vector3 a,Vector3 b)
{
	return Vector3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
double dot(Vector3 a,Vector3 b)
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
double length(Vector3 a)
{
	return sqrt(dot(a,a));
}
double area2(Point3 a,Point3 b,Point3 c)
{
	return length(cross(b-a,c-a));
}
bool pointri(Point3 p,Point3 p0,Point3 p1,Point3 p2)
{
	double a1,a2,a3,a;
	a1 = area2(p,p0,p1);
	a2 = area2(p,p1,p2);
	a3 = area2(p,p2,p0);
	a = area2(p0,p1,p2);
	return dcmp(a1+a2+a3-a)==0;
}
bool triseginter(Point3 p0,Point3 p1,Point3 p2,Point3 a,Point3 b,Point3 &p)
{
	Vector3 n = cross(p1-p0,p2-p0);
	if(dcmp(dot(n,b-a))==0) return 0;
	else
	{
		double t = dot(n,p0-a)/dot(n,b-a);
		if(dcmp(t)<0||dcmp(t-1)>0) return 0;
		p = a+(b-a)*t;
		bool flag = pointri(p,p0,p1,p2);
		return flag;
	}
}
int main()
{
	//freopen("/home/qitaishui/下载/GCPC 2013/testdata/K/random.in","r",stdin);
	//freopen("/home/qitaishui/下载/GCPC 2013/testdata/K/out","w",stdout);
	int cas;
	Point3 a[5],b[5],p;
	scanf("%d",&cas);
	while(cas--)
	{
		for(int i = 0; i < 3; i++) a[i].input();
		for(int i = 0; i < 3; i++) b[i].input();
		int cnt=0;
		for(int i = 0; i < 3; i++)
			cnt+=triseginter(a[0],a[1],a[2],b[i],b[(i+1)%3],p);
		if(cnt!=1) printf("NO\n");
		else  printf("YES\n");
	}
	return 0;
}
