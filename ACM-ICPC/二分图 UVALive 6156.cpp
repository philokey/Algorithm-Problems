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
const int MAXN = 5005;
const int INF = 1111111111;
int n,m,a[105][105],g[MAXN][MAXN],links[MAXN];
bool vis[MAXN];
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
int solve()
{
	int ret=0;
	memset(links,-1,sizeof(links));
	for(int i = 1; i <= n; i++)
	{
		memset(vis,0,sizeof(vis));
		ret+=dfs(i);
	}
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,tmp,u,v,cn,cm,tx[105][105],ty[105][105];;

	scanf("%d",&cas);
	while(cas--)
	{
		memset(a,0,sizeof(a));
		scanf("%d%d%d",&n,&m,&tmp);
		while(tmp--)
		{
			scanf("%d%d",&u,&v);
			a[u][v] = 1;
		}
		scanf("%d",&tmp);
		while(tmp--)
		{
			scanf("%d%d",&u,&v);
			a[u][v] = 2;
		}
		cn = cm = 0;
		bool pr = 0;
		for(int i = 1; i <= n; i++)
		{
			int j=1;
            while (j<=m)
            {
                cn++;
                while (j<=m&&a[i][j]!=2) tx[i][j++]=cn;
                while (j<=m&&a[i][j]==2) j++;
            }
		}


		for(int j = 1; j<= m; j++)
		{
			int i = 1;
			while(i<=n)
			{
				cm++;
				while(i<=n&&a[i][j]!=2) ty[i++][j]=cm;
				while(i<=n&&a[i][j]==2) i++;
			}
		}
		memset(g,0,sizeof(g));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(a[i][j]==1)
					g[tx[i][j]][ty[i][j]] = 1;
		n = cn,m = cm;
		printf("%d\n",solve());
	}
	return 0;
}
