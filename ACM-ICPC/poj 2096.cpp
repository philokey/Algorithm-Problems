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
const int MAXN = 1005;
const int INF = 1111111111;
double dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n,s,ns;
double solve(int i,int j) {
    if (i < 0 || j < 0) return 0;
    if (vis[i][j]) return dp[i][j];
    vis[i][j] = 1;
    return dp[i][j] = ((n-i+1)*j*solve(i-1,j) + i*(s-j+1)*solve(i,j-1) + (n-i+1)*(s-j+1)*solve(i-1,j-1))/(ns-i*j) + 1;
}
int main() {
    freopen("F:\\retired\\in.txt","r",stdin);

    while (scanf("%d%d",&n,&s)!=EOF) {
        ns = n*s;
        dp[0][0] = 0;
        vis[0][0] = 1;
        memset(vis,0,sizeof(vis));
        double ans = solve(n,s);
        printf("%.4f\n",ans);
    }
    return 0;
}
