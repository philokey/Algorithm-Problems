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
const int MAXN = 500005;
const int INF = 111111111;
struct Edge{
	int v,next,w;
}edge[MAXN*85];
int head[MAXN],en,cur[MAXN],gap[MAXN],h[MAXN];
void init()
{
	memset(head,-1,sizeof(head));
	memset(cur,-1,sizeof(cur));
	en = 0;
}
void addedge(int u,int v, int w)
{
	edge[en].v = v,edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
	swap(u,v);
	edge[en].v = v,edge[en].w = 0;
	edge[en].next = head[u];
	head[u] = en++;
}
int dfs(int s,int t,int pos,int n,int cost)
{
	if(pos==t) return cost;
	int minh = n-1,lv = cost,d;
	for(int &j = cur[pos]; j !=-1; j = edge[j].next)
	{
		int v=edge[j].v,w = edge[j].w;
		if(w>0&&h[v]+1==h[pos])
		{
			d = dfs(s,t,v,n,min(lv,w));
			edge[j].w-=d;
			edge[j^1].w+=d;
			lv -= d;
			if(h[s]>=n||lv==0) return cost-lv;
		}
	}
	if(lv==cost)
	{
		for(int j = cur[pos]=head[pos]; j!=-1; j=edge[j].next)
			if(edge[j].w) minh = min(minh,h[edge[j].v]);
		gap[h[pos]]--;
		if(gap[h[pos]]==0) h[s] = n;
		h[pos]=minh+1;
		gap[h[pos]]++;
	}
	return cost-lv;
}
int sap(int st,int ed,int n)
{
	int ret = 0;
	memset(gap,0,sizeof(gap));
	memset(h,0,sizeof(h));
	gap[0] = n;
	while(h[st]<n)
		ret+=dfs(st,ed,st,n,INF);
	return ret;
}
int p[MAXN];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m,u,v,w,s,t,sum;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		s = 0,t = n+m+1;
		sum = 0;
		for(int i = 1; i <= n ;i++)
		{
			scanf("%d",&u);
			addedge(i,t,u);
		}
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(i+n,u,INF);
			addedge(i+n,v,INF);
			addedge(s,i+n,w);
			sum+=w;
		}
		printf("%d\n",sum-sap(s,t,n+m+2));
	}
	return 0;
}
