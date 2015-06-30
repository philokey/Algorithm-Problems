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
const int MAXN = 400005;
struct Edge{
    int v,next;
}edge[MAXN];
int le[MAXN],ri[MAXN],tree[MAXN<<2],lazy[MAXN<<2];
int head[MAXN<<1],dep[MAXN<<1],en,sn,n,m;
void init()
{
    memset(head,-1,sizeof(head));
    memset(tree,0,sizeof(tree));
    memset(lazy,0,sizeof(lazy));
    en = sn = 0;
    dep[1] = 1;
}
void addedge(int u,int v)
{
    edge[en].v = v;
    edge[en].next = head[u];
    head[u] = en++;
}
void dfs(int u,int p)
{
    le[u] = ++sn;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v!=p) {dep[v]=dep[u]+1;dfs(v,u);}
    }
    ri[u] = sn;
}
void pushdown(int rt,int l,int r)
{
    if(lazy[rt]!=0)
    {
        tree[rt<<1]+=lazy[rt];
        tree[rt<<1|1]+=lazy[rt];
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        lazy[rt] = 0;
    }
}
void update(int L,int R,int v,int l,int r,int rt)
{
    if(l>=L&&r<=R)
    {
        lazy[rt]+=v;
        tree[rt]+=v;
        return;
    }
    int m = (l+r)>>1;
    pushdown(rt,l,r);
    if(L<=m) update(L,R,v,lson);
    if(R>m) update(L,R,v,rson);
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
int query(int pos,int l,int r,int rt)
{
    if(l==pos&&r==pos)
    {
        return tree[rt];
    }
    int m = (l+r)>>1;
    pushdown(rt,l,r);
    if(pos<=m) return query(pos,lson);
    else return query(pos,rson);
}
int main()
{
    freopen("F:\\code\\in.txt","r",stdin);
    int a[MAXN],u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs(1,-1);
        //cout<<"$$"<<endl;
        int tp;
        while(m--)
        {
            scanf("%d",&tp);
            if(tp==1)
            {
                scanf("%d%d",&u,&v);
                if(dep[u]&1)
                    update(le[u],ri[u],v,1,sn,1);
                else
                    update(le[u],ri[u],-v,1,sn,1);
            }
            else
            {
                scanf("%d",&u);
                int qu = query(le[u],1,sn,1);
                if(dep[u]&1) printf("%d\n",a[u]+qu);
                else printf("%d\n",a[u]-qu);
            }
        }

    }
    return 0;
}
