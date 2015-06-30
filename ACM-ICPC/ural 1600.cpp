//三分加二分，注意精度
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-5;
const int maxn = 505;
const int inf = 11111111;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y,z;
	Point(){}
	Point(double a,double b,double c):x(a),y(b),z(c){}
	Point operator+(const Point&a)const
	{
		return Point(x+a.x,y+a.y,z+a.z);
	}
	Point operator-(const Point&a)const
	{
		return Point(x-a.x,y-a.y,z-a.z);
	}
	Point operator*(double k)const
	{
		return Point(x*k,y*k,z*k);
	}
	void input()
	{
		scanf("%lf%lf%lf",&x,&y,&z);
	}
	void output()
	{
		printf("%.2f %.2f %.2f\n",x,y,z);
	}
};
typedef Point Vector;
Point p[maxn];
Vector v[maxn];
double d;
int n;
double dist(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
double three(Point a,Vector va,Point b, Vector vb)
{
	double l = 0, r = inf,m,mm,d1,d2;
	while(r - l > eps)
	{
		m = (l+r)/2;
		mm = (m+r)/2;
		d1 = dist(a+va*m,b+vb*m);
		d2 = dist(a+va*mm,b+vb*mm);
		if(d1 < d2) r = mm-eps;
		else l = m+eps;
	}
	return l;
}
double bin(Point a,Vector va,Point b, Vector vb,double r)
{
	double l = 0,m;
	if(dcmp(dist(a+va*r,b+vb*r)-d)>0) return -1;
	r+=eps;
	while(r - l > eps)
	{
		m = (l+r)/2;
		if(dcmp(dist(a+va*m,b+vb*m)-d)<0) r = m-eps;
		else l = m+eps;
	}
	return l;
}
int main()
{
	//freopen("in.txt","r",stdin);
	double l,ans,tmp;
	int a,b;
	scanf("%d%lf",&n,&d);
	for(int i = 0; i < n; i++)
	{
		p[i].input();
		v[i].input();
	}

	ans = inf;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
		{
			l = three(p[i],v[i],p[j],v[j]);
			tmp = bin(p[i],v[i],p[j],v[j],l);
			if(tmp > 0&&tmp<ans)
			{
				ans = tmp;
				a = i+1,b = j+1;
			}
		}
	if(dcmp(ans-inf)==0) printf("OK\n");
	else printf("ALARM!\n%.5f %d %d\n",ans,a,b);
	return 0;
}
