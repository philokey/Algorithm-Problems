#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return x<0? -1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
	Point operator *(double c)const{return Point(x*c,y*c);}
	bool operator <(const Point &a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2f %.2f\n",x,y);}
};
typedef Point Vector;
double Dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double Length(Vector a)
{
	return sqrt(Dot(a,a));
}
int main()
{
	//freopen("in.txt","r",stdin);
	Point p[105];
	int n;
	double m;
	scanf("%d%lf",&n,&m);
	for(int i = 0;i < n; i++)
		p[i].input();
	p[n] = p[0];
	double ans = 2*pi*m;
	for(int i = 0; i < n; i++)
		ans+=Length(p[i+1]-p[i]);
	printf("%.2f\n",ans);
	return 0;
}
