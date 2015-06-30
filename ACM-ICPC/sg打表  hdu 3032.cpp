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
int sg[1000];
int get_sg(int u)
{
	if(sg[u]!=-1) return sg[u];
	bool vis[205]={0};
	vis[0] = 1;
	for(int i = 1; i < u; i++)
	{

		sg[i] = get_sg(i);
		sg[u-i] = get_sg(u-i);
		vis[sg[i]]=1;
		vis[sg[i]^sg[u-i]]=1;
	}
	for(int i = 0; i < 200; i++)
		if(vis[i]==0) return i;
}
int main()
{
//	freopen("/home/qitaishui/code/in.txt","r",stdin);
//	memset(sg,-1,sizeof(sg));
//	sg[0] = 0,sg[1] = 1;
//	for(int i = 1; i <= 200; i++)
//		get_sg(i);
//	for(int i = 0; i < 100; i++)
//		printf("%d ",sg[i]);

	int cas,n,ans,u;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		ans = 0;
		while(n--)
		{
			scanf("%d",&u);

			if(u%4==2||u%4==1) ans^=u;
			else if(u%4==3) ans^=(u+1);
			else ans^=(u-1);
		}
		if(ans==0) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}



