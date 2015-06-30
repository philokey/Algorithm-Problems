#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
const double EPS = 1e-8;
const int MAXN = 20005;
struct Edge{
	int v,w,next;
}edge[MAXN],q[2000005];
int head[MAXN],en,vis[MAXN],fa[MAXN],ans[2000005],dist[MAXN],scc;
int qn,headq[MAXN],rank[MAXN];
int n,m;

int init()
{
	memset(head,-1,sizeof(head));
	memset(headq,-1,sizeof(headq));
	en = scc = qn = 0;
	memset(vis,-1,sizeof(vis));
	memset(ans,-1,sizeof(ans));
	for(int i =0;i <=n; i++)
		fa[i] = i,rank[i] = 1;
}
void addedge(int u,int v,int w)
{
	edge[en].v = v,edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
}
void addedge2(int u,int v,int w)
{
	q[qn].v = v,q[qn].w = w;
	q[qn].next = headq[u];
	headq[u] = qn++;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}

void tarjan(int u,int pre)
{
	int v;
	for(int i = head[u]; i!=-1; i=edge[i].next)
	{
		v = edge[i].v;
		if(v==pre) continue;
		dist[v] = dist[u]+edge[i].w;
		tarjan(v,u);
		fa[v] = u;
	}
	vis[u] = scc;
	for(int i = headq[u]; i!=-1; i=q[i].next)
	{
		v = q[i].v;
		int w = q[i].w;
		if(vis[v]==scc)
			ans[w] = dist[u]+dist[v]-2*dist[find(v)];
	}
}
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
	int u,v,w,qx;
	while(scanf("%d%d%d",&n,&m,&qx)!=EOF)
	{
		init();
		for(int i = 0; i < m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		for(int i = 0 ;i <qx; i++)
		{
			scanf("%d%d",&u,&v);
			addedge2(u,v,i);
			addedge2(v,u,i);
		}
		for(int i = 1; i <= n; i++)
		{
			if(vis[i]==-1)
			{
				dist[i] = 0;
				tarjan(i,-1);
				++scc;
			}

		}
		for(int i = 0; i < qx; i++)
			if(ans[i]==-1) printf("Not connected\n");
			else printf("%d\n",ans[i]);
	}
	return 0;
}

