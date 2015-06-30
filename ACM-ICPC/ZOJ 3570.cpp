#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 100005;
inline int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator+(const Point a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point a)const{return Point(x-a.x,y-a.y);}
    Point operator*(double k)const{return Point(x*k,y*k);}
    bool operator <(const Point &a)const
    {
        return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
    }
    bool operator ==(const Point &a)const
    {
        return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
    }
    void input(){scanf("%lf%lf",&x,&y);}

}p[MAXN],ch[MAXN];
Point o,a[5],b[5],tmp;
typedef Point Vector;
inline double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}
inline double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}
int ConveHull(Point *p,int n,Point *ch)
{
    sort(p,p+n);
    n = unique(p,p+n)-p;
    int m =0;
    for(int i = 0;i<n; i++)
    {
        while(m>1&&dcmp(cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i>=0; i--)
    {
        while(m>k&&dcmp(cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<0) m--;
        ch[m++] = p[i];
    }
    if(n>1) m--;
    cout<<m<<endl;
    return m;
}
inline double area(Point a,Point b,Point c)
{
    return 0.5*fabs(cross(a-c,b-c));
}
inline bool check(Point a,Point b,Point c,Point p)
{
    double s = area(a,b,c);
    double st = area(p,a,b)+area(p,b,c)+area(p,a,c);
    return dcmp(s-st)==0;
}
double getare(Point *p,int n)
{
    double ret=0;
    for(int i = 1; i < n; i++)
        ret+=area(p[0],p[i],p[i+1]);
    return ret;
}
double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool isinter(Point s1,Point e1,Point s2,Point e2)
{
    if(dcmp(min(s1.x,e1.x)-max(s2.x,e2.x))<=0&&
       dcmp(min(s1.y,e1.y)-max(s2.y,e2.y))<=0&&
       dcmp(min(s2.x,e2.x)-max(s1.x,e1.x))<=0&&
       dcmp(min(s2.y,e2.y)-max(s1.y,e1.y))<=0&&
       dcmp(cross(s2-s1,e2-s1))*dcmp(cross(s2-e1,e2-e1))<=0&&
       dcmp(cross(s1-s2,e1-s2))*dcmp(cross(s1-e2,e1-e2))<=0) return 1;
    return 0;
}
Point getinter(Point a,Vector aa,Point b,Vector bb)
{
    Vector u = a-b;
    double t = cross(bb,u)/cross(aa,bb);
    return a+aa*t;
}
bool gao(Point p1,Point p2,double r)
{
    bool flag = 1;
    Point p;
    for(int i = 0; i < 3&&flag; i++)
    {
        if(isinter(a[i],a[i+1],p1,p2))
        {
            p = getinter(a[i],a[i]-a[i+1],p1-p2,p1);
            double da = dist(p,a[i]),db = dist(p,a[i+1]);
            if(dcmp(da-r)>=0&&dcmp(da-2*r)<=0&&dcmp(db-r)>=0&&dcmp(db-2*r)<=0);
            else flag = 0;
        }
    }
    for(int i = 0; i < 3&&flag; i++)
    {
        if(isinter(b[i],b[i+1],p1,p2))
        {
            p = getinter(b[i],b[i]-b[i+1],p1-p2,p1);
            double da = dist(p,b[i]),db = dist(p,b[i+1]);
            if(dcmp(da-r)>=0&&dcmp(da-2*r)<=0&&dcmp(db-r)>=0&&dcmp(db-2*r)<=0);
            else flag = 0;
        }
    }
    return flag;
}
int main()
{
    freopen("/home/qitaishui/code/in.txt","r",stdin);
    Vector vec;
    int n;
    double r,s,thr,area,sa;
    thr = sqrt(3.0);
    while(scanf("%lf%lf%d",&o.x,&o.y,&n)!=EOF)
    {
        for(int i = 0; i < n; i++)
            p[i].input();
        scanf("%lf%lf",&r,&s);
        n = ConveHull(p,n,ch);
        vec = Vector(0,1);
        a[0] = o+vec*(thr*r);
        b[0] = o-vec*(thr*r);
        tmp = o-vec*(thr*r*0.5);
        a[1] = tmp+Vector(1,0)*1.5*r;
        a[2] = tmp-Vector(1,0)*1.5*r;
        tmp = o+vec*(thr*r*0.5);
        b[1] = tmp+Vector(1,0)*1.5*r;
        b[2] = tmp-Vector(1,0)*1.5*r;
        a[3] = a[0], b[3] = b[0];
        ch[n] = ch[0];
        bool flag = 1;
        for(int i = 0; i < n&&flag; i++)
        {
            if(check(a[0],a[1],a[2],ch[i]))
            {
                if(check(a[0],a[1],a[2],ch[i+1])) continue;
                if(check(b[0],b[1],b[2],ch[i+1])&&gao(ch[i],ch[i+1],r)) continue;
            }
            else if(check(b[0],b[1],b[2],ch[i]))
            {
                if(check(b[0],b[1],b[2],ch[i+1])) continue;
                if(check(a[0],a[1],a[2],ch[i+1])&&gao(ch[i],ch[i+1],r)) continue;
            }
            flag = 0;
        }
        if(flag==0)
        {
            printf("Failed.\n");
            continue;
        }
        area = getare(ch,n);
        sa = 3*thr*r*r;
        if(dcmp(sa-area-s)>0) printf("Succeeded.\n");
        else printf("Failed.\n");
    }
    return 0;
}
