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
const int MAXN = 35;
const int INF = 1111111111;
int n,qn;
int dp[1<<21],squ[1<<20];
struct Point{
	int x,y;
	Point(){}
	Point(int a,int b):x(a),y(b){}

	bool operator<(const Point&a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	}
	void input(){scanf("%d%d",&x,&y);}
}p[MAXN];
int dist(Point a,Point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	while(scanf("%d",&n)&&n!=-1)
	{
		Point x,y;
		for(int i = 0; i < n; i++)
			p[i].input();
		sort(p,p+n);
		qn = 0;
		int a,b,c,d;
		for(int i = 0; i<n; i++)
			for(int j = i+1; j<n; j++)
				for(int u = j+1; u<n; u++)
					for(int v = u+1; v<n; v++)
					{

						if(p[i].x!=p[j].x) continue;
						a = dist(p[i],p[j]);
						b = dist(p[j],p[v]);
						c = dist(p[u],p[v]);
						d = dist(p[u],p[i]);
						//printf("%d %d %d %d\n",a,b,c,d);
						if(a==b&&b==c&&c==d&&a)
							squ[qn++] = (1<<i)+(1<<j)+(1<<u)+(1<<v);
					}
		memset(dp,0,sizeof(dp));
		//printf("%d\n",qn);
		for(int i = 0; i<(1<<n); i++)
			for(int j = 0; j<qn; j++)
			{
				if(!(i&squ[j]))
					dp[i|squ[j]] = max(dp[i|squ[j]],dp[i]+4);
			}
		int ans = 0;
		for(int i = 0; i < (1<<n); i++)
			ans = max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}
