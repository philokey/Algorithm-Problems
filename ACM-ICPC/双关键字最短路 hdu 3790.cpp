#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 10005;
const int inf = 1111111111;
struct Edge{
	int v,w,next,c;
}edge[400005];
int head[maxn],en=0;
int dist[maxn],cost[maxn],n,m;
void addedge(int u,int v,int w,int c)
{
	edge[en].v=v,edge[en].w=w,edge[en].c = c;
	edge[en].next=head[u];
	head[u]=en++;
}
void init()
{
    memset(head,-1,sizeof(head));
    en = 0;
}
void spfa(int s)
{
	queue<int> q;
	bool vis[maxn]={0};
	int fr;
	for(int i=1;i<=n;i++)	dist[i]=inf,cost[i]=0;
	dist[s]=0;
	q.push(s);
	while(!q.empty())
	{
		fr=q.front(),q.pop();
		vis[fr]=0;
		for(int e=head[fr];e!=-1;e=edge[e].next)
		{
			int v=edge[e].v;
			if(dist[v]>dist[fr]+edge[e].w||(dist[v]==dist[fr]+edge[e].w&&cost[v]>cost[fr]+edge[e].c))
			{
				dist[v]=dist[fr]+edge[e].w;
				cost[v]=cost[fr]+edge[e].c;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return;
}

int main()
{
    freopen("in.txt","r",stdin);
    int u,v,d,c;
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        init();
        for(int i = 0; i < m ;i++)
        {
            scanf("%d%d%d%d",&u,&v,&d,&c);
            addedge(u,v,d,c);
            addedge(v,u,d,c);
        }
        scanf("%d%d",&u,&v);
        spfa(u);
        printf("%d %d\n",dist[v],cost[v]);
    }
    return 0;
}


