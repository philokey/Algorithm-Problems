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
const double PI = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y,pa;
	int cnt;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point(double a,double b,double c,int d):x(a),y(b),pa(c),cnt(d){}
	Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
	bool operator <(const Point &a)const
	{
		return pa<a.pa;
	}
	void input(){scanf("%lf%lf",&x,&y);}
};
struct Circle{
	Point c;
	double r;
    Point point(double a)
    {
    	return Point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};
typedef Point Vector;
inline double Cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
inline double Dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
inline double Length(Vector a)
{
	return sqrt(Dot(a,a));
}
double Angle(Vector v)
{
	return atan2(v.y,v.x);
}
bool Getccinte(Circle c1,Circle c2,Point &a,Point &b)
{
	double d = Length(c1.c-c2.c);
	if(dcmp(d)==0||dcmp(c1.r+c2.r-d)<0||dcmp(fabs(c1.r-c2.r)-d)>0)
		return 0;
	double ang = Angle(c2.c-c1.c);
	double da = acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
	a = c1.point(ang-da), b = c1.point(ang+da);
	return 1;
}
double s[MAXN];
Point e[MAXN<<2];
int cover[MAXN];
double Cirun(int n,Circle c[],double s[])
{
	Point a,b,p;
	bool flag=0;
	for(int i = 0; i <= n+1; i++) s[i] = 0,cover[i] = 0;
	for(int i =0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			double d = c[i].r-c[j].r;
			if(i!=j&&dcmp(d)>0&&dcmp(Length(c[i].c-c[j].c)-d)<=0)
				cover[j]++;
			else if(i<j&&dcmp(d)==0&&dcmp(Length(c[i].c-c[j].c)-d)==0)
				cover[j]++;
		}
	for(int i = 0; i < n; i++)
	{
		int en = 0;
		e[en++] = Point(c[i].c.x-c[i].r,c[i].c.y,-PI,1);
		e[en++] = Point(c[i].c.x-c[i].r,c[i].c.y,PI,-1);
		for(int j = 0; j < n; j++)
		{
			if(i==j) continue;
			if(Getccinte(c[i],c[j],a,b))
			{
				e[en++] = Point(a.x,a.y,atan2(a.y-c[i].c.y,a.x-c[i].c.x),1);
				e[en++] = Point(b.x,b.y,atan2(b.y-c[i].c.y,b.x-c[i].c.x),-1);
				if(dcmp(e[en-2].pa-e[en-1].pa)>0)
				{
					e[0].cnt++;
					e[1].cnt--;
				}
			}
		}
		sort(e,e+en);
		int cnt = e[0].cnt;
		for(int j = 1; j < en; j++)
		{
			double pad = e[j].pa-e[j-1].pa;
            s[cover[i]+cnt] += (Cross(e[j-1], e[j])+c[i].r*c[i].r*(pad-sin(pad)))/2;
            cnt += e[j].cnt;
		}
	}
	return s[1];

}

int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int nn,n;
	Circle c[MAXN];
	while(scanf("%d",&nn)!=EOF)
	{
		n = 0;
		for(int i = 0; i < nn; i++)
		{
			c[n].c.input();
			scanf("%lf",&c[n].r);
			if(dcmp(c[n].r)>0) n++;
		}
		printf("%.3f\n",Cirun(n,c,s)+EPS);
	}
	return 0;
}

