#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const int maxn = 505;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	else return x < 0? -1:1;
}
struct Point{
    double x,y;
    Point() {} ;
    Point (double a , double b) : x(a) , y(b) {}
    Point operator * (double c) {return Point (x * c , y * c );}
    Point operator / (double c) {return Point (x / c , y / c );}
	Point operator - (const Point a) {return Point (x - a.x , y - a.y );}
	Point operator + (const Point a) {return Point (x + a.x , y + a.y );}
	bool operator == (const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	bool operator <(const Point &a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){cout<<x<<" "<<y<<endl;}
};
typedef Point Vector;
double Cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double Dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double Length(Vector a)
{
	return sqrt(Dot(a,a));
}
Point Getinter(Point a,Vector aa,Point b,Vector bb)//要保证两条直线有唯一交点
{
	Vector u = a-b;
	double t = Cross(bb,u)/Cross(aa,bb);
	return a+aa*t;
}
bool Isinter(Point s1, Point e1, Point s2, Point e2){
    if( min(s1.x, e1.x) <= max(s2.x, e2.x) &&
        min(s1.y, e1.y) <= max(s2.y, e2.y) &&
        min(s2.x, e2.x) <= max(s1.x, e1.x) &&
        min(s2.y, e2.y) <= max(s1.y, e1.y) &&
        dcmp(Cross(s2-s1,e2-s1))*dcmp(Cross(s2-e1,e2-e1))<=0&&
        dcmp(Cross(s1-s2,e1-s2))*dcmp(Cross(s1-e2,e1-e2))<=0)
        return true;
    return false;
}
double Area2(Point a, Point b, Point c)//三角形面积的两倍
{
	return Cross(b-a,c-a);
}
int main()
{
	//freopen("in.txt","r",stdin);
	Point a,b,c,d,p,e,f;
	int ca,cnt;
	bool flag;
	scanf("%d",&ca);
	while(ca--)
	{
		flag = 1;
		cnt = 0;
		a.input();b.input();c.input();d.input();
		if(Cross(b-a,d-c)==0||!Isinter(a,b,c,d))
		{
			printf("0.00\n");
			continue;
		}
		p = Getinter(a,b-a,c,d-c);
		if(a.y>p.y) e = a,cnt++;
		if(b.y>p.y) e = b,cnt++;
		if(c.y>p.y) f = c,cnt++;
		if(d.y>p.y) f = d,cnt++;
		if(cnt!=2) flag = 0;
		//cout<<cnt<<endl;
		if(flag&&((e.y>f.y&&e.x>=f.x)||(e.y<f.y&&e.x<=f.x))) flag = 0;
		if(!flag)
		{
			printf("0.00\n");
			continue;
		}
		Point tmp(e.x,min(e.y,f.y));

		double ans = Area2(p,e,f)/2;
		printf("%.2f\n",fabs(ans));
	}
	return 0;
}








