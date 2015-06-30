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
int match[MAXN],g[MAXN][MAXN];
bool vis[MAXN];
int n,m;
bool dfs(int u)
{
	for(int i = 1; i <= m; i++)
	{
		if(g[u][i]&&!vis[i])
		{
			vis[i] = 1;
			if(match[i]==-1||dfs(match[i]))
			{
				match[i] = u;
				return 1;
			}
		}
	}
	return 0;
}
int solve()
{
	int ret = 0;
	memset(match,-1,sizeof(match));
	for(int i = 1; i <= n; i++)
	{
		memset(vis,0,sizeof(vis));
		ret+=dfs(i);
	}
	return ret;
}
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
	int u,v;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		while(scanf("%d%d",&u,&v)&&u!=-1)
			g[u][v-n] = 1;
		int ans = solve();
		if(ans == 0) printf("No Solution!\n");
		else
		{
			printf("%d\n",ans);
			for(int i = 1; i <= m; i++)
			{
				if(match[i]!=-1) printf("%d %d\n",match[i],i+n);
			}
		}
	}
	return 0;
}





