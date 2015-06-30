#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const int maxn = 200005;
struct Edge{
	int v,next;
}edge[maxn];
int head[maxn],d1[maxn],d2[maxn],en;
bool vis[maxn];
void addedge(int u,int v)
{
	edge[en].v = v;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	en = 0;
}
void dfs1(int u,int pre)
{
	vis[u] = 1;
	d1[u] = d2[u] = 0;
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if(v == pre) continue;
		dfs1(v,u);
		if(d1[u] < d1[v]+1)
		{
			d2[u] = d1[u];
			d1[u] = d1[v]+ 1;
		}
		else if(d2[u] < d1[v]+1)
			d2[u] = d1[v]+1;
	}
}
void dfs2(int u,int pre)
{
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if(v == pre) continue;
		if(d1[u] > d1[v] + 1) d1[v] = d1[u] + 1;
		else if(d1[v] < d2[u] + 1) d1[v] = d2[u] + 1;
		else if(d2[v] < d2[u] + 1) d2[v] = d2[u] + 1;
		dfs2(v,u);
	}
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,n,m,u,v;
	scanf("%d",&cas);
	while(cas--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i = 1; i < n; i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		for(int i = 1; i<=n; i++)
			if(!vis[i]) dfs1(i,-1),dfs2(i,-1);
		int q,len=0;
		for(int i = 1; i <= n; i++) len=max(len,d1[i]);
		//cout<<len<<endl;
		for(int i = 0; i < m; i++)
		{
			scanf("%d",&q);
			if(q<=len+1) printf("%d\n",q-1);
			else printf("%d\n",(q-len-1)*2+len);
		}
		//printf("\n");
	}
	return 0;
}
