#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
const double EPS = 1e-9;
const int MAXN = 2005;
const double INF = 1e50;
const double PI = acos(-1.0);
inline int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0?-1:1;
}
inline double sqr(double x){return x*x;}
struct Edge{
    int v,next;
    double w;
}edge[MAXN*1005];
int head[MAXN],en;
void addedge(int u,int v,double w)
{
    edge[en].v = v,edge[en].w = w;
    edge[en].next = head[u];
    head[u] = en++;
    swap(u,v);
    edge[en].v = v,edge[en].w = w;
    edge[en].next = head[u];
    head[u] = en++;
}

double spfa(int s,int t)
{
	double dist[MAXN];
	bool vis[MAXN]={0};
    int u,v;
    queue<int>q;
    for(int i = 0; i < MAXN; i++) dist[i] = INF;
    dist[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        u = q.front();q.pop();
        vis[u] = 0;
        for(int i = head[u]; i!= -1; i=edge[i].next)
        {
            v = edge[i].v;
            if(dist[v]>dist[u]+edge[i].w)
            {
                dist[v] = dist[u]+edge[i].w;
                if(!vis[v]) vis[v] = 1, q.push(v);
            }
        }
    }
    return dist[t];
}
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(double k)const{return Point(x*k,y*k);}
    Point trunc(double d)
    {
        double len = sqrt(x*x+y*y);
        return Point(x*d/len,y*d/len);
    }
    bool operator==(const Point&a)const
    {
        return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
    }
    bool operator<(const Point&a)const
    {
        return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
    }
    void input(){scanf("%lf%lf",&x,&y);}
}p[100005];
typedef Point Vector;
struct Circle{
    Point o;
    double r;
    Circle(){}
    Circle(Point a,double b):o(a),r(b){}
    Point point(double a)
    {
        return Point(o.x+cos(a)*r,o.y+sin(a)*r);
    }
}c[55];
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
    return sqrt(a.x*a.x+a.y*a.y);
}
Vector rotate(Vector a,double rad)
{
    Vector c;
    c.x = a.x*cos(rad)-a.y*sin(rad);
    c.y = a.x*sin(rad)+a.y*cos(rad);
    return c;
}
int inter_c_and(Circle c1,Circle c2,Point &p1,Point &p2)
{
	Vector v = c2.o-c1.o;
	double len = length(v);
	if(dcmp(len-c1.r-c2.r)>0) return 0;

	double s = (sqr(c1.r)-sqr(c2.r)+sqr(len))/len/2;
	double h = sqrt(sqr(c1.r)-sqr(s));
	Point p0 = c1.o+v.trunc(s);

	p1 = p0+rotate(v,PI/2).trunc(h);
	p2 = p0-rotate(v,PI/2).trunc(h);
	return 1;
}
inline bool onseg(Point p,Point a,Point b)
{
    return dcmp(length(a-p)+length(p-b)-length(a-b))==0;
}
void inter_c_seg(Circle c,Point a,Point b,vector<pair<Point,Point> >&sol)
{
	Vector v = b-a;
    double A = sqr(v.x)+sqr(v.y);
    double B = 2*(v.x*(a.x-c.o.x)+v.y*(a.y-c.o.y));
    double C = sqr(a.x-c.o.x)+sqr(a.y-c.o.y)-sqr(c.r);
    double delta = sqr(B)-4*A*C;
    Point p1,p2,t1,t2;
    if(dcmp(delta)<=0) return ;
    double k1 = (-B-sqrt(delta))/(2*A);
    double k2 = (-B+sqrt(delta))/(2*A);
    p1 = a+v*k1;
    p2 = a+v*k2;
    bool f1 = onseg(p1,a,b),f2 = onseg(p2,a,b);
    if(f1&&f2)
    {
        if(p1<p2) sol.push_back(MP(p1,p2));
        else sol.push_back(MP(p2,p1));
    }
    else if(f1||f2)
    {
    	if(f2) p1 = p2;
    	if(dcmp(length(a-c.o)-c.r)<0)
		{
			t1 = min(a,p1),t2 = max(a,p1);
			sol.push_back(MP(t1,t2));
		}
        else if(dcmp(length(b-c.o)-c.r)<0)
		{
			t1 = min(b,p1),t2 = max(b,p1);
			sol.push_back(MP(t1,t2));
		}
		else sol.push_back(MP(p1,p1));
    }
    else if(dcmp(length(a-c.o)-c.r)<0&&dcmp(length(b-c.o)-c.r)<0)
	{
		if(a < b) sol.push_back(MP(a,b));
		else sol.push_back(MP(b,a));
	}
}
bool judge(vector<pair<Point,Point> >&sol)
{
    int n = sol.size();
    Point se = sol[0].SE;
    bool flag=1;
    for(int i = 1; i < n;i++)
    {
        if(sol[i].FI<se||se==sol[i].FI) se = max(se,sol[i].SE);
        else{flag=0;break;}
    }
    return flag;
}
int main()
{
    int cas;
    int n,m,s,t;
    Point ps,pt;
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas; ca++)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            p[i].input();
            scanf("%lf",&c[i].r);
            c[i].o = p[i];
        }
        m = n;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
            {
                double tmp = length(c[i].o-c[j].o);
                if(dcmp(tmp-c[i].r-c[j].r)>0||dcmp(tmp-fabs(c[i].r-c[j].r))<0)
                    continue;
                inter_c_and(c[i],c[j],p[m],p[m+1]);
                m+=2;
            }
        ps = p[0],pt = p[n-1];
        sort(p,p+m);
        m = unique(p,p+m)-p;
        for(int i = 0; i < m; i++)
        {
            if(p[i]==ps) s = i;
            if(p[i]==pt) t = i;
        }
        vector<pair<Point,Point> >sol;
        memset(head,-1,sizeof(head));
        en = 0;
        for(int i = 0; i < m; i++)
            for(int j = i+1; j < m; j++)
            {
                sol.clear();
                for(int k = 0; k < n; k++)
                    inter_c_seg(c[k],p[i],p[j],sol);
                sort(sol.begin(),sol.end());

                if(judge(sol))
					addedge(i,j,length(p[i]-p[j]));
            }
        double ans = spfa(s,t);
        printf("Case %d: ",ca);
        if(dcmp(ans-INF)==0) printf("No such path.\n");
        else printf("%.4f\n",ans+EPS);
    }
    return 0;
}
