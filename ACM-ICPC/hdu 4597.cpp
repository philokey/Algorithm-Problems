#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 35;
const int INF = 1111111111;
int dp[MAXN][MAXN][MAXN][MAXN];
int n,a[MAXN],b[MAXN],sum;
int solve(int u,int v,int x,int y,int s)
{
    if(dp[u][v][x][y]!=-1) return dp[u][v][x][y];
    int res = 0;

    if(u<=v)
    {
        res = max(res,s-solve(u+1,v,x,y,s-a[u]));
        res = max(res,s-solve(u,v-1,x,y,s-a[v]));
    }
    if(x<=y)
    {
        res = max(res,s-solve(u,v,x+1,y,s-b[x]));
        res = max(res,s-solve(u,v,x,y-1,s-b[y]));
    }
    return dp[u][v][x][y] = res;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        sum = 0;
        for(int i = 1; i<=n; i++) scanf("%d",&a[i]),sum+=a[i];
        for(int i = 1; i<=n; i++) scanf("%d",&b[i]),sum+=b[i];
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(1,n,1,n,sum));
    }
    return 0;
}
