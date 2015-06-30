#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 1005;
const int inf = 1111111111;
char g[maxn][maxn];
int dist[maxn][maxn];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m;
queue<pair<int,int> > q;
bool judge(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m) return 1;
    return 0;
}
void bfs()
{
    int x,y,xx,yy;
    while(!q.empty())
    {
        x = q.front().first,y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            xx = x+dx[i];
            yy = y+dy[i];
            if(judge(xx,yy)&&dist[xx][yy]==-1&&g[xx][yy]!='T')
            {
                q.push(make_pair(xx,yy));
                dist[xx][yy] = dist[x][y]+1;
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    pair<int,int> s,e;
    memset(dist,-1,sizeof(dist));
    for(int i =0; i < n; i++)
        scanf("%s",g[i]);
    for(int i =0; i < n; i++)
        for(int j =0; j < m; j++)
        {
            if(g[i][j]=='S') s = make_pair(i,j);
            else if(g[i][j]=='E') e = make_pair(i,j),dist[i][j]=0;
            else if(g[i][j]=='T') dist[i][j] = inf;
        }
    q.push(e);
    bfs();
    int len = dist[s.first][s.second],tmp,ans = 0;
    for(int i =0; i < n; i++)
        for(int j =0; j < m; j++)
        {
            if(g[i][j]>'0'&&g[i][j]<='9')
            {
                tmp = g[i][j]-'0';
                if(dist[i][j]<=len&&dist[i][j]>0) ans+=tmp;
            }
        }
    printf("%d\n",ans);
    return 0;
}


