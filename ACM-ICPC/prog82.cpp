#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1005;
const int MAXM = 10005;
const int INF = 1111111111;
struct Edge{
	int v,next,w;
}edge[MAXM];
int head[MAXN],gap[MAXN],h[MAXN],en;
void addedge(int u,int v,int w)
{
	edge[en].v = v,edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
	swap(u,v);
	edge[en].v = v,edge[en].w = 0;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	en = 0;
	memset(head,-1,sizeof(head));
}
int dfs(int s,int t,int pos,int n,int cap)
{
	if(pos==t) return cap;
	int minh = n-1,lv = cap,d;
	for(int j = head[pos];j!=-1; j= edge[j].next)
	{
		int v = edge[j].v,w = edge[j].w;
		if(w>0)
		{
			if(h[v]+1==h[pos])
			{
				d = min(lv,w);
				d = dfs(s,t,v,n,d);
				edge[j].w-=d,edge[j^1].w+=d;
				lv -= d;
				if(h[s]>=n) return cap-lv;
				if(lv==0) break;
			}
			if(h[v]<minh) minh=h[v];
		}
	}
	if(lv==cap)
	{
		gap[h[pos]]--;
		if(gap[h[pos]]==0) h[s]=n;
		h[pos] = minh+1;
		gap[h[pos]]++;
	}
	return cap-lv;
}
int sap(int s,int t,int n)
{
	int ret = 0;
	memset(gap,0,sizeof(gap));
	memset(h,0,sizeof(h));
	gap[0] = n;
	while(h[s]<n)
		ret+=dfs(s,t,s,n,INF);
	return ret;
}

void get(int s)
{
	memset(h,-1,sizeof(h));
	h[s] = 0;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();q.pop();
		for(int i = head[u]; i!=-1; i=edge[i].next)
		{
			int v = edge[i].v;
			if(h[v]==-1&&edge[i].w>0)
			{
				h[v] = 0;
				q.push(v);
			}
		}
	}
}
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m,s,t;
	int u,v,sum;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		s = 0,t = m+n+1;
		init();
		sum = 0;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d",&u);
			sum += u;
			addedge(s,i,u);
			while(getchar()!='\n')
			{
				scanf("%d",&u);
				addedge(i,u+m,INF);
			}
		}
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&u);
			addedge(i+m,t,u);
		}
		int ans = sum - sap(s,t,t+1);
		get(0);
		for(int i=1; i<=m; i++)
		{
			if(h[i]!=-1) printf("%d ",i);
		}
		printf("\n");
		for(int i = m+1; i <= n+m; i++)
		{
			if(h[i]!=-1) printf("%d ",i-m);
		}
		printf("\n");
		printf("%d\n",ans);
	}
	return 0;
}

