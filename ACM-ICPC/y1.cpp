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
const int MAXN = 100005;
char str[MAXN];
int dp[MAXN][2];
int main()
{
    freopen("F:\\code\\in.txt","r",stdin);
    int ca,n;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%s",str);
        n = strlen(str);
        memset(dp,-1,sizeof(dp));
        if(str[0]!='?') dp[0][str[0]-'0']=1;
        else dp[0][0] = dp[0][1] = 1;
        for(int i = 1; i < n; i++)
        {
            if(str[i]!='?')
            {
                int tmp = str[i]-'0';
                if(dp[i-1][tmp^1]!=-1) dp[i][tmp] = dp[i][tmp^1]+1;
                else dp[i][tmp] = 1;
            }
            else
            {
                if(dp[i-1][0]!=-1) dp[i][1] = dp[i-1][0]+1;
                else dp[i][1] = 1;
                if(dp[i-1][1]!=-1) dp[i][0] = dp[i-1][1]+1;
                else dp[i][0] = 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans,max(dp[i][0],dp[i][1]));
        printf("%d\n",ans/2*2);
    }
    return 0;
}
