#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
const double EPS= 1e-8;
const double PI = acos(-1.0);
const int MAXN = 305;
const double INF = 1e60;
using namespace std;
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
    Point operator*(double k)const{return Point(x*k,y*k);}
    bool operator<(const Point &a)const
    {
        return dcmp(x-a.x)==0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
    }
    void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN],v[MAXN];
typedef Point Vector;
int n;
inline double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}
inline double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*a.y;
}
inline double length(Vector a)
{
    return dot(a,a);
}
double at,al;
Point pt[MAXN];
inline double judge()
{
    double ret = 0;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j<n; j++)
            ret = max(ret,length(pt[i]-pt[j]));
    return ret;
}
void solve()
{
    double l,r,mid1,mid2;

    l = 0, r = 1e5;
    while(dcmp(r-l)>0)
    {
        mid1= l+(r-l)*0.382;
        mid2 = l+(r-l)*0.618;
        for(int i = 0; i < n; i++)
            pt[i] = p[i]+v[i]*mid1;
        double a = judge();
        for(int i = 0; i < n; i++)
            pt[i] = p[i]+v[i]*mid2;
        double b = judge();
        if(dcmp(a-b)<=0)
        {
            at = mid2;
            al = a;
            r = mid2;
        }
        else l =mid1;
    }
}
int main()
{
    //freopen("/home/moor/Code/input","r",stdin);
    int cas;
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas; ca++)
    {
        scanf("%d",&n);
        for(int i = 0;i < n; i++)
        {
            p[i].input();
            v[i].input();
        }
        solve();
        printf("Case #%d: ",ca);
        printf("%.2f %.2f\n",at,sqrt(al));
    }

    return 0;
}
