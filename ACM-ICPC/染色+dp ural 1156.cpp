#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const int maxn = 305;
bool g[maxn][maxn],flag;
int color[maxn],cnt0,cnt1,id[maxn];
int n,m,nn;
struct Node{
	int x,y;
}node[maxn];
int dfs(int u)
{
	id[u] = nn;
	for(int i = 1; i <= n; i++)
	{
		if(g[u][i]&&color[i]==-1)
		{
			color[i] = color[u]^1;
			if(color[i]==0) cnt0++;
			else cnt1++;
			dfs(i);
		}
		if(g[u][i]&&color[u]==color[i]) flag = 0;
	}

}
void solve()
{
	//cout<<"**\n";
	//cout<<nn<<endl;
	bool dp[maxn][maxn*2];
	int pre[maxn][maxn],ans[maxn];
	memset(dp,0,sizeof(dp));
	dp[0][101] = 1;
	for(int i = 1; i <= nn; i++)
	{
		int w = abs(node[i].x-node[i].y);
		for(int j = w; j<=202;j++)
			if(dp[i-1][j]) dp[i][j-w] = 1,pre[i][j-w] = j;
		for(int j = 0; j <= 202-w; j++)
			if(dp[i-1][j]) dp[i][j+w] = 1,pre[i][j+w] = j;
	}
	if(dp[nn][101]==0)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	int p = 101;
	for(int i =nn;i>0; i--)
	{
		if(p+node[i].x-node[i].y==pre[i][p]) ans[i] = 0;
		else ans[i] = 1;
		p = pre[i][p];
	}
	flag = 0;
	for(int i = 1; i <= n; i++)
		if(color[i]!=ans[id[i]])
		{
			if(!flag) printf("%d",i),flag = 1;
			else printf(" %d",i);
		}
	printf("\n");
	flag = 0;
	for(int i=1;i<=n;i++)
		if(color[i]==ans[id[i]])
		{
			if(!flag) printf("%d",i),flag = 1;
			else printf(" %d",i);
		}
	printf("\n");
}
int main()
{
	//freopen("in.txt","r",stdin);
	int u,v;
	scanf("%d%d",&n,&m);
	n*=2;
	nn = 0;
	flag = 1;
	memset(color,-1,sizeof(color));
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	for(int i =1; i <=n&&flag; i++)
	{
		//cout<<i<<endl;
		if(color[i]==-1)
		{
			++nn;
			cnt0=0;
			color[i] = 1;
			cnt1 = 1;
			dfs(i);
			node[nn].x = cnt0,node[nn].y = cnt1;
		}
	}
	if(flag == 0) printf("IMPOSSIBLE\n");
	else solve();
	return 0;
}
