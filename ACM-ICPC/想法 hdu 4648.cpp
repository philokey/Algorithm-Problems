#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 100005;
const int INF = 1111111111;
long long sum[MAXN];
map<int,int>mp;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m,ans,u;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		mp.clear();
		ans = 0;
		mp[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&u);
			sum[i] = sum[i-1]+u;
		}
		for(int i = 1;i <= n;i++)
		{
			sum[i]%=m;
			if(sum[i]<0) sum[i] = m+sum[i];
			if(mp.find(sum[i])!=mp.end())
				ans = max(ans,i-mp[sum[i]]);
			else mp[sum[i]] = i;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
