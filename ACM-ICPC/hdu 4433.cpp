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
char sta[MAXN],stb[MAXN];
int a[MAXN],b[MAXN],dp[MAXN][11][11];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	while(scanf("%s%s",sta,stb)!=EOF)
	{
		n = strlen(sta);
		for(int i = 0; sta[i]; i++)
			a[i+1] = sta[i]-'0',b[i+1] = stb[i]-'0';
		memset(dp,0x3f,sizeof(dp));
		dp[0][a[1]][a[2]] = 0;
		a[n+2] = a[n+1] = b[n+2] = b[n+1] = 0;
		for(int i = 1; i <= n;i++)
			for(int x = 0; x<10; x++)
				for(int y = 0; y<10; y++)
				{
					int down = (b[i]-x+10)%10;
					for(int j = 0; j<= down; j++)
						for(int k = 0; k<=j; k++)
							dp[i][(y+j)%10][(a[i+2]+k)%10] = min(dp[i][(y+j)%10][(a[i+2]+k)%10],
																dp[i-1][x][y]+down);
					int up = 10-down;
					for(int j = 0; j<=up; j++)
						for(int k = 0; k<=j; k++)
							dp[i][(y-j+10)%10][(a[i+2]-k+10)%10] = min(dp[i][(y-j+10)%10][(a[i+2]-k+10)%10]
																		,dp[i-1][x][y]+up);
				}
		printf("%d\n",dp[n][0][0]);
	}
	return 0;
}
