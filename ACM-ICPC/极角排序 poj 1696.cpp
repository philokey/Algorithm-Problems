//极角排序
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 1111111111;
const double eps = 1e-6;
int pos;
struct Point{
    double x,y;
    int id;
}p[maxn];
double mult(Point sp, Point ep, Point op)
{
    return (sp.x - op.x)*(ep.y - op.y)-(ep.x - op.x)*(sp.y - op.y);
}
double caldis(Point s,Point t)
{
    return sqrt((s.x - t.x)*(s.x - t.x)+(s.y-t.y)*(s.y-t.y));
}
bool cmp(Point p1,Point p2)
{
    double t = mult(p1,p2,p[pos]);
    if(t==0) return caldis(p1,p[pos])>caldis(p2,p[pos]);
    return t>0;
}
int main()
{
    freopen("in.txt","r",stdin);
    int ca,n;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d%ld%lf",&p[i].id,&p[i].x,&p[i].y);
        for(int i = 1; i < n; i++)
            if(p[i].y < p[0].y||((p[i].y == p[0].y)&&p[i].x < p[0].x))
                swap(p[i],p[0]);
        printf("%d %d",n,p[0].id);
        pos = 0;
        for(int i = 1; i < n; i++)
        {
            sort(p+i,p+n,cmp);
            pos = i;
            printf(" %d",p[i].id);
        }
        printf("\n");
    }
    return 0;
}


