#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 3005;
const int INF = 1111111111;
typedef long long LL;
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	LL x,y;
	Point(){}
	Point(LL a,LL b):x(a),y(b){}
	Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
	bool operator <(const Point &a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	}
	bool operator==(const Point&a)const
	{
		return x==a.x&&y==a.y;
	}
	void input(){scanf("%lld%lld",&x,&y);}
};
typedef Point Vector;
struct Seg{
	Point s,t;
	Seg(){}
	Seg(Point x,Point y):s(x),t(y){}
	void input()
	{
		s.input();
		t.input();
	}
	bool operator <(const Seg &a)const
	{
		return s<a.s||(s==a.s&&t<a.t);
	}
	bool operator==(const Seg&a)const
	{
	    return s==a.s&&t==a.t;
	}
}line[MAXN];

inline LL cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
inline LL dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double dist(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline bool onseg(Point p, Point a, Point b)
{
	return dcmp(dist(a,p)+dist(p,b)-dist(a,b))==0;
}
inline bool isaline(Point a,Point b,Point c, Point d)
{
	if(cross(a-b,c-d)==0&&onseg(c,a,b)) return 1;
	return 0;
}

inline bool isinter(Point s1, Point e1, Point s2, Point e2){
    if( min(s1.x, e1.x) <= max(s2.x, e2.x) &&
        min(s1.y, e1.y) <= max(s2.y, e2.y) &&
        min(s2.x, e2.x) <= max(s1.x, e1.x) &&
        min(s2.y, e2.y) <= max(s1.y, e1.y) &&
        dcmp((double)cross(s2-s1,e2-s1))*dcmp((double)cross(s2-e1,e2-e1))<=0&&
        dcmp((double)cross(s1-s2,e1-s2))*dcmp((double)cross(s1-e2,e1-e2))<=0)
        return true;
    return false;
}
inline bool getinter(Point a,Vector aa,Point b,Vector bb,Point &p)
{
	Vector u = a-b;
	LL x = cross(bb,u),y = cross(aa,bb);
	if((aa.x*x)%y!=0||(aa.y*x)%y!=0) return 0;
	p = a+Point(aa.x*x/y,aa.y*x/y);
	return 1;
}
set<Point> st;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	//freopen("/home/qitaishui/code/out1.txt","w",stdout);
	int n,m;
	bool vis[MAXN];
	Point p;
	LL ans;
	while(scanf("%d",&n)!=EOF)
	{
		ans = 0;
		m = 0;
		memset(vis,0,sizeof(vis));
		st.clear();
		for(int i = 0; i < n; i++)
		{
			line[i].input();
			if(line[i].t<line[i].s) swap(line[i].s,line[i].t);
		}
		sort(line,line+n);
		//n = unique(line,line+n)-line;
		for(int i = 0; i < n; i++)
		{
			if(vis[i]) continue;
			vis[i] = 1;
			line[m] = line[i];
			for(int j = i+1; j<n; j++)
			{
				if(!vis[j]&&isaline(line[m].s,line[m].t,line[j].s,line[j].t))
				{
					line[m].t = max(line[m].t,line[j].t);
					vis[j] = 1;
				}
			}
			m++;
		}
		for(int i = 0; i < m; i++)
		{
			ans+=(int)__gcd(abs(line[i].s.x-line[i].t.x),abs(line[i].s.y-line[i].t.y))+1;
			st.clear();
			for(int j = i+1; j < m; j++)
			{
				if(isinter(line[i].s,line[i].t,line[j].s,line[j].t)
					&&getinter(line[i].s,line[i].t-line[i].s,line[j].s,line[j].t-line[j].s,p))
					st.insert(p);
			}
			ans-=st.size();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
