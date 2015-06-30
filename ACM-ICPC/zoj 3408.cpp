#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 50005;
const int INF = 0x3f3f3f3f;
const long long MOD = 10000000000ll;
int n,m,q;
long long cnt[2][MAXN];
struct Edge{
    int v,w,next;
}edge[MAXN*2];
struct Node{
    int u,w;
    bool operator<(const Node&x)const
    {
        return w<x.w;
    }
}node[MAXN];
int head[MAXN],dist[MAXN],en;
bool vis[MAXN];
void addedge(int u,int v,int w)
{
    edge[en].v = v, edge[en].w = w;
    edge[en].next = head[u];
    head[u] = en++;

}
void init()
{
    memset(head,-1,sizeof(head));
    en = 0;
    for(int i = 0; i <= n; i++)
        cnt[0][i] = 0,cnt[1][i] = 1;
    cnt[0][0] = 1;
}
void spfa()
{
    queue<int>q;
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    dist[0] = 0;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();vis[u] = 0;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if(dist[v]>dist[u]+edge[i].w)
            {
                dist[v] = dist[u]+edge[i].w;
                if(!vis[v])
                    q.push(v),vis[v] = 1;
            }
        }
    }
}
void print(long long a,long long b)
{
    int tmp[30]={0};
    for(int i=0;a;a/=10,++i)
    {
        long long tt=b*(a%10);
        for(int j=i,pre=0;tt||pre;++j,tt/=10)
        {
            tmp[j]+=pre+tt%10;
            pre=tmp[j]/10;
            tmp[j]%=10;
        }
    }
    for(int i=9;i>=0;--i)   printf("%d",tmp[i]);
    printf("\n");
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int u,v,w;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        init();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        spfa();
        for(int i = 0; i < n; i++)
            node[i].u = i,node[i].w = dist[i];
        sort(node,node+n);
        for(int i = 0; i < n; i++)
        {
            int u = node[i].u;
            for(int j = head[u]; j != -1; j = edge[j].next)
            {
                int v = edge[j].v, w = edge[j].w;
                if(dist[v]==dist[u]+w) cnt[0][v] = (cnt[0][v]+cnt[0][u])%MOD;
            }
        }
        for(int i = n-1; i>=0; i--)
        {
            int u = node[i].u;
            for(int j = head[u]; j != -1; j = edge[j].next)
            {
                int v = edge[j].v, w = edge[j].w;
                if(dist[v]==dist[u]+w) cnt[1][u] = (cnt[1][v]+cnt[1][u])%MOD;
            }
        }
        while(q--)
        {
            scanf("%d",&u);
            print(cnt[0][u],cnt[1][u]);
        }
    }
    return 0;
}
