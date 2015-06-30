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
const int MAXN = 105;
const int INF = 1111111111;
bool vis[MAXN][MAXN];
int ans[MAXN][MAXN];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m,tmp;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < m; i++)
		{
			tmp = i%n;
			ans[i][0]=tmp;
			vis[i][tmp]=1;
		}
		for(int i = 0; i < n; i++)
		{
			int s = (((m-1)%n)+1)%n;
			for(int j = 0; j < m; j++)
			{
				if(ans[j][0]!=i) continue;
				while(s%n==ans[j][0]) s++;
				ans[j][1] = s%n;
				vis[j][s%n] = 1;
				s++;
			}
		}
		int s;
		for(int i = 0; i < m; i++)
		{
			s = 0;
			for(int j = 2; j < n; j++)
			{
				while(vis[i][s]) s++;
				ans[i][j] = s;
				vis[i][s] = 1;
			}
		}
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(j==0) printf("%d",ans[i][j]+1);
				else printf(" %d",ans[i][j]+1);
			}
			printf("\n");
		}


	}
	return 0;
}
