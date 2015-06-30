/*
求解最小割集普遍采用Stoer-Wagner算法：
1.min=MAXINT，固定一个顶点P
2.从点P用类似prim的s算法扩展出“最大生成树”，记录最后扩展的顶点和最后扩展的边
3.计算最后扩展到的顶点的切割值（即与此顶点相连的所有边权和），若比min小更新min
4.合并最后扩展的那条边的两个端点为一个顶点（当然他们的边也要合并，这个好理解吧？）
5.转到2，合并N-1次后结束
6.min即为所求，输出min
prim本身复杂度是O(n^2)，合并n-1次，算法复杂度即为O(n^3)
如果在prim中加堆优化，复杂度会降为O((n^2)logn)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const int MAXN = 1005;
const int INF = 111111111;
int g[MAXN][MAXN];
int fa[MAXN], dis[MAXN];
bool vis[MAXN];

int Stoer_Wagner(int n)
{
    int res = INF;
    for(int i = 0; i < n; i ++)fa[i] = i;
    while(n > 1)
    {
        int k = 1, pre = 0;//k为最远点
        for(int i = 1; i < n; i ++)
        {
            dis[fa[i]] = g[fa[0]][fa[i]];
            if(dis[fa[i]] > dis[fa[k]])  k = i;
        }
        memset(vis, 0, sizeof(vis));
        vis[fa[0]] = true;
        for(int i = 1; i < n; i ++)
        {
            if(i == n-1)//生成树的最后一条边  
            {
                res = min(res, dis[fa[k]]);
                for(int j = 0; j < n; j ++)
                {
                    g[fa[pre]][fa[j]] += g[fa[j]][fa[k]];
                    g[fa[j]][fa[pre]] += g[fa[j]][fa[k]];
                }
                fa[k] = fa[-- n];
            }
            vis[fa[k]] = true;
            pre = k;
            k = -1;
            for(int j = 1; j < n; j ++)
                if(!vis[fa[j]])
                {
                    dis[fa[j]] += g[fa[pre]][fa[j]];//更新到树的和距离 
                    if(k == -1 || dis[fa[k]] < dis[fa[j]])
                        k = j;
                }
        }
    }
    return res;
}

int main()
{
    int n, m, u, v, w;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(g, 0, sizeof(g));
        while(m --)
        {
            scanf("%d%d%d", &u, &v, &w);
            g[u][v] += w;
            g[v][u] += w;
        }
        printf("%d\n", Stoer_Wagner(n));
    }
    return 0;
}
