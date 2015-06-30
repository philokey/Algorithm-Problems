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
const int MAXN = 1005;
const int INF = 1111111111;
int g[MAXN][MAXN];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m,a,b,ans;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d",&g[i][j]);
	ans = 0;

	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
		{
			a = b = -1;
			for(int k = 0; k < m; k++)
			{
				if(g[i][k]>ans&&g[j][k]>ans)
				{
					int tmp = min(g[i][k],g[j][k]);
					if(tmp>a) b = a,a = tmp;
					else if(tmp>b) b = tmp;
				}
			}
			ans = max(ans,b);
		}
	printf("%d\n",ans);
	return 0;
}
