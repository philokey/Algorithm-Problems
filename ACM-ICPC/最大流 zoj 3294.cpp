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
const int MAXN = 30005;
const int MAXM = 100000;
const int INF = 1111111111;
struct Edge{
	int v,next,w;
}edge[100005*8];
int head[MAXN],en;
int gap[MAXN],h[MAXN];
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].v=v,edge[en].w=0;
	edge[en].next=head[u];
	head[u]=en++;
}
int dfs(int s,int t,int pos,int n,int cost)
{
	if(pos==t)
		return cost;
	int minh=n-1,lv=cost,d;
	for(int j=head[pos];j!=-1;j=edge[j].next)
	{
		int v=edge[j].v,w=edge[j].w;
		if(w>0)
		{
			if(h[v]+1==h[pos])
			{
				d=min(lv,w);
				d=dfs(s,t,v,n,d);
				edge[j].w-=d, edge[j^1].w+=d;
				lv-=d;
				if(h[s]>=n)	return cost-lv;
				if(lv==0)	break;
			}
			if(h[v]<minh)	minh=h[v];
		}
	}
	if(lv==cost)
	{
		gap[h[pos]]--;
		if(gap[h[pos]]==0)	h[s]=n;
		h[pos]=minh+1;
		gap[h[pos]]++;
	}
	return cost-lv;
}
int sap(int s,int t,int n)
{
	int ret=0;
	memset(gap,0,sizeof(gap));
	memset(h,0,sizeof(h));
	gap[0]=n;
	while(h[s]<n)
		ret+=dfs(s,t,s,n,INF);
	return ret;
}
int a[MAXN*2],m,cnt;
pair<int,int>pa[MAXN];
int id[MAXM];
inline bool check(int x)
{
	int ret = 0;
	//if(x&1) return 0;
	while(x)
	{
		ret+=(x&1);
		x>>=1;
	}
	return ret>11;
}
int pre()
{
	cnt = 0;
	int tmp;
	for(int i = 50000; i <= MAXM; i++)
		if(check(i))
			a[cnt] = i,id[i] = cnt++;
	for(int i = 0; i < cnt; i++)
		for(int j = i+1; j < cnt; j++)
		{
			tmp = a[i]&a[j];
			if(id[tmp]&&tmp%2==0)
				pa[m].first = i,pa[m++].second = j;
		}
	//cout<<m<<endl;
}
int init()
{
	memset(head,-1,sizeof(head));
	en = 0;
}

int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	pre();
	int a,b,s,t;
	while(scanf("%d%d",&a,&b)!=EOF)
	{

		if(a==b) printf("150\n");
		else
		{
			if(!id[a]||!id[b]) {printf("0\n");continue;}
			init();
			s = 0, t = 1697;
			for(int i = 0; i < m; i++)
				addedge(pa[i].first,pa[i].second,1);
			addedge(0,id[a],150);
			addedge(id[b],t,150);
			//printf("%d\n",cnt);
			printf("%d\n",sap(s,t,1698));
		}
	}
	return 0;
}
