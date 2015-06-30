//time 31MS
//memory 1332K
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1015
using namespace std;
struct Point{
    int x,y;
    Point(){}
    Point(int a,int b):x(a),y(b){}
    bool operator ==(const Point &a)const
    {
        return x==a.x&&y==a.y;
    }
    void input(){scanf("%d%d",&x,&y);}
};
int link[MAXN],n,m;
bool vis[MAXN],g[MAXN][MAXN];
bool judge(Point a, Point b)
{
    if(a==b||Point(a.x+1,a.y)==b||Point(a.x+1,a.y)==Point(b.x,b.y+1)||a==Point(b.x,b.y+1))
        return 1;
    return 0;
}
bool dfs(int u)
{
    for(int i = 0;i < m; i++)
    {
        if(!vis[i]&&g[u][i])
        {
            vis[i] = 1;
            if(link[i]==-1||dfs(link[i]))
            {
                link[i] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    //freopen("/home/moor/Code/input","r",stdin);
    Point pn[MAXN],pm[MAXN];
    while(scanf("%d%d",&n,&m)&&(m+n))
    {
        memset(g,0,sizeof(g));
        for(int i = 0; i < n; i++)
            pn[i].input();
        for(int i = 0; i < m; i++)
            pm[i].input();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(judge(pn[i],pm[j]))
                    g[i][j] = 1;
        memset(link,-1,sizeof(link));
        int sum=0;
        for(int i = 0; i < n; i++)
        {
            memset(vis,0,sizeof(vis));
            sum+=dfs(i);
        }
        printf("%d\n",n+m-sum);
    }
    return 0;
}
