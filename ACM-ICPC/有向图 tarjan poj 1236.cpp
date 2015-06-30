#include<cstdio>
#include<cstring>
#include<stack>
#define maxn 105
using namespace std;
struct node{
	int v,next;
}edge[maxn*maxn];
int head[maxn],low[maxn],dfn[maxn],n,t=0,id[maxn],num=1,scc=0;
bool vis[maxn],flag[maxn];
stack<int> sta;
void addedge(int u,int v){
	edge[t].v=v,edge[t].next=head[u];
	head[u]=t++;
}
void tarjan(int v)
{
	dfn[v]=low[v]=num++;
	sta.push(v);
	vis[v]=1;
	for(int i=head[v];i!=-1;i=edge[i].next){
		int x=edge[i].v;
		if(!dfn[x]){
			tarjan(x);
			low[v]=min(low[v],low[x]);
		}
		else if(vis[x])
			low[v]=min(low[v],low[x]);//
	}
	if(low[v]==dfn[v]){
		scc++;
		int x;
		do{
			x=sta.top();
			sta.pop();
			vis[x]=0;
			id[x]=scc;
		}while(x!=v);
	}
	return;
}
void solve()
{
	bool cd[maxn];
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	memset(flag,0,sizeof(flag));
	memset(cd,0,sizeof(cd));
	for(int i=1;i<=n;i++){
		for(int j=head[i];j!=-1;j=edge[j].next){
			if(id[i]!=id[edge[j].v])
				flag[id[edge[j].v]]=1,cd[id[i]]=1;//查找与其他连通分量的交集，以此判断入度
		}
	}
	int p,cnt=0,cds=0;
	for(int i=1;i<=scc;i++){
		if(!flag[i])
			cnt++;//计算入度为0的点的个数
		if(!cd[i])
			cds++;
	}
	if(scc==1&&cnt==1)
		printf("1\n0\n");

	else{
		printf("%d\n%d\n",cnt,max(cnt,cds));
	}
}
int main()
{
	int a;
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++){
		while(scanf("%d",&a)&&a)
			addedge(i,a);
	}
	solve();
}
