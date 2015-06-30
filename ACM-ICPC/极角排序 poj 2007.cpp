#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 1005;
const int inf = 1111111111;
struct Point{
    int x,y;
}p[maxn];
int mult(Point sp, Point ep, Point op)
{
    return (sp.x - op.x)*(ep.y-op.y) - (ep.x - op.x)*(sp.y - op.y);
}
bool cmp(Point p1, Point p2)
{
   return mult(p1,p2,p[0]) > 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n = 0;

    while(scanf("%d%d",&p[n].x,&p[n].y)!=EOF) n++;
    sort(p+1,p+n,cmp);
    for(int i = 0; i < n; i++)
        printf("(%d,%d)\n",p[i].x,p[i].y);
    return 0;
}

