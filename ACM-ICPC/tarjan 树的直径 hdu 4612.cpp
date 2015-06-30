//time 1031MS
//memory 31340K
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 300015
#define MAXM 4000015
using namespace std;
struct Edge{
    int v,next;
}edge[MAXM],edge2[MAXM];
int head[MAXN],en;
int head2[MAXN],en2;
int id[MAXN],dfn[MAXN],low[MAXN],sta[MAXN],top,num,scc;
int n,m;
bool vis[MAXN];
void init()
{
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    en = 0;
    top = 0;
    scc=num = 0;memset(dfn,0,sizeof(dfn));
}
void addedge(int u,int v)
{
    edge[en].v = v;
    edge[en].next = head[u];
    head[u] = en++;
}
void addedge2(int u,int v)
{
    edge2[en2].v = v;
    edge2[en2].next = head2[u];
    head2[u] = en2++;
}
void tarjan(int u,int fa)
{
    dfn[u] = low[u] = ++num;
    sta[++top] = u;
    int cnt=0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
        }
        else if (fa==v)
        {
            if (cnt) low[u] = min(low[u],dfn[v]);//重边
            cnt++;
        }
        else low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        int x;
        scc++;
        do
        {
            x = sta[top--];
            id[x] = scc;
        }while(x!=u);
    }
}
void build()
{
    en2 = 0;
    memset(head2,-1,sizeof(head2));
    for(int i = 1; i <= n; i++)
    {
        for(int j = head[i]; j!=-1; j = edge[j].next)
        {
            int v = edge[j].v;
            if(id[i]!=id[v])
                addedge2(id[i],id[v]);
        }
    }
}
int ans;
int dfs(int u,int p)
{
    int max1=0,max2=0;
    for (int i=head2[u];i!=-1;i=edge2[i].next)
    {
        int v=edge2[i].v;
        if (v==p) continue;
        int tmp=dfs(v,u)+1;
        if (max1<tmp) max2=max1,max1=tmp;
        else if (max2<tmp) max2=tmp;
    }
    ans=max(ans,max1+max2);
    return max1;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int u,v;
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        init();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d",&u,&v);
            if (v==u) continue;
            addedge(u,v);
            addedge(v,u);
        }

        tarjan(1,-1);
        build();
        ans=0;
        dfs(1,-1);
        printf("%d\n",scc-ans-1);
    }
    return 0;
}
