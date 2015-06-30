#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 2005;
const int INF = 1111111111;
vector<int> g[MAXN];
int sg[MAXN];
int n;
void init()
{
	for(int i = 0; i <= n; i++)
		g[i].clear();
	memset(sg,-1,sizeof(sg));
}
int get_sg(int u)
{
	if(sg[u]!=-1) return sg[u];
	bool vis[1005]={0};
	for(int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		sg[v] = get_sg(v);
		vis[sg[v]] = 1;
	}
	for(int i = 0; i < n; i++)
		if(vis[i]==0) return i;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);

	int m,u;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		for(int i = 0; i <n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&u);
				g[i].push_back(u);
			}
		}
		int ret = 0;
		while(scanf("%d",&m)&&m)
		{
			ret = 0;
			while(m--)
			{
				scanf("%d",&u);
				if(sg[u]==-1) sg[u] = get_sg(u);
				ret^=sg[u];
			}
			if(ret==0) puts("LOSE");
			else puts("WIN");
		}
	}
	return 0;
}
