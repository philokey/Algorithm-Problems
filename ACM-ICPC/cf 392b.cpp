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
const int MAXN = 105;
int c[4][4];
long long dp[MAXN][4][4];
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int n;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d",&c[i][j]);
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int l = 1; l <= n; l++)
        for(int i=0; i < 3; i++)
            for(int j=0; j<3; j++)
            {
                if(i==j) continue;
                int k = 3-i-j;
                dp[l][i][j] = min(dp[l-1][i][k]+c[i][j]+dp[l-1][k][j],
								2*dp[l-1][i][j]+c[i][k]+dp[l-1][j][i]+c[k][j]);
            }
    cout<<dp[n][0][2]<<endl;
    return 0;
}
