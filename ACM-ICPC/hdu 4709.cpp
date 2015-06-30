#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN= 205;
const double EPS = 1e-8;
const double INF = 1e50;
inline int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    void input(){scanf("%lf%lf",&x,&y);}
    //void output(){}
}p[MAXN];
typedef Point Vector;
inline double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}
double length(Vector a)
{
    return sqrt(dot(a,a));
}
inline double area(Point a,Point b,Point c)
{
    return fabs(cross(b-a,c-a))/2;
}
int main()
{
    //freopen("/home/moor/Code/1004.txt","r",stdin);
    int n,cas;
    //bool flag;
    double ans;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
       // flag=1;
        ans = INF;
        for(int i = 0; i<n;i++)
            p[i].input();
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                for(int k = j+1; k < n;k++)
                {
                    double tmp = area(p[i],p[j],p[k]);
                   //cout<<i<<" "<<j<<" "<<k<<" "<<tmp<<endl;
                    if(dcmp(tmp)!=0)
                        ans = min(ans,tmp);
                }
        if(dcmp(ans-INF)==0) printf("Impossible\n");
        else printf("%.2f\n",ans);
    }
    return 0;
}
