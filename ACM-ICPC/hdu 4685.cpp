#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1005;
const int INF = 1111111111;
struct Node{
	int v,next;
}edge[MAXN];
int head[MAXN],dfn[MAXN],links[MAXN],low[MAXN],id[MAXN],g[MAXN][MAXN];
bool vis[MAXN];
int en,scc,n,m,cnt;
stack<int>sta;
vector<int> ans[MAXN];
void addedge(int u,int v)
{
	//cout<<u<<" "<<v<<endl;
	edge[en].v = v;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	en = cnt = scc = 0;
	memset(head,-1,sizeof(head));
	memset(dfn,-1,sizeof(dfn));
	memset(links,-1,sizeof(links));
	memset(g,0,sizeof(g));
	for(int i = 0; i <= n; i++)
		ans[i].clear();
}
bool dfs(int u)
{
	for(int i = 1; i <= m; i++)
	{

		if(g[u][i]&&!vis[i])
		{
			vis[i] = 1;

			if(links[i]==-1||dfs(links[i]))
			{
				links[i] = u;
				return 1;
			}

		}
	}
	return 0;
}
void gao()
{
	for(int i = 1; i <= n; i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i);
	}

}
void tarjan(int u)
{
	dfn[u] = low[u] = cnt++;
	sta.push(u);
	vis[u] = 1;
	for(int i = head[u]; i!= -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if(dfn[v]==-1)
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(vis[v]) low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		int v;
		do
		{
			v = sta.top();
			sta.pop();
			vis[v] = 0;
			id[v] = scc;
		}while(u!=v);
		scc++;
	}
}
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,u,v;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		scanf("%d%d",&n,&m);
		init();

		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&u);
			while(u--)
			{
				scanf("%d",&v);
				g[i][v] = 1;
			}
		}
		gao();
		for(int i = 1; i <= m; i++)
			addedge(0,i+n);
		for(int i = 1; i<=m; i++)
			addedge(links[i],i+n);

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				if(g[i][j]&&links[j]!=i)
				{
					addedge(j+n,i);
					if(links[j]!=-1)
					{
						addedge(j+n,0);
					}
				}

			}

		memset(vis,0,sizeof(vis));
		for(int i = 1; i <= n; i++)
			if(dfn[i]==-1)
				tarjan(i);
		//cout<<scc<<endl;
		printf("Case #%d:\n",ca);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(g[i][j]&&id[i]==id[j]) ans[i].push_back(j);
		for(int i = 1; i <= n; i++)
		{
			printf("%d",ans[i].size());
			for(int j = 0; j < ans[i].size(); j++)
			{
				printf(" %d",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
