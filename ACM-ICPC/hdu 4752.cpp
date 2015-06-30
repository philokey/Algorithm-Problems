#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-10;
const int MAXN = 100005;
const int INF = 1111111111;
inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
	bool operator<(const Point &a)const
	{
		return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
	}
	bool operator==(const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2lf %.2lf\n",x,y);}
}p[MAXN],ch[MAXN];
typedef Point Vector;
inline double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
inline double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}

int n,m;
double a,b,c,k,d,l,r;
inline bool judge(double x)
{
	return dcmp(x-l)>=0&&dcmp(x-r)<=0;
}
inline bool onseg(Point p, Point a, Point b)
{
	return dcmp(cross(a-p,b-p))==0&&dcmp(dot(a-p,b-p))<0;
}
int getinter(double x1,double y1,double x2,double y2,Point &p1,Point &p2)
{
	if(dcmp(x1-x2)==0)
	{
		p1 = Point(x1,a*x1*x1+b*x1+c);
		if(judge(x1)&&onseg(p1,Point(x1,y1),Point(x2,y2))) return 1;
		else return 0;
	}
	k = (y2-y1)/(x2-x1);
	d = y1-k*x1;
	double delta = (b-k)*(b-k)-4*a*(c-d),x,y;
	if(dcmp(delta)<=0) return 0;
	int cnt = 0;
	x = (k-b+sqrt(delta))/(2*a);
	if(judge(x))
	{
		y = k*x+d;
		p1 = Point(x,y);
		if(onseg(p1,Point(x1,y1),Point(x2,y2)))
			cnt++;
	}
	x = (k-b-sqrt(delta))/(2*a);
	if(judge(x))
	{
		y = k*x+d;
		p2 = Point(x,y);
		if(onseg(p2,Point(x1,y1),Point(x2,y2)))
		{
			if(cnt==0) p1 = p2;
			cnt++;
		}
	}
	return cnt;
}
double f(double x)
{
	return sqrt((2*a*x+b)*(2*a*x+b)+1);
}
double simpson(double l,double r)
{
    return (f(l)+f(r)+4*f((l+r)/2))/6*(r-l);
}
double solve(double l,double r)
{
    double ans = simpson(l,r),m = (l+r)/2;
    if(fabs(ans-simpson(l,m)-simpson(m,r))<EPS)
        return ans;
    return solve(l,m)+solve(m,r);
}
int ispinpoly(Point p, Point *poly, int n)
{
    int wn = 0;
    for(int i = 0; i < n; i++)
    {
        Point p1 = poly[i], p2 = poly[i+1];
        if(onseg(p, p1, p2)) return 1;
        int k = dcmp(cross(p2-p1, p-p1));
        int d1 = dcmp(p1.y - p.y);
        int d2 = dcmp(p2.y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) wn++;
        if(k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if(wn != 0) return 1;
    return 0;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	Point p1,p2;
	double ans;
	while(scanf("%d%lf%lf%lf%lf%lf",&n,&a,&b,&c,&l,&r)!=EOF)
	{
		for(int i = 0; i < n; i++) ch[i].input();
		ch[n] = ch[0];
		m = 0;
		for(int i = 0; i<n; i++)
		{
			int tmp = getinter(ch[i].x,ch[i].y,ch[i+1].x,ch[i+1].y,p1,p2);
			if(tmp==2)
			{
				p[m++] = p1;
				p[m++] = p2;
			}
			if(tmp==1) p[m++] = p1;
		}
		if(ispinpoly(Point(l,a*l*l+b*l+c),ch,n))
			p[m++] = Point(l,a*l*l+b*l+c);
		if(ispinpoly(Point(r,a*r*r+b*r+c),ch,n))
			p[m++] = Point(r,a*r*r+b*r+c);
		sort(p,p+m);
		m = unique(p,p+m)-p;
		//for(int i = 0; i < m; i++)
			//p[i].output();
		ans = 0;
		for(int i = 0; i < m; i+=2)
		{
			ans+=solve(p[i].x,p[i+1].x);
		}


		printf("%.2lf\n",ans+EPS);
	}
	return 0;
}
