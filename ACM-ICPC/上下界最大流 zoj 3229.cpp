#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
const int MAXM = 410000*2;
const int INF = 0x3f3f3f3f;
struct FlowMAXNetwork{
	int possible;
	int e;
	int head[MAXN],d[MAXN],vd[MAXN],pre[MAXN],cur[MAXN];
	int nxt[MAXM],eu[MAXM],ev[MAXM];
	int c[MAXM],mi[MAXM],deg[MAXM];
	void add(int u,int v,int w)
	{
		eu[e] = u;ev[e] = v;c[e] = w;nxt[e] = head[u]; head[u] = e++;
		eu[e] = v,ev[e] = u,c[e] = 0,nxt[e] = head[v], head[v] = e++;
	}
	int sap(int s,int t,int n)
	{
		int i,u;
		memset(d,0,sizeof(d));
		memset(vd,0,sizeof(vd));
		cur[u=s] = head[s];
		pre[s] = -1;
		int temp,ans = 0;
		while(d[s]<n)
		{
			if(u==t)
			{
				for(temp = INF,i = pre[u];i!=-1; i = pre[eu[i]])
					temp = min(temp,c[i]);
				for(i = pre[u]; i!=-1; i = pre[eu[i]])
				{
					c[i]-=temp;
					c[i^1]+=temp;
				}
				ans+=temp;
				u = s;
			}
			for(i = cur[u];i!=-1;i = nxt[i])
				if(c[i]>0&&d[u]==d[ev[i]]+1)
				{
					cur[u] = i;
					pre[u=ev[i]] = i;
					break;
				}
			if(i == -1)
			{
				cur[u] = head[u];
				if(--vd[d[u]] == 0) break;
				vd[++d[u]]++;
				if(u!=s) u = eu[pre[u]];
			}
		}
		return ans;
	}
	void init()
	{
		possible = 1;
		e = 0;
		memset(head,-1,sizeof(head));
		memset(deg,0,sizeof(deg));
	}
	void addedge(int u,int v,int L,int R)
	{
		int w = R-L;
		mi[e/2] = L;
		if(w<0) possible = 0;
		deg[u]-=L;
		deg[v]+=L;
		add(u,v,w);
	}
	int run(int pres,int pret,int sn,int tn)
	{
		if(!possible) return -1;
		addedge(pret,pres,0,INF);
		int sum = 0;
		int s = tn+1,t = tn+2;
		int end = e;
		for(int i = sn; i <= tn; i++)
		{
			if(deg[i]>0) add(s,i,deg[i]),sum+=deg[i];
			else add(i,t,-deg[i]);
		}
		int res = sap(s,t,tn-sn+3);
		if(res!=sum) return -1;
		for(int i = 0; i < end; i+=2)
		{
			mi[i/2]+=c[i^1];
			c[i^1] = 0;
		}
		int ans = mi[end/2-1];
		ans+=sap(pres,pret,tn-sn+3);
		for(int i = 0; i < end; i+=2)
			mi[i/2]+=c[i^1];
		return ans;
	}
	int flow(int i)
	{
		return mi[i-1];
	}
}fl;
vector<int> out[405];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m,w;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		fl.init();
		int s =0,t = n+m+1;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d",&w);
			fl.addedge(n+i,t,w,INF);
		}
		for(int i = 1; i <= n; i++)
		{
			out[i].clear();
			int c,d;
			scanf("%d%d",&c,&d);
			fl.addedge(s,i,0,d);
			for(int j = 0; j < c; j++)
			{
				int v,l,r;
				scanf("%d%d%d",&v,&l,&r);
				++v;
				out[i].push_back(fl.e/2+1);
				fl.addedge(i,n+v,l,r);
			}
		}
		int res = fl.run(s,t,0,n+m+1);
		if(res!=-1)
		{
			printf("%d\n",res);
			for(int i = 1; i <= n; i++)
				for(int j = 0; j < out[i].size();j++)
					printf("%d\n",fl.flow(out[i][j]));
		}
		else printf("-1\n");
		printf("\n");
	}
	return 0;
}
