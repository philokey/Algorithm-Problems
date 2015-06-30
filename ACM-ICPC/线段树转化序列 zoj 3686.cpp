#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const double EPS = 1e-8;
const int MAXN = 100005;
const int INF = 1111111111;
struct Edge{
	int v,next;
}edge[MAXN];
int tree[MAXN<<2],ri[MAXN],le[MAXN],lazy[MAXN<<2];
int en,head[MAXN],sn;
void addedge(int u,int v)
{
	edge[en].v = v;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	memset(head,-1,sizeof(head));
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
	en = sn = 0;
}
void dfs(int u)
{
	le[u] = ++sn;
	for(int i = head[u]; i != -1; i = edge[i].next)
		dfs(edge[i].v);
	ri[u] = sn;
}
void pushdown(int rt,int l,int r)
{
	if(lazy[rt])
	{
		int m = (l+r)>>1;
		lazy[rt<<1]^=1;
		lazy[rt<<1|1]^=1;
		tree[rt<<1] = m-l+1-tree[rt<<1];
		tree[rt<<1|1] = r-m-tree[rt<<1|1];
		lazy[rt] = 0;
	}
}
void update(int L,int R, int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		lazy[rt]^=1;
		tree[rt] = r-l+1-tree[rt];
		return;
	}
	pushdown(rt,l,r);
	int m = (l+r)>>1;
	if(L <= m) update(L,R,lson);
	if(m < R) update(L,R,rson);
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
int query(int L,int R,int l,int r,int rt)
{
	if(L <= l&& r <= R) return tree[rt];
	pushdown(rt,l,r);
	int m = (l+r)>>1;
	int ret = 0;
	if(L <= m) ret+=query(L,R,lson);
	if(R > m) ret+=query(L,R,rson);
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,q,u,v;
	char op[5];
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		init();
		for(int i = 2; i <= n; i++)
		{
			scanf("%d",&u);
			addedge(u,i);
		}
		dfs(1);
		while(q--)
		{
			scanf("%s%d",op,&u);
			if(op[0]=='o') update(le[u],ri[u],1,n,1);
			else printf("%d\n",query(le[u],ri[u],1,n,1));
		}
		printf("\n");
	}
	return 0;
}
