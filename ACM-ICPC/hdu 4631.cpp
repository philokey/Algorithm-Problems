#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
#define MP make_pair
typedef long long LL;
using namespace std;
const double EPS = 1e-8;
const int MAXN = 800005;
const int INF = 1111111111;
int n;
pair<int,int> pa;

struct Point{
	int x,y;
	int id;
	Point(){};
	Point(int a,int b,int id):x(a),y(b){}
};
Point p[MAXN],pp[MAXN],q[MAXN];
bool cmp1(const Point &a,const Point &b)
{
	return a.x<b.x||(a.x-b.x==0&&a.y<b.y);
}
bool cmp2(const Point &a,const Point &b)
{
	return a.y<b.y;
}
LL dist(Point a, Point b)
{
	return (LL)(a.x-b.x)*(a.x-b.x)+(LL)(a.y-b.y)*(a.y-b.y);
}
LL dd;
void solve(int l,int r)
{
    long long d = (LL)1<<62;
    if(l>=r) return;
    if(l+1==r)
	{
		d = dist(p[l],p[r]);
		if(dd>d)
			pa = MP(p[l].id,p[r].id),dd = d;
		return;
	}
    int m = (l+r)/2;
    solve(l,m); solve(m+1,r);
    int k = 0;
    for(int i = l; i <= r; i++)
    {
        if(fabs(p[m].x-p[i].x) <= dd)
            q[k++] = p[i];
    }
    sort(q,q+k,cmp2);
    for(int i = 0; i < k; i++)
        for(int j = i+1; j < k && (LL)(q[j].y-q[i].y)*(q[j].y-q[i].y)<d; j++)
		{
			d = dist(q[i],q[j]);
			if(dd > d)
			{
				dd = d;
				pa = MP(q[i].id,q[j].id);
			}
		}
}

int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	int pos,tmp;
	LL a1,a2,b1,b2,c1,c2,ans;
	scanf("%d",&cas);
	while(cas--)
	{
		cin>>n>>a1>>b1>>c1>>a2>>b2>>c2;
		pp[0] = Point(0,0,0);
		for(int i = 1; i <= n; i++)
		{
			pp[i].x = (a1*pp[i-1].x+b1)%c1;
			pp[i].y = (a2*pp[i-1].y+b2)%c2;
			pp[i].id = i;
		}
		pos = n;
		ans = 0;

		while(pos>1)
		{
			dd = (LL)1<<62;
			for(int i = 0; i < pos; i++) p[i] = pp[i+1];
			sort(p,p+pos,cmp1);
			solve(0,pos-1);
			tmp = max(pa.FI,pa.SE);
			ans+=dd*(pos-tmp+1);
			pos = tmp-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
