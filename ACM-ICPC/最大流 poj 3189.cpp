#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=2005;
const int inf=1111111111;
struct Edge{
	int v,next,w;
}edge[maxn*maxn*2];
int head[maxn],en;
int gap[maxn],h[maxn],cur[maxn];
int n,m;
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
	cur[u]=head[u];
	swap(u,v);
	edge[en].v=v,edge[en].w=0;
	edge[en].next=head[u];
	head[u]=en++;
	cur[u]=head[u];
}
int dfs(int s,int t,int pos,int n,int cost)
{
	if(pos==t) return cost;
	int minh=n-1,lv=cost,d;
	for(int &j=cur[pos];j!=-1;j=edge[j].next)
	{
		int v=edge[j].v,w=edge[j].w;
		if(w>0 && h[v]+1==h[pos])
		{
			d=dfs(s,t,v,n,min(lv,w));
			edge[j].w-=d,edge[j^1].w+=d;
			lv-=d;
			if(h[s]>=n || lv==0)	return cost-lv;
		}
	}
	if(lv==cost)
	{	
                for(int j=cur[pos]=head[pos];j!=-1;j=edge[j].next)
                        if(edge[j].w) minh=min(minh,h[edge[j].v]);
		gap[h[pos]]--;
		if(gap[h[pos]]==0)	h[s]=n;
		h[pos]=minh+1;
		gap[h[pos]]++;
	}
	return cost-lv;
}
int sap(int st,int ed,int n)
{
	int ret=0;
	memset(gap,0,sizeof(gap));
	memset(h,0,sizeof(h));
	gap[0]=n;
	while(h[st]<n)
		ret+=dfs(st,ed,st,n,inf);
	return ret;
}
int cap[35],level[maxn][35];

bool check(int l,int r)
{
	memset(head,-1,sizeof(head));
	memset(cur,-1,sizeof(cur));
	en=0;
	
	for(int i=0;i<n;i++)
		for(int j=l;j<r;j++)
			addedge(i,level[i][j]+n-1,1);
	for(int i=0;i<n;++i)addedge(1400,i,1);
	for(int i=0;i<m;++i)addedge(i+n,1401,cap[i]); 
	return sap(1400,1401,n+m+2)==n;
}
int run()
{
	for(int ans=0;ans<m;++ans)  
		for(int k=0;k<m-ans;++k)  
			if(check(k,k+ans+1))
				return ans+1;
	return -1;
}
int main()
{
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&level[i][j]);
	for(int i=0;i<m;i++)
		scanf("%d",&cap[i]);
	printf("%d\n",run());
	return 0;
}
