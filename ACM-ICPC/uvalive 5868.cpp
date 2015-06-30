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
const int MAXN = 350005;
const double INF = 1e60;
const int MOD = 1000;
int dcmp(double x)
{
	if(fabs(x)==0) return 0;
	return x<0?-1:1;
}
struct Node{
	int s,g,id,x;
};
struct Point{
	double x,y;
	int id;
	bool operator <(const Point&a)const
	{
		return dcmp(x-a.x)>0||(dcmp(x-a.x)==0&&dcmp(y-a.y)>0);
	}
};
Node s[MAXN],node[MAXN];
int c[MAXN];
int n,t;
double h[MAXN];
bool cmp0(const Node&a,const Node&b)
{
	return a.x>b.x;
}
bool cmp(const Node&a,const Node&b)
{
	return a.g>b.g;
}
int lowbit(int x)
{
	return x&(-x);
}
void update(int x)
{
	while(x<=n)
	{
		c[x]+=1;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int ret = 0;
	while(x>0)
	{
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}
Point get(int i ,int j)
{
	Point p;
	p.id = j;
	if(node[i].s>=node[j].s)
	{
		p.x = p.y = INF;
	}
	else
	{
		p.x = ((double)node[j].g-node[i].g)/(node[i].s-node[j].s);
		p.y = node[i].s*p.x+node[i].g;
	}
	h[node[j].id]=p.x;
	return p;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d",&n,&t);
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d",&node[i].g,&node[i].s);
			node[i].id = i+1;
			node[i].x = node[i].s*t+node[i].g;
		}
		int ans = 0;
		sort(node,node+n,cmp0);
		memset(c,0,sizeof(c));
		for(int i = 0; i <n ;i++)
		{
			int u = node[i].id;
			ans+=query(u);
			ans%=MOD;
			update(u);
		}
		printf("%d\n",ans);
		sort(node,node+n,cmp);
		priority_queue<Point> q;
		for(int i = 0; i < n-1; i++)
			q.push(get(i,i+1));
		for(int i = 0; i < 10000&&!q.empty();)
		{
			Point u = q.top();q.pop();
			int id = u.id;
			if(u.x>t) break;
			if(dcmp(h[node[id].id]-u.x)!=0) continue;
			printf("%d %d\n",node[id].id,node[id-1].id);
			swap(node[id],node[id-1]);
			if(id+1<n)
			{
				Point v = get(id,id+1);
				q.push(v);
			}
			if(id-2>=0)
			{
				Point v = get(id-2,id-1);
				q.push(v);
			}
			i++;
		}
	}
	return 0;
}
