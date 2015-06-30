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
const int MOD = 10007;
char str[MAXN];
int dp[MAXN][MAXN],len;
int solve()
{
	for(int i = len-1; i >= 0; i--)
		for(int j = i; j < len; j++)
		{
			if(i==j)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
			if(str[i]==str[j]) dp[i][j]+=dp[i+1][j-1]+1;
			dp[i][j] = (dp[i][j]+MOD)%MOD;
		}
	return dp[0][len-1];
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		scanf("%s",str);
		memset(dp,0,sizeof(dp));
		len = strlen(str);
		printf("Case %d: %d\n",ca,solve());
	}
	return 0;
}
