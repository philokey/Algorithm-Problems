#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 305;
const int inf = 1111111111;
int main()
{

    int a[maxn],dp[maxn][maxn],n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    for(int l = 2; l <= n; l++)
    {
        for(int i = 1; i <= n&&i+l<=n; i++)
        {
            int j = i + l;
            dp[i][j]=inf;
            for(int k = i+1; k < j; k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}

