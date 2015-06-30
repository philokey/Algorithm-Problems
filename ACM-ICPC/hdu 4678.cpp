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
const int MAXN = 1005;
const int INF = 1111111111;
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,0,1,-1,0,1,-1};
int n,m,c;
int g[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool check(int x,int y)
{
	return x>=0&&x<n&&y>=0&&y<m;
}
int bfs(int x,int y)
{
	int ret = 1;
	queue<pair<int,int> > q;
	pair<int,int> u;
	q.push(MP(x,y));
	vis[x][y] = 1;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for(int i = 0; i < 8; i++)
		{
			x = u.FI+dx[i];
			y = u.SE+dy[i];
			if(check(x,y)&&g[x][y]!=1&&!vis[x][y])
			{
				vis[x][y] = 1;
				if(g[x][y]==0) q.push(MP(x,y));
				else ret++;
			}
		}
	}
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,u,v,ans,cnt,num;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		scanf("%d%d%d",&n,&m,&c);
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		num = 0;
		for(int i = 0; i < c; i++)
		{
			scanf("%d%d",&u,&v);
			g[u][v] = 1;
			for(int j = 0; j < 8;j++)
				if(check(u+dx[j],v+dy[j])&&g[u+dx[j]][v+dy[j]]==0)
					g[u+dx[j]][v+dy[j]] = 2;
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(g[i][j]==2) num++;
		ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				if(!vis[i][j]&&g[i][j]==0)
				{
					cnt = bfs(i,j);
					ans^=(2-(cnt%2));
					num = num-cnt+1;
				}

			}

		if(num)
			ans^=(num%2);
		printf("Case #%d: ",ca);
		if(ans) puts("Xiemao");
		else puts("Fanglaoshi");
	}
	return 0;
}
