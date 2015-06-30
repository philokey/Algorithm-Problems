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
const int MAXN = 50005;
const int MAXM = 2000005;
const long long INF = 1ll<<60;
typedef long long LL;
struct Edge{
    int v,next;
    LL w;
}edge[MAXM];

int head[MAXN],en;
int h[MAXN],gap[MAXN];
void init()
{
	memset(head,-1,sizeof(head));
	en = 0;
}
void addedge(int u,int v,LL w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].v=v,edge[en].w=0;
	edge[en].next=head[u];
	head[u]=en++;
}
LL dfs(int s,int t,int pos,int n,LL cost)
{
	if(pos==t)
		return cost;
	int minh=n-1;
	LL lv=cost,d;
	for(int j=head[pos];j!=-1;j=edge[j].next)
	{
		int v=edge[j].v;
		LL w=edge[j].w;
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
LL sap(int st,int ed,int n)
{
	LL ret=0;
	memset(gap,0,sizeof(gap));
	memset(h,0,sizeof(h));
	gap[0]=n;
	while(h[st]<n)
		ret+=dfs(st,ed,st,n,INF);
	return ret;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int n,m,cas,s,t,w,p;
    LL sum,tmp,u,v;
    scanf("%d",&cas);
    for(int ca=1; ca<=cas; ca++)
    {
        scanf("%d",&n);
        init();
        sum = 0;
        p=2;
        s = 0, t = 1;
        for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=1;j<=m;j++)
			{
				LL cost,val;
				int w;
				scanf("%I64d%I64d%d",&cost,&val,&w);
				val-=cost;
				if(val>0)
				{
					addedge(s,i*26+j,val);
					sum+=val;
				}
				else addedge(i*26+j,t,-val);
				while(w--)
				{
					int a,b;
					scanf("%d%d",&a,&b);
					addedge(i*26+j,a*26+b,INF);
				}
			}
		}
		//cout<<sum<<endl;
        cout<<"Case #"<<ca<<": "<<sum-sap(s,t,n*26)<<"\n";
    }
    return 0;
}
