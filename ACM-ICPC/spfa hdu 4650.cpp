#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
const double EPS = 1e-8;
const int MAXN = 50005;
const int MAXM = 505;
const double INF = 1e50;
int n,m;
struct Edge{
	int v,w,next;
}edge[MAXN];
int head[MAXM],en,g[MAXM][MAXM];
double dist[MAXM][MAXM],ans[MAXM][MAXM];
bool vis[MAXM][MAXM];
inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
inline void addedge(int u,int v,int w)
{
	edge[en].v = v,edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	en = 0;
	memset(head,-1,sizeof(head));
	memset(g,0,sizeof(g));
	for(int i = 0; i < n; i++)
		for(int j =0; j <n;j++)
			ans[i][j] = INF;
}
inline void spfa(int s)
{
	memset(vis,0,sizeof(vis));
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			dist[i][j] = INF;
	queue<pair<int,int> > q;
	dist[s][0] = 0;
	q.push(MP(s,0));
	int u,k,v;
	while(!q.empty())
	{
		u = q.front().FI;
		k = q.front().SE;
		vis[u][k] = 0;
		q.pop();
		for(int i = head[u]; i!=-1; i = edge[i].next)
		{
			v=edge[i].v;
			if(k+1<=n&&dcmp(dist[v][k+1]-(dist[u][k]+edge[i].w)>0))
			{
				dist[v][k+1]=dist[u][k]+edge[i].w;
				if(!vis[v][k+1])
				{
					vis[v][k+1] = 1;
					q.push(MP(v,k+1));
				}
			}
		}
	}

}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int u,v,w;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			--u,--v;
			g[u][v]=1;
			addedge(u,v,w);
		}
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n;i++)
				for(int j = 0; j < n;j++)
					if(g[i][k]&&g[k][j]) g[i][j]=1;
		for(int i = 0; i < n;i++)
		{
			spfa(i);
			for(int j = 0; j < n; j++)
				for(int k = 1; k <= n; k++)
				{
					if(dcmp(dist[j][k]-INF)<0&&dist[j][k]/k<ans[i][j])
						ans[i][j] = dist[j][k]/k;
				}
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
				{
					if(g[j][i]&&g[i][k])
						ans[j][k] = min(ans[j][k],ans[i][i]);
				}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(j) printf(" ");
				if(dcmp(ans[i][j]-INF)==0)
					printf("NO");
				else printf("%.3f",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
