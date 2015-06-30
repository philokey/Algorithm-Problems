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
const int MAXN = 505;
const int INF = 1111111111;

struct Point{
	double x,y,z;
	int w;
	void input(){scanf("%lf%lf%lf%d",&x,&y,&z,&w);}
}p[MAXN];
inline int dist(Point a,Point b)
{
	double tmp = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
	int ret = floor(tmp);
	return ret;
}

//zkw费用流，不能有负环，标号全从1开始，很适用于筹密图
struct ZKW_flow{
    int st, ed, ecnt, n;
    int head[MAXN];
    int cap[MAXM], cost[MAXM], to[MAXM], next[MAXM];

    void init()
    {
        memset(head, 0, sizeof(head));
        ecnt = 2;
    }

    void addedge(int u, int v, int cc, int ww)
    {
        cap[ecnt] = cc; cost[ecnt] = ww; to[ecnt] = v;
        next[ecnt] = head[u]; head[u] = ecnt++;
        cap[ecnt] = 0; cost[ecnt] = -ww; to[ecnt] = u;
        next[ecnt] = head[v]; head[v] = ecnt++;
    }
	int dis[MAXN];
    void SPFA(){
        for(int i = 1; i <= n; ++i) dis[i] = INF;
        priority_queue<pair<int, int> > q;
        dis[st] = 0;
        q.push(make_pair(0, st));
        while(!q.empty())
		{
            int u = q.top().second, d = -q.top().first;
            q.pop();
            if(dis[u] != d) continue;
            for(int p = head[u]; p; p = next[p])
            {
                int &v = to[p];
                if(cap[p] && dis[v] > d + cost[p])
                {
                    dis[v] = d + cost[p];
                    q.push(make_pair(-dis[v], v));
                }
            }
        }
        for(int i = 1; i <= n; ++i) dis[i] = dis[ed] - dis[i];
    }

    int minCost, maxFlow;
    bool use[MAXN];

    int add_flow(int u, int flow)
    {
        if(u == ed)
		{
            maxFlow += flow;
            minCost += dis[st] * flow;
            return flow;
        }
        use[u] = 1;
        int now = flow;
        for(int p = head[u]; p; p = next[p])
        {
            int &v = to[p];
            if(cap[p] && !use[v] && dis[u] == dis[v] + cost[p])
            {
                int tmp = add_flow(v, min(now, cap[p]));
                cap[p] -= tmp;
                cap[p^1] += tmp;
                now -= tmp;
                if(!now) break;
            }
        }
        return flow - now;
    }

    bool modify_label()
    {
        int d = INF;
        for(int u = 1; u <= n; ++u) if(use[u])
            for(int p = head[u]; p; p = next[p])
			{
                int &v = to[p];
                if(cap[p] && !use[v]) d = min(d, dis[v] + cost[p] - dis[u]);
            }
        if(d == INF) return false;
        for(int i = 1; i <= n; ++i) if(use[i]) dis[i] += d;
        return true;
    }

    int min_cost_flow(int ss, int tt, int nn)
    {
        st = ss, ed = tt, n = nn;
        minCost = maxFlow = 0;
        SPFA();
        while(1)
		{
            while(1)
            {
                for(int i = 1; i <= n; ++i) use[i] = 0;
                if(!add_flow(st, INF)) break;
            }
            if(!modify_label()) break;
        }
        return minCost;
    }
}g;
double d[MAXN][MAXN];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);

	int s,t,n,sum;
	while(scanf("%d",&n)&&n)
	{
		g.init();
		sum = 0;
		for(int i = 1; i <= n; i++)
		{
			p[i].input();
			sum+=p[i].w;
		}
		for(int i = 1; i <= n; i++)
			for(int j = i+1; j <= n; j++)
				d[i][j] = d[j][i] = dist(p[i],p[j]);
		s = n*2+1, t = s+1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i==j) continue;
				g.addedge(i,j+n,p[i].w,d[i][j]);
				//cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
			}
		}

		for(int i = 1; i <= n; i++)
		{
			g.addedge(s,i,p[i].w,0);
			g.addedge(i+n,t,p[i].w,0);
		}
		//cout<<sum<<endl;
		g.min_cost_flow(s,t,t);
		if(g.maxFlow==sum)
			printf("%d\n",g.minCost);
		else printf("-1\n");
	}
	return 0;
}
