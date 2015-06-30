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
/*int sg[MAXN],k;
int p(int b)
{
	int ret=1;
	while(b--)
		ret*=k;
	return ret;
}
int get_sg(int u)
{
	if(sg[u]!=-1) return sg[u];
	bool vis[105] = {0};
	for(int i = 0; i < 30; i++)
	{
		int tmp = p(i);
		if(tmp<=u) vis[get_sg(u-tmp)] = 1;
		else break;
	}
	for(int i = 0; i < 1000; i++)
		if(!vis[i]) return sg[u] = i;
}
int main()
{
	freopen("/home/qitaishui/code/out.txt","w",stdout);
	memset(sg,-1,sizeof(sg));
	k = 18;
	sg[0] = 0;
	for(int i = 0; i < 100; i++)
		printf("%d %d\n",i,get_sg(i));
	return 0;
}*/
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	int n,k;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d",&n,&k);
		if(k%2)
		{
			if(n%2) printf("1\n");
			else printf("0\n");
		}
		else
		{
			k++;
			if(n%k==k-1) printf("%d\n",k-1);
			else if((n%k)%2) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
