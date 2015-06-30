#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1015;
struct Node{
	int u,v;
	double w;
	bool operator < (const Node &a)const
	{
		return w<a.w;
	}
}node[MAXN*MAXN*2];
struct Point{
	double x,y;
	void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN];
struct Edge{
	int v,next;
	double w;
}edge[MAXN*5];
int n,val[MAXN],nn,fa[MAXN];
int head[MAXN],en;
double g[MAXN][MAXN];

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}
double Dist(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void addedge(int u,int v,double w)
{
	edge[en].v = v,edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
}
void dfs(int root,int u,int pre)
{
	for(int i = head[u]; i !=-1; i = edge[i].next)
	{
		int v = edge[i].v;
		if(v == pre) continue;
		g[root][v] = max(g[root][u],edge[i].w);
		dfs(root,v,u);
	}
}
double solve()
{
	double sum = 0;
	int cnt = 0;
	for(int i = 0; i <= n; i++) fa[i] = i;
	en = 0;
	memset(head,-1,sizeof(head));
	sort(node,node+nn);
	for(int i = 0; i < nn&&cnt!=n-1; i++)
	{
		int u = find(node[i].u),v = find(node[i].v);
		if(u!=v)
		{
			fa[u] = v;
			sum+=node[i].w;
			cnt++;
			addedge(node[i].u,node[i].v,node[i].w);
			addedge(node[i].v,node[i].u,node[i].w);
		}
	}
	memset(g,0,sizeof(g));
	for(int i = 0; i < n; i++)
		dfs(i,i,i);
	double ret=0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i!=j)
			ret = max(ret,(val[i]+val[j])/(sum-g[i][j]));
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		nn = 0;
		for(int i = 0; i < n; i++)
			p[i].input(),scanf("%d",&val[i]);
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
			{
				node[nn].u = i;
				node[nn].v = j;
				node[nn++].w = Dist(p[i],p[j]);
			}
		printf("%.2f\n",solve());
	}
	return 0;
}
