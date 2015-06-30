//线段和射线相交，wa的一把鼻涕一把眼泪的！
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 4005;
const int inf = 100005;
const double eps = 1e-8;
struct Point{
    double x,y;
    Point() {} ;
    Point (double a , double b) : x(a) , y(b) {}
    Point operator * (double c) {return Point ( x * c , y * c ) ; }
	Point operator - (const Point a) {return Point ( x - a.x , y - a.y );}
	Point operator + (const Point a) {return Point ( x + a.x , y + a.y );}
};
double mult(Point sp, Point ep, Point op)
{
    return (sp.x-op.x)*(ep.y-op.y) - (ep.x-op.x)*(sp.y-op.y);
}

bool isIntersected(Point p1, Point p2, Point s, Point e)
{
    p2 = (p2 - p1) * 50000 + p1;
    if(min(p1.x,p2.x)<=max(s.x,e.x)&&
       min(p1.y,p2.y)<=max(s.y,e.y)&&
       min(s.x,e.x)<=max(p1.x,p2.x)&&
       min(s.y,e.y)<=max(p1.y,p2.y)&&
       mult(p1, p2, s)*mult(p1, p2, e)<=0&&
       mult(s,e,p1)*mult(s,e,p2)<=0) return 1;
    return 0;
}
Point p[maxn][2];
int main()
{
    freopen("in.txt","r",stdin);
    int ca,n;
    Point pos;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 2; j++)
                scanf("%lf%lf",&p[i][j].x,&p[i][j].y);
        scanf("%lf%lf",&pos.x,&pos.y);
        int ans = 0, tmp;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 2; j++)
            {
                tmp = 0;
                for(int k = 0; k < n; k++)
                    if(isIntersected(pos,p[i][j],p[k][0],p[k][1])) tmp++;
                ans = max(ans,tmp);
            }
        printf("%d\n",ans);
    }
    return 0;
}
