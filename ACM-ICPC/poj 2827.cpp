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
const int MAXN = 30005;
const int INF = 1111111111;
int fa[MAXN],d[MAXN],x[MAXN];
int a[MAXN],b[MAXN],c[MAXN];
int find(int x)
{
	if(fa[x]==x) return x;
	int ret = find(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,xn;
	while(scanf("%d",&n)!=EOF)
	{
		xn = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>b[i]) swap(a[i],b[i]);
			x[xn++] = a[i]-1;
			x[xn++] = b[i];
		}
		sort(x,x+xn);
		xn = unique(x,x+xn)-x;
		int aa,bb;
		for(int i = 0; i <= xn; i++) fa[i] = i;
		memset(d,0,sizeof(d));
		for(int i = 0; i < n; i++)
		{
			aa = lower_bound(x,x+xn,a[i]-1)-x;
			bb = lower_bound(x,x+xn,b[i])-x;
			int u = find(aa), v = find(bb);
			if(u==v)
			{
				if(d[bb]-d[aa]!=c[i])
					printf("Bug Detected %d\n",d[bb]-d[aa]);
				else printf("Accept\n");
			}
			else
			{
                d[v] = d[aa]+c[i]-d[bb];
                fa[v] = u;
                printf("Accept\n");
			}
		}
	}
	return 0;
}
