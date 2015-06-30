#include<cstdio>
#include<stack>
#include<cstring>
#define maxn 10005
#define maxm 50005
using namespace std;
int m,n,head[maxn],dfn[maxn],low[maxn],id[maxn],scc,t;
bool vis[maxn];
struct node{
	int v,next;
}edge[maxm];
stack<int> sta;
void tarjan(int v)
{
	dfn[v]=low[v]=t++;
	sta.push(v);
	vis[v]=1;
	for(int i=head[v];i!=-1;i=edge[i].next){
		int x=edge[i].v;
		if(!dfn[x]){
			tarjan(x);
			low[v]=min(low[v],low[x]);
		}
		else
			low[v]=min(low[v],dfn[x]);//
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
	scc=0;
	for(int i=1;i<=n;i++){
		if(!dfn[i])
			tarjan(i);
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		for(int j=head[i];j!=-1;j=edge[j].next){
			if(id[i]!=id[edge[j].v])
				vis[id[i]]=1;
		}
	}
	int p,cnt=0;
	for(int i=1;i<=scc;i++){
		if(!vis[i])
			cnt++,p=i;
	}
	if(cnt>1)
		printf("0\n");
	else{
		cnt=0;
		for(int i=1;i<=n;i++)
			if(id[i]==p)
				cnt++;
		printf("%d\n",cnt);
	}
}
int main()
{
	int a,b;
	scanf("%d%d",&n,&m);
	t=1;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		dfn[i]=0;
		head[i]=-1;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		edge[i].v=b;
		edge[i].next=head[a];
		head[a]=i;
	}
	solve();

}
