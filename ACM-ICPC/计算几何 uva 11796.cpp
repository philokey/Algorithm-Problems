#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 105;
const int inf = 1111111111;
const double eps = 1e-8;
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){};
    Point(double a,double b):x(a),y(b){}
    Point operator *(double c) {return Point(x*c,y*c);}
    Point operator /(double c) {return Point(x/c,y/c);}
    Point operator -(const Point a){return Point(x-a.x,y-a.y);}
    Point operator +(const Point a){return Point(x+a.x,y+a.y);}
    bool operator <(const Point &a)const
    {
        return x<a.x||(x==a.x&&y<a.y);
    }
    bool operator ==(const Point &a)const
    {
        return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
    }
    void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
double Cross(Vector a, Vector b)
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
double Getdis(Point p1, Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double Distoseg(Point p, Point a, Point b)
{
    if(a==b) return Length(p-a);
    Vector v1 = b-a, v2 = p-a, v3 = p-b;
    if(dcmp(Dot(v1,v2)<0)) return Length(v2);
    if(dcmp(Dot(v1,v3))>0) return Length(v3);
    return fabs(Cross(v1,v2))/Length(v1);
}
double Min,Max;
void solve(Point p, Point a, Point b)
{
    Min = min(Min,Distoseg(p,a,b));
    Max = max(Max,max(Getdis(p,a),Getdis(p,b)));
}
int main()
{
    //freopen("in.txt","r",stdin);
    int cas,n,m;
    Point pa[maxn],pb[maxn],na,nb;
    double la,lb;
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas;ca++)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
            pa[i].input();
        for(int i = 0; i < m; i++)
            pb[i].input();
        la = lb = 0;
        for(int i = 1; i < n; i++)
            la+=Getdis(pa[i-1],pa[i]);
        for(int i = 1; i < m; i++)
            lb+=Getdis(pb[i-1],pb[i]);
        na = pa[0],nb = pb[0];
        Min = inf, Max = -inf;
        int xa=1,xb=1;
        double laa,lbb,t;
        while(xa<n&&xb<m)
        {
            laa = Length(na-pa[xa]);
            lbb = Length(nb-pb[xb]);
            t = min(laa/la,lbb/lb);
            Vector va = (pa[xa]-na)/laa*t*la;
            Vector vb = (pb[xb]-nb)/lbb*t*lb;
            solve(na,nb,nb+vb-va);
            na = na+va;
            nb = nb+vb;
            if(na==pa[xa]) xa++;
            if(nb==pb[xb]) xb++;
            //cout<<xa<<" "<<xb<<endl;
        }
        printf("Case %d: %.0f\n",ca,Max-Min);
    }
    return 0;
}











