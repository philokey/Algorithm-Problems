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
const int MAXN = 2005;
const int INF = 1111111111;
//int sg[MAXN][MAXN];
int n,m;
//void dfs(int x,int y)
//{
//	if(sg[x][y]!=-1) return;
//	bool vis[10] = {0};
//	if(x+1<=n) dfs(x+1,y),vis[sg[x+1][y]]=1;
//	if(y-1>0) dfs(x,y-1),vis[sg[x][y-1]]=1;
//	if(x+1<=n&&y-1>0) dfs(x+1,y-1),vis[sg[x+1][y-1]]=1;
//
//	for(int i = 0; i < 10; i++)
//		if(!vis[i]) {sg[x][y] = i;return ;}
//}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		if((n%2&&m%2)) printf("What a pity!\n");
		else printf("Wonderful!\n");
	}
	return 0;
}
