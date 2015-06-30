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
const int MAXN = 200005;
const int INF = 1111111111;
int a[MAXN];
struct Node{
	int l,id,x,y;
	bool operator<(const Node&a)const
	{
		return l<a.l||(l==a.l&&y<a.y);
	}
}node[MAXN];
int ret,px,py;
bool vis[MAXN];
void gao1(int i)
{
	if(vis[i-1]&&vis[i+1]) ret--;
	else if(!vis[i-1]&&!vis[i+1]) ret++;
}
void gao2(int i)
{
	if(vis[i-1]&&vis[i+1]) ret++;
	else if(!vis[i-1]&&!vis[i+1]) ret--;
}

void query(int x, int y, int flag)
{
    if (flag != 0)
	{
        for(int i = x; i < px; i++)
		{
			vis[a[i]] = 1;
			gao1(a[i]);
		}
        for(int i = py+1; i <= y; i++)
		{
			vis[a[i]] = 1;
			gao1(a[i]);
		}
        for(int i = px; i < x; i++)
		{
			vis[a[i]] = 0;
			gao2(a[i]);
		}
        for(int i = y+1; i<=py; i++)
		{
			vis[a[i]] = 0;
			gao2(a[i]);
		}
    }
     else
     {
        ret = 0;
		memset(vis,0,sizeof(vis));
		for(int i = x; i <= y; i++)
		{
			vis[a[i]] = 1;
			gao1(a[i]);
		}
    }
    px = x, py = y;
}

int main()
{
	//freopen("/home/qitaishui/code/1007.in","r",stdin);
	//freopen("/home/qitaishui/code/out","w",stdout);
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int q,cas,block,ans[MAXN];
	int n;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas;ca++)
	{
		scanf("%d%d",&n,&q);
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);

		block = sqrt(n*1.0);
		for(int i = 0; i < q; i++)
		{
			scanf("%d%d",&node[i].x,&node[i].y);
			node[i].id = i;
			node[i].l = node[i].x/block;
		}
		sort(node,node+q);
		for(int i = 0;i < q; i++)
		{
			query(node[i].x,node[i].y,i);
			ans[node[i].id]=ret;
		}
		for(int i = 0; i < q; i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
