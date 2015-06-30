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
typedef long long LL;
LL dp[25][25];
int num[25];
LL dfs(int l,int r,int e)
{
	if(l==-1) return r==0;
	if(!e&&dp[l][r]!=-1) return dp[l][r];
	int u = e?num[l]:9;
	LL res = 0;
	for(int i = 0; i <=u; i++)
		res+=dfs(l-1,(r+i)%10,e&&i==u);
	return e? res:dp[l][r] = res;
}
LL solve(LL n)
{
	int l = 0;
	if(n<0) return 0;
	while(n)
	{
		num[l++] = n%10;
		n/=10;
	}
	return dfs(l-1,0,1);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	LL a,b;
	scanf("%d",&cas);
	memset(dp,-1,sizeof(dp));
	for(int ca = 1; ca<=cas; ca++)
	{
		scanf("%I64d%I64d",&a,&b);
		cout<<"Case #"<<ca<<": "<<solve(b)-solve(a-1)<<"\n";
	}
	return 0;
}
