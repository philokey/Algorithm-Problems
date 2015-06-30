#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int MOD = 1000000007;
int dp[1005][20005];
int a[1005];
int main()
{
    //freopen("F://code//in.txt","r",stdin);
    int n,m;
    m = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        m+=a[i];
    }
    //dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        dp[i][a[i]+m]=dp[i][m-a[i]] = 1;
        for(int j = 0; j <= m*2+3; j++)
        {
            dp[i][j] = (dp[i][j]+dp[i-1][j-a[i]]+dp[i-1][j+a[i]])%MOD;
        }
    }

    int ans=0;
    for(int i = 1; i <= n; i++)
        ans = (ans+dp[i][m])%MOD;
    printf("%d\n",ans);

    return 0;
}
