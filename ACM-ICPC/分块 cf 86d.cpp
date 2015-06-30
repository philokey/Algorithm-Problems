#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
typedef long long LL;
const double EPS = 1e-8;
const int MAXN = 1000005;
const int MAXM = 200005;
const int INF = 1111111111;
int cnt[MAXN],a[MAXM];
LL ans[MAXM];
struct Node{
	int x,y,l,id;
	bool operator <(const Node&a)const
	{
		return l<a.l||(l==a.l&&y<a.y);
	}
}node[MAXM];
inline LL g(int i)
{
	return (LL)((cnt[a[i]]<<1)+1)*a[i];
}
inline LL f(int i)
{
	return (LL)(1-(cnt[a[i]]<<1))*a[i];
}
int px,py;
LL ret = 0;
int query(int x,int y,int p)
{

	if(!p)
	{
		for(int i = x; i <= y; i++)
		{
			ret+=g(i);
			cnt[a[i]]++;
		}
	}
	else
	{
		for(int i = x; i < px; i++)
		{
			ret+=g(i);
			cnt[a[i]]++;
		}
		for(int i = px; i < x; i++)
		{
			ret+=f(i);
			cnt[a[i]]--;
		}
		for(int i = y+1; i <= py; i++)
		{
			ret+=f(i);
			cnt[a[i]]--;
		}
		for(int i = py+1; i<=y; i++)
		{
			ret+=g(i);
			cnt[a[i]]++;
		}
	}
	px = x, py = y;
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,block,q;
	int u,v;
	scanf("%d%d",&n,&q);
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	block = sqrt(n*1.0);
	for(int i = 0; i < q; i++)
	{
		scanf("%d%d",&node[i].x,&node[i].y);
		node[i].l = node[i].x/block;
		node[i].id = i;
	}
	sort(node,node+q);

	for(int i = 0; i < q; i++)
	{
		query(node[i].x,node[i].y,i);
		ans[node[i].id] = ret;
	}
	for(int i = 0; i < q; i++)
		printf("%lld\n",ans[i]);
	return 0;
}
