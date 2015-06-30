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
const int MAXN = 100005;
const int INF = 1111111111;
inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
	bool operator <(const Point &a)const
	{
		return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
	}
	bool operator==(const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN],ch[MAXN];
typedef Point Vector;
double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double dist2(Vector a)
{
	return dot(a,a);
}

int convehull(Point *p,int n,Point *ch)
{
	sort(p,p+n);
	n=unique(p,p+n)-p;
	int m = 0;
	for(int i = 0; i < n; i++)
	{
		while(m>1&&dcmp(cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-2; i>=0; i--)
	{
		while(m>k&&dcmp(cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) m--;
		ch[m++] = p[i];
	}
	if(n>1) m--;
	return m;
}
double rotatingcalipers(Point *p,int n)
{

	if(n==1) return 0;
	if(n==2) return dist2(p[0]-p[1]);
	p[n] = p[0];
	double ret = 0;
	for(int u = 0,v=1; u<n; u++)
	{
		while(1)
		{
			double diff = cross(p[u+1]-p[u],p[v+1]-p[u])-cross(p[u+1]-p[u],p[v]-p[u]);
			if(dcmp(diff)<=0)
			{
				ret = max(ret,dist2(p[u]-p[v]));
				if(dcmp(diff)==0) ret = max(ret,dist2(p[u]-p[v+1]));
				break;
			}
			v = (v+1)%n;
		}
	}
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		p[i].input();
	int m = convehull(p,n,ch);
	printf("%.0f\n",rotatingcalipers(ch,m));
	return 0;
}
