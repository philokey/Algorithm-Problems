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
struct Node{
	double u,l;
	bool operator < (const Node &x)const
	{
		return u < x.u;
	}
}node[maxn];
double x1,yy1,x2,y2;
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
		a.x = node[m].u, b.x = node[m].l;
		if(mult(a,b,pos)<eps) r = m-1;
		else l = m+1;
	}
	//cout<<l<<endl;
	ans[r]++;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int b[maxn];
	while(scanf("%d",&n)&&n)
	{
		scanf("%d%lf%lf%lf%lf",&m,&x1,&yy1,&x2,&y2);
		node[0].u = x1, node[0].l = x1;
		node[n+1].u = x2, node[n+1].l = x2;
		for(int i = 1; i <= n; i++)
			scanf("%lf%lf",&node[i].u,&node[i].l);
		memset(ans,0,sizeof(ans));
		memset(b,0,sizeof(b));
		sort(node,node+n+2);
		for(int i = 0; i < m; i++)
		{
			scanf("%lf%lf",&pos.x,&pos.y);
			solve(pos);
		}
		for(int i = 0; i <= m; i++)
			b[ans[i]]++;
		printf("Box\n");
		for(int i = 1; i <= m; i++)
			if(b[i]) printf("%d: %d\n",i,b[i]);
	}
	return 0;
}
