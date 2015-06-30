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
int a[MAXN][MAXN],n;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool v[2][MAXN][MAXN];
pair<int,int>s[2];
int d[2];
bool solve(int w)
{
	int xx = s[w].FI+dir[d[w]][0],yy = s[w].SE+dir[d[w]][1];
	if(xx>=0&&xx<n&&yy>=0&&yy<n&&!v[w][xx][yy])
	{
		v[w][xx][yy] = 1;
		s[w] = make_pair(xx,yy);
		return 1;
	}
	if(w==0) d[w]=(d[w]+1)%4;
	else d[w] = (d[w]-1+4)%4;
	xx = s[w].FI+dir[d[w]][0],yy = s[w].SE+dir[d[w]][1];
	if(xx>=0&&xx<n&&yy>=0&&yy<n&&!v[w][xx][yy])
	{
		v[w][xx][yy] = 1;
		s[w] = make_pair(xx,yy);
		return 1;
	}
	return 0;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		scanf("%d%d%d",&s[0].first,&s[0].second,&d[0]);
		scanf("%d%d%d",&s[1].first,&s[1].second,&d[1]);
		bool f1,f0;
		f1 = f0 = 1;
		memset(v,0,sizeof(v));
		v[0][s[0].FI][s[0].SE] = 1;
		v[1][s[1].FI][s[1].SE] = 1;
		while((f1||f0)&&(s[0]!=s[1]))
		{
			if(f0) f0 = solve(0);
			if(f1) f1 = solve(1);
		}
		if(s[0]==s[1])
			printf("%d %d\n",s[0].FI,s[0].SE);
		else printf("-1\n");
	}
	return 0;
}
