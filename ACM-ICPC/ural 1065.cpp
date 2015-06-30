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
const double INF = 1e50;
double d[MAXN][MAXN];
bool g[MAXN][MAXN];
inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point&a){return Point(x+a.x,y+a.y);}
	Point operator-(const Point&a){return Point(x-a.x,y-a.y);}
	void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN],h[MAXN];
typedef Point Vector;
inline double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
inline double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
inline double length(Vector a)
{
	return sqrt(dot(a,a));
}
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m;
	double dp[MAXN][MAXN];
	scanf("%d%d",&n,&m);
	for(int i = 0; i<n; i++)
		p[i].input();
	for(int i = 0; i<m; i++)
		h[i].input();
	for(int i = 0; i<=n; i++)
			dp[i][i] = 0;
	memset(g,0,sizeof(g));
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
		{
			if(i==j) continue;
			bool flag=1;
			for(int k = 0; k<m; k++)
				if(dcmp(cross(p[j]-p[i],h[k]-p[i]))>0){flag=0;break;}
			if(flag) d[i][j] = length(p[i]-p[j]),g[i][j] = 1;
			dp[i][j] = INF;
		}
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < i+n; j++)
			for(int k = i; k < j; k++)
				if(dp[i][k%n]<INF&&g[k%n][j%n])
					dp[i][k%n] = min(dp[i][j%n],dp[i][k%n]+d[k%n][j%n]);

     double ans = INF;
     for (int i = 0; i < n; i++)
         for (int j = 0; j < m; j++)
             for (int k = j+1; k < m; k++)
				if(dp[i][j%n]<INF&&g[j%n][k%n]&&g[k%n][i])
					ans = min(ans,dp[i][j%n]+d[j%n][k%n]+d[k%n][i]);
	printf("%.2f\n",ans);
	return 0;
}
