#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 300010;
const int INF = 1111111111;
struct Edge{
	int v,next;
}edge[MAXN];
int head[MAXN],en,dfn[MAXN],low[MAXN],cnt,scc,id[MAXN],num[MAXN];
int ind[MAXN],ond[MAXN];
bool insta[MAXN],vis[MAXN];
stack<int> sta;
void addedge(int u,int v)
{
	edge[en].v = v;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	memset(head,-1,sizeof(head));
	memset(dfn,-1,sizeof(dfn));
	memset(num,0,sizeof(num));
	memset(ind,0,sizeof(ind));
	memset(ond,0,sizeof(ond));
	en = cnt = 0;
	scc = 0;
	memset(insta,0,sizeof(insta));
	memset(vis,0,sizeof(vis));
}
void tarjan(int u)
{
	dfn[u] = low[u] = cnt++;
	sta.push(u);
	vis[u] = 1;insta[u] = 1;
	for(int i = head[u]; i!= -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if(dfn[v]==-1)
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(insta[v]) low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		int v;
		do
		{
			v = sta.top();
			sta.pop();
			insta[v] = 0;
			id[v] = scc;
			num[scc]++;
		}while(u!=v);
		scc++;
	}
}
void gao(int n)
{
	int v;
	for(int i = 1; i <=n; i++)
	{
		for(int j = head[i]; j != -1; j = edge[j].next)
		{
			v = edge[j].v;
			if(id[i]!=id[v]) ond[id[i]]++,ind[id[v]]++;
		}
	}
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,v,u,cnt;
	int n,m;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		scanf("%d%d",&n,&m);
		init();
		cnt = 0;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		for(int i = 1; i <= n; i++)
			if(!vis[i]) tarjan(i);
		printf("Case %d: ",ca);
		int ans = 0,tmp;
		if(scc==1) printf("-1\n");
		else
		{
			gao(n);
			for(int i = 0; i < scc; i++)
			{
				if(ind[i]==0||ond[i]==0)
				{
					tmp = num[i];
					ans = max(ans,tmp*(tmp-1)+(n-tmp)*(n-tmp-1)+(n-tmp)*(tmp));
				}
			}
			printf("%d\n",ans-m);
		}
	}
	return 0;
}
