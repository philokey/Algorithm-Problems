#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const double EPS = 1e-6;
const int MAXN = 400005;
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
double sqr(double x){return x*x;}
struct Circle{
	double x,y,r;
}c[MAXN];
struct Line{
	double x,y;
	int id,tp;
	bool operator<(const Line &a)const
	{
		return x<a.x;
	}
}l[MAXN*2];
double xx;
struct Node{
	int id, tp;
	double gy()const
	{
		double dis = sqrt(sqr(c[id].r)-sqr(c[id].x-xx));
		if(tp == 0) return c[id].y - dis;
		return c[id].y + dis;
	}
	bool operator < (const Node &a)const
	{
		double t1 = gy(),t2 = a.gy();
		if(dcmp(t1-t2)) return dcmp(t1-t2)<0;
		if(id!=a.id) return id < a.id;
		return tp < a.tp;
	}
}node;
set<Node> st;
set<Node>::iterator pre, now, nxt;
int ln,ans[MAXN];
void add(Circle c,int id)
{
	l[ln].x = c.x-c.r;
	l[ln].id = id;
	l[ln++].tp = 0;

	l[ln].x = c.x+c.r;
	l[ln].id = id;
	l[ln++].tp = 1;
}
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		ln = 0;
		st.clear();
		memset(ans,0,sizeof(ans));
		for(int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf",&c[i].r,&c[i].x,&c[i].y);
			add(c[i],i);
		}
		sort(l,l+ln);
		for(int i = 0; i < ln; i++)
		{
			node.id = l[i].id;
			if(l[i].tp)
			{
				node.tp = 0;
				st.erase(node);
				node.tp = 1;
				st.erase(node);
			}
			else
			{
				xx = l[i].x;
				node.tp = 0;
				st.insert(node);
				pre = now = nxt = st.find(node);
				nxt++;
				if(pre==st.begin()||nxt == st.end())
					ans[node.id] = 1;
				else
				{
					pre--;
					int id1 = pre->id, id2 = nxt->id;
					if (id1 == id2)
						ans[node.id] = ans[id1] + 1;
					else
						ans[node.id] = max(ans[id1], ans[id2]);
				}
				node.tp = 1;
				st.insert(node);
			}
		}
		vector<int> ve;
		ve.clear();
		for(int i = 0; i < n; i++)
			if(ans[i]==1) ve.push_back(i+1);
		printf("%d\n",ve.size());
		for(int i = 0; i < ve.size(); i++)
			if(i==0) printf("%d",ve[i]);
			else printf(" %d",ve[i]);
		printf("\n");
	}
	return 0;
}
