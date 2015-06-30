#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const int maxn = 55;
const int inf = 111111111;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y,z,r;
	Point(){}
	Point(double a,double b,double c):x(a),y(b),z(c){}

}p[1005];
int n,m,k;
int g[maxn][maxn];
bool vis[maxn][maxn];
double dist(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

int solve(int x,int y)
{
	int ret;
	double minh=g[x][y],maxh=inf,d2,len;
	for(int i = 0; i < k; i++)
	{
		d2 = dist(p[i],Point(x,y,p[i].z));
		if(dcmp(d2-p[i].r)>0) return 0;
		len = sqrt(p[i].r*p[i].r-d2*d2+eps);

		//if(dcmp(p[i].z+len-minh)<0||dcmp(p[i].z-len-maxh)>0) return 0;

		minh = max(minh,p[i].z-len);
		maxh = min(maxh,p[i].z+len);

		if(dcmp(minh-maxh)>0) return 0;
	}

	ret = (int)floor(maxh+eps)-(int)ceil(minh-eps)+1;
	return ret;
}
int main()
{
	int x,y;
	double r;
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i =0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d",&g[i][j]);
	for(int i = 0; i < k; i++)
	{
		scanf("%d%d%lf",&x,&y,&p[i].r);
		x--,y--;
		vis[x][y] = 1;
		p[i].x=x,p[i].y=y,p[i].z=g[x][y];
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!vis[i][j])
				ans+=solve(i,j);
	printf("%d\n",ans);
	return 0;
}
