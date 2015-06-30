#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
typedef long long LL;
using namespace std;
const double EPS = 1e-8;
const int MAXN = 755;
const int MAXM = 100005;
bool is[MAXM],vis[MAXN],can[MAXN];
int prim[MAXM/5],pcnt=0,link[MAXN];
struct Edge{
	int v,next;
}edge[MAXN*35];
int head[MAXM],en,id,un;
LL use[MAXM];
void init()
{
	en = 0;
	id = 0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
	edge[en].v = v;
	edge[en].next = head[u];
	head[u] = en++;
}
bool cmp(const LL&a,const LL&b)
{
	return a>b;
}
void get_p()
{
	for(int i = 2; i <MAXM; i++)
	{
		if(!is[i])
		{
			prim[pcnt++] = i;
			for(int j = 2; i*j<MAXM; j++)
				is[i*j] = 1;
		}
	}
}
bool dfs(int u)
{
	if(vis[u]) return 0;
	vis[u] = 1;
	for(int i = head[u]; i!=-1; i = edge[i].next)
	{
		int v = edge[i].v;

			vis[v] = 1;
			if((!can[v])&&(link[v]==-1||dfs(link[v])))
			{
				link[v] = u;
				return 1;
			}

	}
	return 0;
}
bool solve(int s,int n)
{
	memset(link,-1,sizeof(link));
	for(int i = s; i <n; i++)
	{
		memset(vis,0,sizeof(vis));
		if(!dfs(i)) return 0;
	}
	return 1;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	LL a,b;
	int n;
	get_p();
	while(scanf("%lld%lld",&a,&b)&&(a+b))
	{
		init();
		un = 0;
		for(LL i = a; i <= b; i++)
		{
			LL tmp = i;
			for(int j = 0; j < pcnt&&tmp>=prim[j]*prim[j]; j++)
			{
				if(tmp%prim[j]==0) use[un++] = prim[j];
				while(tmp%prim[j]==0) tmp/=prim[j];
			}
			if(tmp>1)
				use[un++] = tmp;
		}
		sort(use,use+un,cmp);
		un = unique(use,use+un)-use;
		id = 0;
		for(LL i = a; i <= b; i++,id++)
		{
			for(int j = 0; j < un; j++)
			{
				if(use[j]>i) break;
				if(i%use[j]==0) addedge(id,j);
			}
		}
		n = b-a+1;
		LL ans[MAXN];
		memset(can,0,sizeof(can));
		memset(ans,0,sizeof(ans));
		for(int i = 0; i < n; i++)
		{
			for(int j = head[i]; j != -1; j = edge[j].next)
			{
				int v = edge[j].v;
				if(can[v]) continue;
				can[v] = 1;
				if(solve(i+1,n))
				{
					ans[i] = use[v];
					break;
				}
				else can[v] = 0;
			}
			
		}
		for(int i = 0; i < id; i++)
			if(i==0) printf("%lld",ans[i]);
			else printf(" %lld",ans[i]);
		printf("\n");
	}
	return 0;
}
