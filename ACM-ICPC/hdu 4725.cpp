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
const int MAXN = 500005;
const int MAXM = 1000005;
const int INF = 1111111111;
struct Edge{
	int v,w,next;
}edge[MAXM];
int head[MAXN],en,bel[MAXN];
int n,m,c;
void init()
{
	en = 0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w)
{
	edge[en].v = v;edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
}
int dist[MAXN];
bool vis[MAXN];
int spfa(int s,int t)
{
	queue<int> q;
	memset(vis,0,sizeof(vis));
	for(int i = 0; i <= n*2; i++) dist[i] = INF;
	dist[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 1;
		for(int i = head[u]; i!=-1; i=edge[i].next)
		{
			int v = edge[i].v;
			if(dist[v]>dist[u]+edge[i].w)
			{
				dist[v] = dist[u]+edge[i].w;
				if(!vis[v])
					q.push(v),vis[v] = 1;
			}
		}
	}
	if(dist[t]==INF) return -1;
	return dist[t];
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);

	int cas,u,v,w;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		init();
		scanf("%d%d%d",&n,&m,&c);
		for(int i = 1; i<= n; i++)
			scanf("%d",&bel[i]);
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		for(int i = 1; i <= n; i++)
		{
			addedge(n+bel[i],i,0);
			if(bel[i]!=1) addedge(i,n+bel[i]-1,c);
			if(bel[i]!=n) addedge(i,n+bel[i]+1,c);
		}
		printf("Case #%d: %d\n",ca,spfa(1,n));
	}
	return 0;
}
