/*
题意：给定平面上的两种点a和b，每个点有权值，要求画一条直线，并删除一些点，使得直线的每一侧只有一类点，并且删除的权值之和最小。
解法：枚举每一个点为中心，用atan2进行极角排序。再扫一遍中心点和每个点的连线，连线为射线，可以计算射线的反向延长线的极角。统计在这条直线一侧的两种点的个数（射线上的点包括端点算在内，延长线上的点不算），就可以计算出以这条直线分割的代价。扫下一条射线时，要把在当前射线上的点权删除。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-10;
const int MAXN = 40005;
const int INF = 1111111111;
const double PI = acos(-1.0);
inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0? -1:1;
}
struct Point{
	double x,y;
	int val,tp;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	void input()
	{
		scanf("%lf%lf%d",&x,&y,&val);
	}
}p[MAXN];
struct Node{
	int val,tp;
	double ang;
	Node(){}
	Node(int a,int b,double c)
	{
		val = a,tp = b;
		ang = c;
	}
	bool operator <(const Node&a)const
	{
		return dcmp(ang-a.ang)<0;
	}
}node[MAXN];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m,sv[2],ans;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		sv[0] = sv[1] =0;
		for(int i = 0; i < n+m; i++)
		{
			p[i].input();
			p[i].tp = (i>=n);
			sv[p[i].tp]+=p[i].val;
		}
		ans = min(sv[0],sv[1]);
		n+=m;
		//cout<<ans<<"**\n";
		for(int i = 0; i < n; i++)
		{
			m = 0;
			for(int j = 0; j < n; j++)
			{
				if(i==j) continue;
				double tmp = atan2(p[j].y-p[i].y,p[j].x-p[i].x);
				node[m++] = Node(p[j].val,p[j].tp,tmp);
			}
			sort(node,node+m);
			for(int j = 0; j < m; j++)
			{
				node[m+j] = node[j];
				node[m+j].ang+=2*PI;
			}

			int l,r,x[2];
			l=r=x[0]=x[1]=0;

			while(l < m)
			{
				while(dcmp(PI+node[l].ang-node[r].ang)>0)
				{
					x[node[r].tp]+=node[r].val;
					r++;
				}
				ans = min(ans,x[0]+sv[1]-x[1]);
				double tmp = node[l].ang;
				while(dcmp(tmp-node[l].ang)==0)
				{
					x[node[l].tp]-=node[l].val;
					l++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
