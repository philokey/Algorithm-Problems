#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 505;
const int INF = 0x3f3f3f3f;
struct Edge{
    int u,v,next,cap,cost;
}edge[50005];
int head[MAXN],en;
void init() {
    en = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost) {
    edge[en].v = v, edge[en].u = u, edge[en].cap = cap, edge[en].cost = cost;
    edge[en].next = head[u];
    head[u] = en++;
    swap(u,v);
    edge[en].v = v, edge[en].u = u, edge[en].cap = 0, edge[en].cost = -cost;
    edge[en].next = head[u];
    head[u] = en++;
}
int mcmf(int s,int t,int flow) {
    int c = 0, f = 0, v,u;
    queue<int> q;
    int dist[MAXN], pre[MAXN];
    bool vis[MAXN];
    while (true) {
        memset(vis,0,sizeof(vis));
        memset(pre,-1,sizeof(pre));
        memset(dist,0x3f,sizeof(dist));
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            vis[u] = 0;
            for (int i = head[u]; i != -1; i = edge[i].next) {
                v = edge[i].v;
                if (edge[i].cap > 0 && dist[v] > dist[u] + edge[i].cost) {
                    dist[v] = dist[u] + edge[i].cost;
                    pre[v] = i;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
        if (dist[t] == INF) break;
        int a = INF;
        for (int i = pre[t]; i != -1; i = pre[edge[i].u]) {
            a = min(a,edge[i].cap);
        }
        f += a;
        c += dist[t]*a;
        for (int i = pre[t]; i != -1; i = pre[edge[i].u]) {
            edge[i].cap -= a;
            edge[i^1].cap += a;
        }
    }
    if (f < flow) return -1;
    return c;
}
int main() {
    freopen("F:\\retired\\in.txt","r",stdin);
    int n,m,k;
    int u,v,w,c;
    while (scanf("%d%d%d",&n,&m,&k)!=EOF) {
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%d",&u,&v,&w,&c);
            for (int i = 0; i < c; ++i) {
                addedge(u,v,1,(2*i+1)*w);
            }
        }
        addedge(0,1,k,0);
        printf("%d\n",mcmf(0,n,k));
    }
    return 0;
}
