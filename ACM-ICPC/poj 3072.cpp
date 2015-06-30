#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-12;
const int MAXN = 25;
const double INF = 1e60;
const double PI = acos(-1.0);
double dist[MAXN][MAXN],g[MAXN][MAXN];
inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
	bool operator==(const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN];
typedef Point Vector;
int n;
inline double angle(Point a,Point b,Point c)
{
	double ret = fabs(atan2(b.y-a.y,b.x-a.x)-atan2(c.y-b.y,c.x-b.x));
	ret = fabs(ret)*180/PI;
	if(ret>180) ret=360-ret;
	return ret;
}

void spfa(int s,double r)
{
	queue<pair<int,int> >q;
	bool vis[MAXN][MAXN];
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			dist[i][j] = INF,vis[i][j]=0;
	for(int i = 1; i < n; i++)
	{
		if(dcmp(g[0][i]-r)>0) continue;
		double tmp = angle(p[n],p[0],p[i]);
		dist[i][0] = g[0][i]+tmp;
		q.push(make_pair(i,0));
		vis[i][0] = 1;
	}
	while(!q.empty())
	{
		int u = q.front().FI,x = q.front().SE;

		q.pop();vis[u][x] = 0;
		double tmp=INF,ang;
		for(int i = 0; i < n; i++)
		{
			if(i==u||dcmp(g[u][i]-r)>0) continue;
			ang = angle(p[x],p[u],p[i]);
			if(dist[i][u]>dist[u][x]+ang+g[u][i])
			{
				dist[i][u]=dist[u][x]+ang+g[u][i];
				if(!vis[i][u])
					q.push(make_pair(i,u)),vis[i][u]=1;
			}
		}
	}
}
int main()
{
	//freopen("/home/qitaishui/code/out.txt","r",stdin);
    //freopen("/home/qitaishui/code/out2.txt","w",stdout);
	double r;
	while(scanf("%lf%d",&r,&n)&&n!=-1)
	{
		for(int i = 0; i < n; i++)
			p[i].input();
		if(p[0]==p[n-1])
		{
			printf("0\n");
			continue;
		}
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				g[i][j] = g[j][i] = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+
											(p[i].y-p[j].y)*(p[i].y-p[j].y));
		p[n] = p[0]+(p[0]-p[n-1]);
		spfa(0,r);
		double ans = INF;
		for(int i = 0; i < n; i++)
			ans = min(dist[n-1][i],ans);
		if(dcmp(ans-INF)==0) printf("impossible\n");
		else printf("%.d\n",int(ans+0.5));
	}
	return 0;
}
