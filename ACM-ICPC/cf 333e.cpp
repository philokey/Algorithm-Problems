#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 3005;
const int INF = 1111111111;
struct Point{
	int x,y;
	void input(){scanf("%d%d",&x,&y);}
}p[MAXN];
struct Node{
	int u,v,d;
	Node(){}
	Node(int a,int b,int c):u(a),v(b),d(c){}
	bool operator <(const Node&a)const
	{
		return d>a.d;
	}
}seg[MAXN*MAXN];
bitset<MAXN> bit[MAXN],tmp;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m=0,u,v,ans;
	scanf("%d",&n);
	for(int i = 0; i < n;i++)
		p[i].input();
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			seg[m++] = Node(i,j,(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
	sort(seg,seg+m);
	//cout<<"*\n";
	for(int i = 0; i < m; i++)
	{
		u = seg[i].u,v = seg[i].v;
		tmp = bit[u]&bit[v];
		//cout<<u<<endl;
		if(tmp.any())
		{
			ans = seg[i].d;
			break;
		}
		bit[u].set(v);
		bit[v].set(u);
	}
	//cout<<ans<<endl;
	printf("%.10f\n",sqrt(1.0*ans)/2);
	return 0;
}
