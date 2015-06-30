#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 1010
const double EPS = 1e-7;
const double INF = 1e40;
const double PI = acos(-1.0);
int x[MAXN],y[MAXN];
int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0? -1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
    Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
    Point operator /(double a)const{return Point(x/a,y/a);}
    Point operator *(double a)const{return Point(x*a,y*a);}
    double operator ==(const Point &a)const
    {
        return (dcmp(a.x-x)==0)&&(dcmp(y-a.y)==0);
    }
    void input(){scanf("%lf%lf",&x,&y);}
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
Point Getinter(Point a,Vector aa,Point b,Vector bb)
{
    Vector u = a - b;
    double t = Cross(bb,u)/Cross(aa,bb);
    return a+aa*t;
}
Vector Rotate(Vector a,double rad)
{
    Vector c;
    c.x = a.x*cos(rad)-a.y*sin(rad);
    c.y = a.x*sin(rad)+a.y*cos(rad);
    return c;
}
double Dtline(Point p,Point a,Point b)
{
    Vector v1 = b-a,v2 = p-a;
    return fabs(Cross(v1,v2)/Length(v1));
}
int n,m;
Point city[MAXN],base[MAXN];
int solve(int a,int b)
{
    int now,ret = -1,tn;
    double d = INF,len,l;
    Point mid,p,tmp,pp;
    Vector zc;
    len = Length(city[a]-city[b]);
    for(int i = 1; i <= m; i++)
    {
        if(dcmp(d-Length(base[i]-city[a]))>0)
            d = Length(base[i]-city[a]), now = i;
        else if(dcmp(d-Length(base[i]-city[a]))==0&&
                dcmp(Length(base[i]-city[b])-Length(base[now]-city[b]))<0)
                now = i;
    }
    l = 0;
    p = city[a];

    while(len-l>EPS)
    {
        d = INF;
        ++ret;
        for(int i = 1; i <= m; i++)
		{
            if(i==now) continue;

            mid = (base[i]+base[now])/2;
            zc = Rotate(base[i]-base[now],PI/2);

            tmp = Getinter(p,city[b]-city[a],mid,zc);
            if(dcmp(Length(tmp-p)+Length(tmp-city[b])-Length(p-city[b]))==0&&!(tmp==p))
			{
                if(dcmp(d-Length(tmp-p))>0) d = Length(tmp-p),tn = i,pp=tmp;
                else if(dcmp(d-Length(tmp-p))==0&&
                         dcmp(Dtline(base[i],city[a],city[b])-Dtline(base[now],city[a],city[b]))>0)
                    tn = i,pp = tmp;
            }

        }
        now = tn;
        l = Length(p-city[a])+d;
        p = pp;

    }
    return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int a,b;

    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;++i)
            city[i].input();
        for(int i=1;i<=m;++i)
            base[i].input();
        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",solve(a,b));
        }
    }
    return 0;
}
