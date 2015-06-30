#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105;
int g[maxn][maxn],rg[maxn][maxn],n,nn,id[maxn],pre[maxn][maxn],sum;
int color[maxn],cnt1,cnt0,flag;
struct Node{
	int x,y;
}node[maxn];
void dfs(int u)
{
	id[u]=nn;
	for(int i=1;i<=n&&flag;i++)
	{
		if(rg[u][i]&&color[i]==-1)
		{
			color[i]=(color[u]^1);
			if(color[i]==0)	cnt0++;
			else cnt1++;
			dfs(i);
		}
		if(rg[u][i]&&color[i]==color[u])	flag=0;
	}
}
void solve()
{
	bool dp[maxn][maxn*2];
	int ans[maxn];
	memset(dp,0,sizeof(dp));
	dp[0][101]=1;
	for(int i=1;i<=nn;i++)
	{
		int w=abs(node[i].x-node[i].y);
		for(int j=w;j<=202;j++)
			if(dp[i-1][j])  dp[i][j-w]=1,pre[i][j-w]=j;
		for(int j=0;j<=202-w;j++)
			if(dp[i-1][j])	dp[i][j+w]=1,pre[i][j+w]=j;
	}
	int p;
	for(int i=0;i<=n;i++)
	{
		if(dp[nn][101-i])
		{
			p=101-i;
			break;
		}
		if(dp[nn][101+i])
		{
			p=i+101;
			break;
		}
	}
	//printf("%d\n",i);
	int x=(n-(p-101))/2;
	for(int i=nn;i>0;i--)
	{
		if(p+node[i].x-node[i].y==pre[i][p])
			ans[i]=0;
		else ans[i]=1;
		p=pre[i][p];
	}
	printf("%d",x);
	for(int i=1;i<=n;i++)
		if(color[i]==ans[id[i]])
			printf(" %d",i);
	printf("\n%d",n-x);
	for(int i=1;i<=n;i++)
		if(color[i]!=ans[id[i]])
			printf(" %d",i);
	printf("\n");
}
int main()
{
	//freopen("in.txt","r",stdin);
	int v;
	while(scanf("%d",&n)!=EOF)
	{
		memset(g,0,sizeof(g));
		memset(rg,0,sizeof(rg));
		memset(color,-1,sizeof(color));
		flag=1;
		for(int i=1;i<=n;i++)
			while(scanf("%d",&v)&&v)
				g[i][v]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j)	continue;
				if(g[i][j]==0)	rg[i][j]=rg[j][i]=1;
			}
		nn=0;
		for(int i=1;i<=n&&flag;i++)
		{
			if(color[i]==-1)
			{
				nn++;
				cnt0=0,cnt1=1;
				color[i]=1;
				dfs(i);
				node[nn].x=cnt0,node[nn].y=cnt1;
			}
		}

		if(!flag)
		{
			printf("No solution\n");
			continue;
		}
		solve();
	}
	return 0;
}
