#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
#define MAXN 2005
const double EPS = 1e-8;
inline int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(double k)const{return Point(k*x,k*y);}
    Point operator/(double k)const{return Point(x/k,y/k);}
    bool operator==(const Point&a)const
    {
        return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
    }
    void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN],ans[MAXN];
typedef Point Vector;
inline double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}
inline double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}
inline double length(Vector a)
{
    return sqrt(dot(a,a));
}
int main()
{
    int n,m,cas=0;
    double len,tmp;
    Vector vec;
    //freopen("/home/moor/Code/input","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cas++;
        len = 0;
        p[0] = Point(0,0);
        for(int i = 1; i <= n; i++)
        {
            p[i].input();
            len+=length(p[i]-p[i-1]);
        }
        len/=(m+1);
        Point now=p[0];
        int pos=0;
        double clen = len;
        for(int i = 0; i < m; i++)
        {
            tmp = length(p[pos+1]-now);
            len = clen;
            while(dcmp(tmp-len)<0)
            {
                pos++;
                now = p[pos];
                len-=tmp;
                tmp = length(p[pos+1]-now);
            }
            vec = (p[pos+1]-now)/tmp;
            if(dcmp(tmp-len)==0)
            {
                ans[i] = p[pos];
                pos++;
            }
            else
                ans[i] = now+vec*len;
            now = ans[i];
        }
        printf("Route %d\n",cas);
        for(int i = 0; i < m; i++)
            printf("CP%d: (%.3f, %.3f)\n",i+1,ans[i].x,ans[i].y);
    }
    return 0;
}
