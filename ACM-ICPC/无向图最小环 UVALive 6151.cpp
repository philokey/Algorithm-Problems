#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1005;
const int MAXM = 50005;
const int INF = 1111111111;
struct Edge{
	int v,next;
}edge[MAXM];
int head[MAXN],en,ans,dist[MAXN],fa[MAXN];
bool vis[MAXN];
void init()
{
	en = 0;
	memset(head,-1,sizeof(head));
	memset(fa,-1,sizeof(fa));
	ans = INF;
	memset(vis,0,sizeof(vis));
}
void addedge(int u,int v)
{
	edge[en].v = v;
	edge[en].next = head[u];
	head[u] = en++;
}
void bfs(int u)
{
	queue<int> q;
	q.push(u);
	vis[u] = 1;
	dist[u] = 0;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		if(dist[u]*2+1>=ans) return;
		for(int i = head[u]; i!=-1; i = edge[i].next)
		{
			int v = edge[i].v;
			if(!vis[v])
			{
				vis[v] = 1;
				fa[v] = u;
				q.push(v);
				dist[v] = dist[u]+1;
			}
			else if(fa[u]!=v)
				ans = min(ans,dist[u]+dist[v]+1);
		}
	}
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,u,v;
	int n,m;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		for(int i = 0; i < n; i++)
		{
			memset(vis,0,sizeof(vis));
			bfs(i);
		}
		printf("Case %d: ",ca);
		if(ans == INF) printf("impossible\n");
		else printf("%d\n",ans);
	}
	return 0;
}
