#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-6;
const int maxn = 6005;
struct Point{
	double x,y;
}pos;
double ui[maxn],li[maxn],x1,yy1,x2,y2;
int n,m,ans[maxn];
double mult(Point sp, Point ep, Point op)
{
	return (sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y);
}
void solve(Point pos)
{
	int l = 0,r = n+1;
	Point a,b;
	a.y = yy1, b.y = y2;
	while(l<=r)
	{
		int m = (l+r)/2;
		a.x = ui[m], b.x = li[m];
		if(mult(a,b,pos)<eps) r = m-1;
		else l = m+1;
	}
	//cout<<l<<endl;
	ans[r]++;
}
int main()
{
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		scanf("%d%lf%lf%lf%lf",&m,&x1,&yy1,&x2,&y2);
		ui[0] = x1, li[0] = x1;
		ui[n+1] = x2, li[n+1] = x2;
		for(int i = 1; i <= n; i++)
			scanf("%lf%lf",&ui[i],&li[i]);
		memset(ans,0,sizeof(ans));
		for(int i = 0; i < m; i++)
		{
			scanf("%lf%lf",&pos.x,&pos.y);
			solve(pos);
		}
		for(int i = 0; i <= n; i++)
			printf("%d: %d\n",i,ans[i]);
		printf("\n");
	}
	return 0;
}
