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
const int MAXN = 1005;
const int INF = 1111111111;
const double PI = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
	void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN];
struct Node{
	int id;
	double ang;
	Node(){}
	Node(int a,double b):id(a),ang(b){}
	bool operator<(const Node&a)const
	{
		return dcmp(ang-a.ang)<0;
	}
}node[MAXN*3];
typedef Point Vector;
inline double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}

int cnt[MAXN][MAXN],rig[MAXN][MAXN],n;
inline int gao(int a,int b,int c)
{
	if(cnt[a][b]-cnt[a][c]>0) return cnt[a][b]-cnt[a][c]-1;
	return n-1-(cnt[a][c]-cnt[a][b]+1);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	int m;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		scanf("%d",&n);
		for(int i = 0; i < n;i++)
			p[i].input();
		for(int i = 0; i < n;i++)
		{
			m = 0;
			for(int j = 0; j < n; j++)
			{
				if(i==j) continue;
				double tmp = atan2(p[j].y-p[i].y,p[j].x-p[i].x);
				node[m++] = Node(j,tmp);
			}
			sort(node,node+m);
			for(int j = 0; j < m; j++)
			{
				cnt[i][node[j].id] = n-1-j;
				node[m+j] = node[j];
				node[m+j].ang+=2*PI;
			}
			int l,r;
			l = r = 0;
			while(l < m)
			{
				while(dcmp(node[l].ang+PI-node[r].ang)>0) r++;
				rig[node[l].id][i] = r-l-1;
				rig[i][node[l].id] = n-2-(r-l-1);
				l++;
			}

		}
		scanf("%d",&m);
		printf("Case %d:\n",ca);
		int a,b,c,ans;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(dcmp(cross(p[c]-p[a],p[b]-p[a]))>0) swap(b,a);

            int ans=rig[a][b]+rig[b][c]+rig[c][a];
            ans+=gao(a,b,c)+gao(b,c,a)+gao(c,a,b);
            ans=ans+6-2*n;
            printf("%d\n",ans);
		}
	}
	return 0;
}
