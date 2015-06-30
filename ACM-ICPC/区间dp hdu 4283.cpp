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
const int INF = 1111111111;
int sum[MAXN],a[MAXN],dp[MAXN][MAXN];
int main()
{
	int T,n;
	int cas=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=0;i<=n;i++)
			for(int j=i;j<=n;j++)
				dp[i][j]=INF;
		for(int i=1;i<=n;i++)
			dp[i][i]=0;
		for(int len=1;len<n;len++)
			for(int i=1;i+len<=n;i++)
			{
				int j=i+len;
				dp[i][j]=min(dp[i][j],dp[i+1][j]+sum[j]-sum[i]);
				for(int k=i+1;k<=j;k++)
					dp[i][j]=min(dp[i][j],dp[i+1][k]+a[i]*(k-i)+dp[k+1][j]+(sum[j]-sum[k])*(k-i+1));
			}
		printf("Case #%d: %d\n",cas++,dp[1][n]);
	}
	return 0;
}
