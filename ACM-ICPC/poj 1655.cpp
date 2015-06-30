#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 40005;
vector<int> edge[MAXN];
int n;
int dp[MAXN],s[MAXN];
void init()
{
    for(int i = 0; i <= n; i++)
        edge[i].clear();
}
int dfs(int u,int pre)
{
    int v,sz;
    sz = edge[u].size();
    s[u] = 1;
    for(int i = 0; i < sz; i++)
    {
        v = edge[u][i];
        if(v==pre) continue;
        s[u]+=dfs(v,u);
    }
    return s[u];
}
void cal(int u,int pre)
{
    int sz,v;
    dp[u] = n-s[u];
    sz = edge[u].size();
    for(int i = 0; i < sz; i++)
    {
        v = edge[u][i];
        if(v == pre) continue;
        dp[u] = max(dp[u],s[v]);
        cal(v,u);
    }
}
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int ca,u,v;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        init();
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1,0);
        cal(1,0);
        int ans=dp[1],ai=1;
        for(int i = 2; i <= n; i++)
            if(dp[i]<ans) ans = dp[i],ai = i;
        printf("%d %d\n",ai,ans);
    }
    return 0;
}
