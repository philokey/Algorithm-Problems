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
const int MAXN = 100005;
vector<int>edge[MAXN];
int pa[MAXN],sum[MAXN];
bool vis[MAXN];
char ans[MAXN];
int dfs(int u,int fa,int n)
{
    if(vis[u]) return -1;
    int sz = edge[u].size();
    int v,tmp,ans=-1;
    bool flag = 1;
    sum[u] = 1;
    for(int i = 0; i < sz; i++)
    {
        v = edge[u][i];
        if(v == fa||vis[v]) continue;
        tmp = dfs(v,u,n);
        sum[u]+=sum[v];
        if(sum[v]>n/2) flag = 0;
        if(tmp!=-1)ans = tmp;
        pa[v] = u;
    }
    if(n-sum[u]>n/2) flag = 0;
    if(flag) ans = u;
    return ans;
}


void solve(int u,char c,int n)
{
    if(vis[u]) return;
    int p,sz;
    pa[u] = -1;
    p = dfs(u,0,n);
   // cout<<p<<endl;
    vis[p] = 1;
    ans[p] = c;
    sz = edge[p].size();
    for(int i = 0; i < sz; i++)
    {
        int v = edge[p][i];
        if(pa[p]!=v)  solve(v,c+1,sum[v]);
    }
    if(pa[p]!=-1)
        solve(pa[p],c+1,n-sum[p]);
}
int main()
{
   // freopen("F:\\code\\in.txt","r",stdin);
    int n;
    int u,v;
    scanf("%d",&n);
    for(int i = 1; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    solve(1,'A',n);
    for(int i = 1; i <= n; i++)
        printf("%c ",ans[i]);
    printf("\n");
    return 0;
}
