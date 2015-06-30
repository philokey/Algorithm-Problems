#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1005;
const double INF = 1e50;
const double PI = acos(-1.0);
int pre[MAXN];
int n,m;
double dp[MAXN][MAXN],g[MAXN][MAXN];
vector<int>tree[MAXN];
struct Point{
    double x,y;
    void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN];
inline double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void init()
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
            dp[i][j] = INF;
        pre[i] = -1;
        tree[i].clear();
    }
}
double prim()
{
    double ret = 0,dist[MAXN];
    bool vis[MAXN]={0};
    for(int i = 1; i < n; i++)
        dist[i] = g[i][0];
    memset(pre,0,sizeof(pre));
    dist[0] = INF;
    vis[0] = 1;
    for(int k = 1;k < n; k++)
    {
        int mi=0;
        for(int i = 1; i < n; i++)
            if(!vis[i]&&dist[i]<dist[mi]) mi = i;
        vis[mi] = 1;
        tree[mi].push_back(pre[mi]);
        tree[pre[mi]].push_back(mi);
        ret+=dist[mi];
        for(int i = 1; i < n; i++)
            if(!vis[i]&&dist[i]>g[mi][i])
                dist[i] = g[mi][i],pre[i] = mi;
    }
    return ret;
}
double dfs(int pos,int u,int fa)
{
    double ret = INF;
    for(int i = 0; i < (int)tree[u].size(); i++)
    {
        int v = tree[u][i];
        if(v==fa) continue;
        double tmp = dfs(pos,v,u);
        ret = min(tmp,ret);
        dp[u][v] = dp[v][u] = min(dp[u][v],tmp);
    }
    if(pos!=fa)
        ret = min(ret,g[pos][u]);
    return ret;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i = 0; i < n; i++)
            p[i].input();
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                g[i][j] = g[j][i] = dist(p[i],p[j]);
        double mst = prim();
        for(int i = 0; i < n; i++)
            dfs(i,i,-1);
        double ans = mst;
        for(int i = 1; i < n; i++)
            for(int j = i+1; j < n; j++)
            {
                if(pre[i]==j||pre[j]==i)
                    ans = max(ans,mst-g[i][j]+dp[i][j]);
            }
        printf("%.2f\n",ans*m);
    }
    return 0;
}
