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
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
char g[MAXN][MAXN];
int dist[MAXN][MAXN],way[15][15],ans;
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
struct Node{
    int x,y;
}node[15];
int n,m,q;
bool vis[MAXN][MAXN],is[15];
void bfs(Node s,int id)
{
    queue<Node> que;
    int x,y;
    que.push(s);
    memset(vis,0,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    vis[s.x][s.y]=1;
    dist[s.x][s.y] = 0;
    while(!que.empty())
    {
        x = que.front().x;
        y = que.front().y;
        que.pop();
        for(int i = 0; i < 4; i++)
        {
            int xx = x+dx[i],yy = y+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&g[xx][yy]=='.')
            {
                s.x = xx;s.y = yy;
                dist[xx][yy] = dist[x][y]+1;
                vis[xx][yy] = 1;
                que.push(s);
            }
        }
    }
    for(int i = 0; i <= q; i++)
        way[id][i] = dist[node[i].x][node[i].y];
    return;
}
void dfs(int u,int dep,int sum)
{
    if(dep==q)
    {
        ans = min(ans,sum);
        return;
    }
    for(int i = 1; i <=q; i++)
    {
        if(!is[i]&&way[u][i]<INF)
        {
            is[i] = 1;
            dfs(i,dep+1,sum+way[u][i]);
            is[i] = 0;
        }
    }
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%s",g[i]);
            for(int j = 0; j < m; j++)
                if(g[i][j]=='@') node[0].x = i,node[0].y = j,g[i][j] = '.';
        }
        scanf("%d",&q);
        for(int i = 1; i <= q; i++)
        {
            scanf("%d%d",&node[i].x,&node[i].y);
            --node[i].x,--node[i].y;
        }
        for(int i = 0; i <=q; i++)
            bfs(node[i],i);
        ans = INF;
        memset(is,0,sizeof(is));
        is[0] = 1;
        dfs(0,0,0);
        if(ans>=INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
