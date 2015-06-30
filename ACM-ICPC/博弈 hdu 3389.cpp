/*
题意：给n个盒子编号1到n，每个盒子里有一定数量的球，第a个盒子可以移动到b当且仅当b<a&&(a+b)%2==1&&(a+b)%3==0，每次可以移动非零的任意个。问先手赢还是后手赢。
解法：由sg函数可知，sg值为1,0,1,0,0,1的循环，可以转化为NIM博弈
*/
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
//int sg[MAXN];
//int get_sg(int u)
//{
//	if(sg[u]!=-1) return sg[u];
//	int vis[100]={0};
//	for(int i = 1; i < u; i++)
//		if((i+u)%2&&(i+u)%3==0) vis[get_sg(i)] =1;
//	for(int i = 0; i < 100; i++)
//		if(!vis[i]) return sg[u] = i;
//}
//int main()
//{
//	freopen("/home/qitaishui/code/out.txt","w",stdout);
//	memset(sg,-1,sizeof(sg));
//	for(int i = 1; i < 500; i++)
//		printf("%d ",get_sg(i));
//	return 0;
//}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int sg[]={1,0,1,0,0,1};
	int cas;
	int a,n,ans;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		ans = 0;
		printf("Case %d: ",ca);
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&a);
			ans^=a*sg[i%6];
		}
		if(ans) printf("Alice\n");
		else printf("Bob\n");

	}
}
