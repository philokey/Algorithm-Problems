#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 80005;
struct Edge{
	int v,w,next;
}edge[MAXN];
vector<pair<int,int> > q[MAXN/2];
int fa[MAXN];
int head[MAXN],en,ans[MAXN],dist[MAXN];
bool vis[MAXN];
int n,m;
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void addedge(int u,int v, int w)
{
	edge[en].w = w,edge[en].v = v;
	edge[en].next = head[u];
	head[u] = en++;
}
void tarjan(int u,int pre)
{
	for(int i = head[u]; i!=-1;i = edge[i].next)
	{
		int v = edge[i].v;
		if(v==pre) continue;
		dist[v] = dist[u]+edge[i].w;
		tarjan(v,u);
		fa[v] = u;
	}
	vis[u] = 1;
	for(int i = 0; i < q[u].size(); i++)
	{
		int v = q[u][i].first;
		if(vis[v])
			ans[q[u][i].second] = dist[u]+dist[v]-2*dist[find(v)];
	}
}
void init()
{
	en = 0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(dist,0,sizeof(dist));
	memset(ans,0,sizeof(ans));
	for(int i = 0; i <= n;i++)
		fa[i] = i,q[i].clear();
}

int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,u,v,w;

	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d",&n,&m);
		init();
		for(int i = 1; i < n; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		for(int i = 0 ;i < m; i++)
		{
			scanf("%d%d",&u,&v);
			q[u].push_back(make_pair(v,i));
			q[v].push_back(make_pair(u,i));
		}
		tarjan(1,-1);
		for(int i = 0; i < m ;i++)
			printf("%d\n",ans[i]);

	}
	return 0;
}
