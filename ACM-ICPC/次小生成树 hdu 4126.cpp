/*
题意：给一个图，问替换其中一条边的边权，且只能变大，问替换后的最小生成树
解法：先求出原图的最小生成树，由于是稠密图，所以用prim。然后采用次小生成树的算法。用树形dp。
dp[i][j]表示从i到j不走生成树上的边的最小距离。可以枚举每个节点，算出以它为根的树的dp[i][j]，即去掉ij边两棵树的最近距离
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 3005;
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXN],g[MAXN][MAXN],pre[MAXN];
int n,m;
vector<int> tree[MAXN];
void init()
{
    memset(dp,0x3f,sizeof(dp));
    memset(g,0x3f,sizeof(g));

    memset(pre,-1,sizeof(pre));
    for(int i = 0; i <= n; i++)
        tree[i].clear();
}
long long prim()
{
    long long ret = 0;
    int dist[MAXN];
    bool vis[MAXN]={0};
    for(int i = 1; i < n; i++)
    {
        dist[i] = g[0][i];
        pre[i] = 0;
    }
    vis[0] = 1;
    pre[0] = -1;
    dist[0] = INF;
    for(int k = 1; k < n; k++)
    {
        int mi = 0;
        for(int i = 1; i < n; i++)
            if(!vis[i]&&dist[mi]>dist[i]) mi = i;
        vis[mi] = 1;
        ret+=dist[mi];

        tree[mi].push_back(pre[mi]);
        tree[pre[mi]].push_back(mi);
        for(int i = 1; i < n; i++)
            if(!vis[i]&&dist[i]>g[mi][i])
                dist[i] = g[mi][i],pre[i] = mi;
    }
    return ret;
}
int dfs(int pos,int u,int fa)
{
    int ans=INF;
    for(int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        if(v==fa) continue;
        int tmp = dfs(pos,v,u);
        ans = min(tmp,ans);
        dp[u][v] = dp[v][u] = min(dp[u][v],tmp);
    }
    if(fa!=pos)
        ans = min(ans,g[pos][u]);
    return ans;
}
int main()
{
    int u,v,w;
    long long mst;
    while(scanf("%d%d",&n,&m)&&n)
    {
        init();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            g[u][v] = g[v][u] = w;
        }
        mst = prim();
        for(int i = 0; i < n; i++)
            dfs(i,i,-1);
        scanf("%d",&m);
        double ans=0;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(pre[u]==v||pre[v]==u)
                ans+=mst-g[u][v]+min(w,dp[u][v]);
            else ans+=mst;
        }
        printf("%.4f\n",ans/m);
    }
    return 0;
}
