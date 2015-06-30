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
const int MAXN = 3005;
const int INF = 1111111111;
int sg[205],n;
int get_sg(int u)
{
	if(sg[u]!=-1) return sg[u];
	bool vis[205]={0};
	for(int i = 0; i <= u-2; i++)
	{
		sg[i] = get_sg(i);
		sg[u-i-2] = get_sg(u-i-2);
		vis[sg[i]^sg[u-i-2]]=1;
	}
	for(int i = 0; i < 10; i++)
		if(vis[i]==0) return i;

}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	//freopen("/home/qitaishui/code/out.txt","w",stdout);
	int cas;
	memset(sg,-1,sizeof(sg));
	sg[0] = 0,sg[1] = 0,sg[2] = 1;
	for(int i = 0; i <= 200; i++)
		get_sg(i);
	scanf("%d",&cas);
	int ret,u;
	while(cas--)
	{
		scanf("%d",&n);
		ret = 0;
		while(n--)
		{
			scanf("%d",&u);
			if(u<86) ret^=sg[u];
			else ret^=sg[u%34+68];
		}
		if(ret==0) printf("Dave\n");
		else printf("Carol\n");
	}
	return 0;
}
