#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int maxn=155;
bool g[maxn][maxn],inque[maxn],inblossom[maxn];
int match[maxn],pre[maxn],base[maxn];
int n,m;
queue<int> q;
pair<int,int> pa[maxn];
void reset(int u,int anc)
{
	while(u!=anc)
	{
		int v=match[u];
		inblossom[base[u]]=1;
		inblossom[base[v]]=1;
		v=pre[v];
		if(base[v]!=anc)	pre[v]=match[u];
		u=v;
	}
}
int findancestor(int u,int v)
{
	bool inpath[maxn]={0};
	while(1)
	{
		u=base[u];
		inpath[u]=1;
		if(match[u]==-1)break;
		u=pre[match[u]];
	}
	while(1)
	{
		v=base[v];
		if(inpath[v])	return v;
		v=pre[match[v]];
	}
}
void contract(int u,int v,int n)
{
	int anc=findancestor(u,v);
	memset(inblossom,0,sizeof(inblossom));
	reset(u,anc),reset(v,anc);
	if(base[u]!=anc)	pre[u]=v;
	if(base[v]!=anc)	pre[v]=u;
	for(int i=1;i<=n;i++)
	{
		if(inblossom[base[i]])
		{
			base[i]=anc;
			if(!inque[i])
			{
				q.push(i);
				inque[i]=1;
			}
		}
	}
}
bool bfs(int s,int n,int a,int b)
{

	for(int i=0;i<=n;i++)
		pre[i]=-1,inque[i]=0,base[i]=i;
	while(!q.empty())	q.pop();
	q.push(s),inque[s]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v=1;v<=n;v++)
		{
			if(v==a||v==b) continue;
			if(g[u][v]&&base[v]!=base[u]&&match[u]!=v)
			{
				if(v==s||(match[v]!=-1&&pre[match[v]]!=-1))
					contract(u,v,n);
				else if(pre[v]==-1)
				{
					pre[v]=u;
					if(match[v]!=-1)	q.push(match[v]),inque[match[v]]=1;
					else
					{
						u=v;
						while(u!=-1)
						{
							v=pre[u];
							int w=match[v];
							match[u]=v;
							match[v]=u;
							u=w;
						}
						return true;
					}
				}
			}
		}
	}
	return false;
}
int solve(int a,int b)
{
	memset(match,-1,sizeof(match));
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		if(i==a||i==b) continue;
		if(match[i]==-1) bfs(i,n,a,b);
	}
	for(int i = 1; i <= n; i++)
		if(match[i]!=-1) cnt++;
	return cnt;
}

int main()
{
	int u,v,cnt,tx,ma;
	vector<int> ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(g,0,sizeof(g));
		ans.clear();
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d",&u,&v);
			pa[i] = make_pair(u,v);
			g[u][v] = g[v][u] = 1;
		}
		ma = solve(-1,-1);
		for(int i = 1; i <= m; i++)
		{
			u = pa[i].first,v = pa[i].second;
			bool tmp = g[u][v];
			tx = solve(u,v);
			if(tx<ma-2) ans.push_back(i);
		}
		printf("%d\n",ans.size());
		for(int i = 0; i < ans.size(); i++)
			if(i==0) printf("%d",ans[i]);
			else printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
