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
const int MAXN = 10005;
const int INF = 1111111111;
const double PI = acos(-1.0);
struct Node{
	int id;
	double d;
	Node(){}
	Node(int a,double b):id(a),d(b){};
	bool operator<(const Node&a)const
	{
		return d<a.d;
	}
}node;

struct Point{
	double x,y,r;
	void input(){scanf("%lf%lf",&x,&y);}
}p[1005];
inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
priority_queue<Node> q[1005];
double dist(Point a,Point b)
{
	double ret = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	if(ret<1) return 0;
	return min(ret,50.0);
}
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		p[i].input();
	for(int i = 0;i < n; i++)
		for(int j = i+1; j < n; j++)
		{
			double tmp = dist(p[i],p[j]);
			node=Node(j,tmp);
			q[i].push(node);
			node=Node(i,tmp);
			q[j].push(node);
		}
	bool vis[1005]={0};
	int mx;
	double val,ans=0;
	for(int i = 0; i < n; i++)
	{
		mx = -1;
		val = 0;
		for(int j = 0; j < n; j++)
		{
			if(vis[j]) continue;
			node = q[j].top();
			while(vis[node.id]&&dcmp(node.d-dist(p[j],p[node.id])-p[node.id].r)!=0)
			{
				q[j].pop();
				q[j].push(Node(node.id,dist(p[j],p[node.id])-p[node.id].r));
			}
			node = q[j].top();
			if(dcmp(node.d-val)>0)
				val = node.d,mx = j;
		}
		if(mx==-1) break;
		vis[mx] = 1;
		p[mx].r = val;
		ans+=val*val;
	}
	printf("%.4f\n",PI*ans);
	return 0;
}
