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
const int MAXN = 1005;
const int INF = 1111111111;
const double PI = acos(-1.0);
char f[45][45];
int n,m,q,dp[45][45],cnt[45][45];
int main()
{
    freopen("/home/qitaishui/code/in.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%s",f[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0] = f[0][0]-'0';
        for(int i = 1; i < m; i++)
            dp[0][i] = dp[0][i-1]+f[0][i]-'0';
        for(int i = 1; i < n; i++)
        {
            int tmp = 0;
            for(int j = 0; j < m; j++)
            {
                tmp+=f[i][j]-'0';
                dp[i][j] = dp[i-1][j]+tmp;
            }
        }
        int ans,a,b,c,d;
        while(q--)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            a--,b--,c--,d--;
            ans = dp[c][d]-dp[c][b]-dp[a][d]+dp[a][b];
            printf("%d\n",ans);
        }

    }
    return 0;
}
