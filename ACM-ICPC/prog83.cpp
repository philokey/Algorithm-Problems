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
const int INF = 1111111111;
int g[MAXN][MAXN],match[MAXN],fan[MAXN];
int n,m;
bool vis[MAXN];
bool dfs(int u)
{
	//cout<<u<<endl;
	for(int i = 1; i <= n;i++)
	{
		if(!vis[i]&&g[u][i])
		{
			vis[i] = 1;
			if(match[i]==-1||dfs(match[i]))
			{
				match[i] = u;
				fan[u] = i;
				return 1;
			}
		}
	}
	return 0;
}
int solve()
{
	int ret=0;
	memset(match,-1,sizeof(match));
	memset(fan,-1,sizeof(fan));
	for(int i = 1; i <= n; i++)
	{
		memset(vis,0,sizeof(vis));
		ret+=dfs(i);
	}
	return ret;
}
void print(int u)
{

	vis[u] = 1;
	if(match[u]!=-1)
		print(match[u]);
	printf("%d ",u);
}
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);

	int u,v,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(g,0,sizeof(g));
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d",&u,&v);
			g[u][v] = 1;
		}
		ans = solve();
		memset(vis,0,sizeof(vis));
		for(int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			print(i);
			for(int j = fan[i]; j!=-1; j = fan[j])
			{
				vis[j] = 1;
				printf("%d ",j);
			}
			printf("\n");
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
