#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
pair<int,int> pa[5][105][105],a[4005];

int si[4005],s,cnt;
void solve(int x,int y)
{
	pair<int,int> tmp;
	for(int i = 0; i < s;i++)
	{
		tmp = pa[si[i]][x][y];
		x = tmp.first, y = tmp.second;

	}
	a[cnt++] = tmp;
}
int main()
{

	int n,m;
	cnt = 0;
	scanf("%d%d",&n,&m);
	for(int k = 1; k < 5;k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d%d",&pa[k][i][j].first,&pa[k][i][j].second);
	scanf("%d",&s);
	int q,u,v;
	for(int i = 0; i < s; i++)
		scanf("%d",&si[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			solve(i,j);

	sort(a,a+cnt);
	cnt = unique(a,a+cnt)-a;

	printf("%d\n",cnt);
	for(int i = 0; i < cnt; i++)
		printf("%d %d\n",a[i].first,a[i].second);
	return 0;
}
