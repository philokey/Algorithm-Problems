#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<iostream>
using namespace std;
const int maxn = 1205;
struct Edge{
	int v,next;
}edge[maxn*3];
int n,r;
int head[maxn],dfn[maxn],low[maxn],en,num,ind[maxn];
void addedge(int u,int v)
{
	edge[en].v = v;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	num = 0;
	en = 0;
	memset(head,-1,sizeof(head));
	memset(dfn,-1,sizeof(dfn));
	memset(ind,0,sizeof(ind));
}
void tarjan(int u,int fa)//简化的tarjan
{
	int v;
	dfn[u] = low[u] = ++num;
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		v = edge[i].v;
		if(v == fa) continue;
		if(dfn[v] == -1) tarjan(v,u);
		low[u] = min(low[v],low[u]);
	}
}
int main()
{
	int u,v;
	while(scanf("%d%d",&n,&r)!= EOF)
	{
		init();
		for(int i = 0; i < r; i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		for(int i = 1; i <= n; i++)
			if(dfn[i] == -1)	tarjan(i,-1);
		for(int i = 1; i <= n;i++)
			for(int j= head[i];j!= -1;j= edge[j].next)//缩点
				if(low[i]!=low[edge[j].v]) ind[low[i]]++;
		int ans = 0;
		for(int i = 1; i <= num; i++)
			if(ind[i] == 1) ans++;//变成一棵树后统计叶子的个数
		printf("%d\n",(ans+1)/2);//两个叶子相连成环就好了

	}
	return 0;
}
