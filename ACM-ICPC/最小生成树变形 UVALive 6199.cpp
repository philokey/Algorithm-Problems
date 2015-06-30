#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 1005
#define maxm 2000005
#define inf 111111111
const double eps=1e-8;
using namespace std;
struct Point{
    double x,y;
    void input(){scanf("%lf%lf",&x,&y);}
    bool operator <(const Point &a)const
    {
        return y<a.y||(fabs(y-a.y)<eps&&x<a.x);
    }
}p[maxn];
struct Edge{
	int u,v;
	double w;
	bool operator <(const Edge&e)const
	{
		return w<e.w;
	}
}edge[maxm];
double dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int n,fa[maxn];
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
double solve()
{
	Edge tmp,tp;
	double pos = p[0].y,ret=0;
	int b,u,v,cnt,num,i;
	for(i = 0; i <= n; i++) fa[i] = i;
	u = 0;
	for(i = 1; i < n; i++)
	{
		v = i;
		if(fabs(p[i].y-pos)<eps)
		{
			v = find(v);
			fa[v] = u;
			ret+=p[i].x-p[i-1].x;
		}
		else break;
	}
	b = i;
	while(i<n)
	{
		int en=0;
		pos = p[i++].y;
		num=1;
		for(; i < n; i++)
			if(fabs(p[i].y-pos)<eps) b++,num++;
			else break;
		for(int j = b; j>b-num; j--)
			for(int k = j-1; k >= 0; k--)
			{
				tmp.u = k,tmp.v = j,tmp.w = dist(p[k],p[j]);
				edge[en++] = tmp;
			}
		cnt = 0;
		sort(edge,edge+en);
		for(int j = 0;j<en&&cnt<num;j++)
		{
			tp = edge[j];
			u = find(tp.u),v = find(tp.v);
			if(u!=v)
			{
				fa[u] = v;
				cnt++;
				ret+=tp.w;
			}
		}
		b = i;
	}
	return ret;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    while(scanf("%d",&n)&&n)
    {
        for(int i = 0; i < n; i++) p[i].input();
        sort(p,p+n);
        printf("%.2f\n",solve());
    }
    return 0;
}

