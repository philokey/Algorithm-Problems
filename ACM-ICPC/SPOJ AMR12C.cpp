#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int MAXN = 105;
const double EPS = 1e-8;
const double INF = 1e30;
const double PI = acos(-1.0);
int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    double pa;
    int cnt;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point(double a,double b,double c,int d):x(a),y(b),pa(c),cnt(d){}
    Point operator +(Point a)const{return Point(x+a.x,y+a.y);}
    Point operator -(Point a)const{return Point(x-a.x,y-a.y);}
    bool operator <(const Point &a)const
    {
        return pa<a.pa;
    }
    void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
struct Circle{
    Point c;
    double r;
    bool flag;
    Point point(double x)
    {
        return Point(c.x+cos(x)*r,c.y+sin(x)*r);
    }
};
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
double Angle(Vector v)
{
    return atan2(v.y,v.x);
}
Point p[MAXN],e[MAXN];
int cover[MAXN];
double s[MAXN];
bool Getccinte(Circle c1,Circle c2,Point &a,Point &b)
{
    double d = Length(c1.c-c2.c);
    if(dcmp(d)==0||dcmp(c1.r+c2.r-d)<0||dcmp(fabs(c1.r-c2.r)-d)>0)
        return 0;
    double ang = Angle(c2.c-c1.c);
    double da = acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    a = c1.point(ang-da),b = c1.point(ang+da);
    return 1;
}
bool circle_union(int n,Circle c[],double s[])
{
    Point a,b;
    for(int i = 0; i <=n; i++) s[i] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            double d = c[i].r-c[j].r;
            if(i!=j&&dcmp(d)>0&&dcmp(Length(c[i].c-c[j].c)-d)<=0)
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
			if(dcmp(s[n])>0) return 1;
        }
    }
    //cout<<s[n-1]<<endl;
    return 0;
}
double v[MAXN];
int main()
{
    //freopen("F:\\acmcode\\in.txt","r",stdin);
    int cas,tmp;
    int n,cnt;
    bool flag;
    Circle c[MAXN];
    Point sol[MAXN*MAXN][2];
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            p[i].input();
            c[i].c = p[i];
            c[i].flag = 1;
            scanf("%lf",&v[i]);
        }
        double l,r,m,ans=0;
        l = 0,r = INF;
        while(r-l>EPS)
        {
            flag = 1;
            m = (l+r)/2;
            cnt = 0;
            for(int i = 0; i < n; i++)
                c[i].r = m*v[i];
			memset(cover,0,sizeof(cover));
            if(circle_union(n,c,s)) ans = m, r = m-EPS;
            else l = m+EPS;
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}



