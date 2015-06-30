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
int le[MAXN],ri[MAXN],tree[MAXN<<1];
int head[MAXN<<1],dep[MAXN<<1],en,sn,n,m;
void init()
{
    memset(head,-1,sizeof(head));
    memset(tree,0,sizeof(tree));
    en = 0;
    sn = 0;
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
inline int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int v)
{
    while(x<=sn)
    {
        tree[x]+=v;
        x += lowbit(x);
    }
}
int query(int x)
{
    int s = 0;
    while(x){s+=tree[x];x-=lowbit(x);}
    return s;
}
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
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
                if((dep[u]&1)==0) v=-v;
                update(le[u],v);
                update(ri[u]+1,-v);
            }
            else
            {
                scanf("%d",&u);
                int qu = query(le[u]);
                if(dep[u]&1) printf("%d\n",a[u]+qu);
                else printf("%d\n",a[u]-qu);
            }
        }

    }
    return 0;
}

