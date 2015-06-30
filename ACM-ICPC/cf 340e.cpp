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
const int MAXN = 2015;
const int MOD = 1000000007;
long long dp[MAXN][MAXN];
int a[MAXN];
bool vis[MAXN];
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int m,n,k;
    scanf("%d",&m);
    n = k = 0;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=-1) vis[a[i]] = 1;
    }
    for(int i = 1; i <= m; i++)
        if(a[i] == -1)
        {
            if(vis[i]) n++;
            else k++;
        }
    //cout<<n<<" "<<k<<endl;
    dp[0][0] = 1;
    for(int i = 1; i<=n+k; i++) dp[i][0] = dp[i-1][0]*i%MOD;
    for(int i = 0; i<=n+k; i++) dp[i][1] = dp[i][0]*i%MOD;
    for(int j = 2; j<=k; j++)
        for(int i = 0; i <= n+k; i++)
            dp[i][j] = (i*dp[i][j-1]+(j-1)*dp[i+1][j-2])%MOD;
    printf("%d\n",dp[n][k]);
    return 0;
}
