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
const int MAXN = 10005;
const int INF = 1111111111;
double dp[2][205];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m,l,r,s,w,d;
	while(scanf("%d%d%d%d",&n,&m,&l,&r)&&(n+m+l+r))
	{
		s = 0;
		--l,--r;
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i = 0; i < m; i++)
		{
			scanf("%d",&w);
			for(int j = 0; j< n; j++)
				dp[!s][j] = dp[s][(j+w)%n]*0.5+dp[s][(j-w+n)%n]*0.5;
			s=!s;
		}
		double ans = 0;
		for(int i = l; i <= r; i++)
			ans+=dp[s][i];
		printf("%.4f\n",ans);
	}
	return 0;
}
