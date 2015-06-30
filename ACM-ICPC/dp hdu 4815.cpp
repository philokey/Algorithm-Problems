/*
题意：给n道题，每个题两个选项，猴子随机选一个答案，每题有分值，问老虎至少得多少分，可以保证以>=p的概率不输给猴子
解法：dp，用dp[i][j]表示到第i题，得分为j的概率，然后再求sum(Pi)<=p的最大值
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 50005;
const double EPS = 1e-8;
double dp[45][MAXN];
int a[45];
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int ca;
    int n;
    double p;
    scanf("%d",&ca);
    while(ca--)
    {
        int m = 0;
        scanf("%d%lf",&n,&p);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            m+=a[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                dp[i][j]+=dp[i-1][j]*0.5;
                dp[i][j+a[i]]+=dp[i-1][j]*0.5;
            }
        }
        double s = 0;
        int ans = 0;
        for(int i = 0; i <= m; i++)
        {
            s+=dp[n][i];
            if(p-s>EPS) ans++;
            else break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
