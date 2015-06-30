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
const int MAXN = 5005;
const int INF = 1111111111;
int n,num[MAXN],q[MAXN],cnt[MAXN],ans[MAXN];
bool vis[MAXN];
bool dfs(int u,int h,int t)
{
	for(int i = u; i < n ;i++)
	{
		if(h == t||num[i]!=q[h])
			q[t++]=num[i],ans[i]=0;
		else if(vis[i]==1)
		{
			ans[i] = 1;
			if(dfs(i+1,h+1,t)) return 1;
			q[t++] = num[i];
			ans[i] = 0;
			if(dfs(i+1,h,t+1)) return 1;
		}
		else h++,ans[i] = 1;
	}
	if(h==t) return 1;
	return 0;

}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int ca;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&num[i]);
		}
		for(int i = n-1; i >=0; i--)
		{
			cnt[num[i]]++;
			if(cnt[num[i]]==3) vis[i] = 1;
		}

		dfs(0,0,0);
		for(int i = 0; i < n; i++)
			printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}
