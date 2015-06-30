#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 105;
int INF=15000000;
int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0? -1:1;
}
struct Point{
  double x,y;
  Point(){}
  Point(double a,double b):x(a),y(b){}
  Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
  Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
  void input(){scanf("%lf%lf",&x,&y);}
};
struct Line{
    Point a,b;
};
typedef Point Vector;
double Cross(Vector a, Vector b)
{
    return a.x*b.y-a.y*b.x;
}
double Dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}
double Dist(Vector a)
{
    return sqrt(Dot(a,a));
}
bool Ispinter(Point a,Point b,Point c,Point d)
{
    double c1 = Cross(b-a,c-a),c2 = Cross(b-a,d-a),
           c3 = Cross(d-c,a-c),c4 = Cross(d-c,b-c);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
int n,m,p,ord[MAXN],link[MAXN];
Point city[MAXN*3];
Line l[MAXN];
double dist[MAXN*3][MAXN*3];
bool g[MAXN][MAXN];
bool vis[MAXN];
bool dfs(int x)
{
	for(int i = 0; i< n; i++)
	{
		if(g[x][i]&&!vis[i])
		{
			vis[i] = 1;
			if(link[i]==-1||dfs(link[i]))
			{
				link[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
bool gao()
{
	int sum = 0;
	memset(link,-1,sizeof(link));
	for(int i = 0; i < n; i++)
	{
		memset(vis,0,sizeof(vis));
		sum+=dfs(i);
	}
	return n-sum<=p;
}
int main()
{

    int cas,cnt;

    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d%d",&n,&m,&p);
        for(int i = 0; i < n; i++)
            city[i].input();
        cnt = n;
        for(int i = 0; i < m; i++)
        {
            l[i].a.input(),l[i].b.input();
            city[cnt++] = l[i].a;
            city[cnt++] = l[i].b;
        }

        for(int i = 0;i < cnt; i++)
            for(int j = i+1; j < cnt; j++)
            {
                dist[i][j] = dist[j][i]= INF;
                bool flag = 1;
                for(int k = 0; k < m&&flag; k++)
                    if(Ispinter(city[i],city[j],l[k].a,l[k].b))
                        flag = 0;
                if(flag) dist[i][j] = dist[j][i]= Dist(city[i]-city[j]);
            }
        for(int i=0;i<cnt;++i)  dist[i][i]=0;
        double l=0,r=0,mid;
        for(int k = 0; k < cnt; k++)
            for(int i = 0; i < cnt; i++)
                for(int j = 0; j < cnt; j++)
				{
					dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
					if(dist[i][j]!=INF) r = max(dist[i][j],r);
				}
		int tmp;
        for(int i = 0; i < n; i++)
            scanf("%d",&tmp),ord[--tmp]=i;
		double ans;
		r+=1;
		while(r-l>EPS)
		{
			mid = (l+r)/2;
			memset(g,0,sizeof(g));
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					if(dcmp(dist[i][j]-mid)<=0&& ord[i]<ord[j]) g[i][j] = 1;

			if(gao()) ans = mid,r = mid-EPS;
			else l = mid+EPS;
		}
        printf("%.2f\n",l);
    }
    return 0;
}

