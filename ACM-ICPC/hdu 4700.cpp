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
const int MAXM = 50005;
const int MAXN = 205;
const int INF = 1111111111;
struct Node{
	int u,v,w;
	Node(){}
	Node(int a,int b,int c):u(a),v(b),w(c){}
	bool operator<(const Node&a)const
	{
		return w<a.w;
	}
}node[MAXM];
int ans[MAXN][MAXN],flow[MAXN][MAXN],fa[MAXN];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,u,v,w,m,fu,fv;
	while(scanf("%d",&n)!=EOF)
	{
		m = 0;
		memset(flow,-1,sizeof(flow));
		for(int i = 0; i <= n; i++) fa[i] = i;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				scanf("%d",&w);
				if(w>0) node[m++]= Node(i,j,w);
			}
		sort(node,node+m);

		bool flag=1;
		for(int i = 0; i < m; i++)
		{

			u = node[i].u,v = node[i].v,w = node[i].w;
			fu = find(u),fv = find(v);
			if(fu==fv)
			{
				if(w!=flow[u][v]){flag = 0;break;}
			}
			else
			{
				fa[fu] = fv;
				flow[u][v] = flow[v][u] = ans[u][v] = ans[v][u] = w;
				for(int j = 0; j < n; j++)
				{
					int t1,t2;
					t1 = max(flow[j][u],flow[j][v]);
					for(int k = 0; k < n; k++)
					{
						t2 = max(flow[k][u],flow[k][v]);
						if(fa[j]==fa[k]&&flow[j][k]==-1)
							flow[j][k] = flow[k][j] = min(t1,t2);
					}
				}

			}
		}
		if(!flag) printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i = 0; i < n;i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(j) printf(" ");
					if(i==j) printf("-1");
					else printf("%d",ans[i][j]);
				}
				printf("\n");
			}

		}
	}
	return 0;
}
