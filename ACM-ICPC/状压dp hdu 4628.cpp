#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
const int INF = 111111111;
char str[55];
int dp[1<<19],n;
bool is[1<<19];

void init()
{
	memset(is,0,sizeof(is));
	char s[35];
	int len=0;
	bool flag;
	for(int i = 1; i < (1<<n); i++)
	{
		len = 0;
		flag = 1;
		for(int j = 0; j < n; j++)
			if((1<<j)&i) s[len++] = str[j];
		for(int j = 0, jj = len-1; j<jj&&flag; j++,jj--)
			if(s[j]!=s[jj]) flag = 0;
		is[i] = flag;
	}
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%s",str);
		n = strlen(str);
		init();
		for(int i = 1; i < (1<<n); i++)
		{
			dp[i] = INF;
			for(int j = i; j >0; j = (j-1)&i)
				if(is[j])  dp[i] = min(dp[i],dp[i^j]+1);

		}
		cout<<dp[(1<<n)-1]<<endl;
	}
	return 0;
}
