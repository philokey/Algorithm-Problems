#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
const double eps = 1e-8;
const int maxn = 300005;
const int inf = 1111111111;
using namespace std;
struct Point{
    double x,y;
    bool tp;
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
}p[maxn],q[maxn];
int n;
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x < 0? -1:1;
}
bool cmp1(const Point a, const Point b)
{
    if(dcmp(a.x-b.x)==0) return a.y<b.y;
    return a.x<b.x;
}
bool cmp2(const Point a,const Point b)
{
    return a.y<b.y;
}
double dist(Point a, Point b)
{
	if(a.tp==b.tp) return inf;
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double solve(int l,int r)
{
    double d = inf;
    if(l>=r) return d;
    if(l+1==r) return dist(p[l],p[r]);
    //if(l+2==r) return min(dist(l,l+1),min(dist(l,r),dist(l+1,r)));
    int m = (l+r)/2;
    d = min(solve(l,m),solve(m+1,r));
    int k = 0;
    for(int i = l; i <= r; i++)
    {
        if(fabs(p[m].x-p[i].x) <= d)
            q[k++] = p[i];
    }
    sort(q,q+k,cmp2);
    for(int i = 0; i < k; i++)
        for(int j = i+1; j < k && q[j].y-q[i].y<d; j++)
            d = min(d, dist(q[i],q[j]));
    return d;
}

int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            p[i].tp = 0;
            p[i].input();
        }
        for(int i = n; i < 2*n; i++)
        {
            p[i].tp = 1;
            p[i].input();
        }
        n*=2;
        sort(p,p+n,cmp1);
        printf("%.3f\n",solve(0,n-1));
    }
    return 0;
}
