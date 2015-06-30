#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
const int MAXM = 200010;
const int INF = 1111111111;
const double PI = acos(-1.0);
struct Edge{
    int v,w,next;
}edge[MAXM];
int head[MAXN],en,en2,n,m,s1,s2,mlen,bn;
int id[MAXN],dfn[MAXN],low[MAXN],scc,num,bridge[MAXN][3],ans;
stack<int> sta;
void addedge(int u,int v,int w)
{
    edge[en].v = v,edge[en].w = w;
    edge[en].next = head[u];
    head[u] = en++;
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(dfn,-1,sizeof(dfn));
    en = bn = 0;
    num = 0;
    scc = 0;
    while(!sta.empty()) sta.pop();
    mlen = INF;
}
void tarjan(int u,int fa)
{
    dfn[u] = low[u] = num++;
    sta.push(u);
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        if(dfn[v]==-1)
        {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>dfn[u])
            {
                bridge[bn][0] = u, bridge[bn][1] = v;
                bridge[bn++][2] = edge[i].w;
            }
        }
        else low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        int v;
        scc++;
        do
        {
            v = sta.top();sta.pop();
            id[v] = scc;
        }while(u!=v);
    }
}

int dfs(int u,int pre)
{
    int m1=INF,m2=INF;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==pre)continue;
        int w=dfs(v,u);
        w = min(w,edge[i].w);
        if(w<m1) m2 = m1,m1 = w;
        else if(w<m2) m2 = w;

    }
    ans=min(ans,m2);
    return m1;
}
void shrink()
{
    int u,v,w;
    tarjan(1,-1);
    en = 0;
    memset(head,-1,sizeof(head));
    for(int i = 0; i < bn; i++)
    {
        u = id[bridge[i][0]];
        v = id[bridge[i][1]];
        w = bridge[i][2];
        addedge(u,v,w);
        addedge(v,u,w);
        if(w<mlen) mlen = w, s1 = u,s2 = v;
    }
}
int solve()
{
    ans = INF;
    dfs(s1,s2);
    dfs(s2,s1);
    if(ans == INF) return -1;
    return ans;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        shrink();

        printf("%d\n",solve());
    }
    return 0;
}
