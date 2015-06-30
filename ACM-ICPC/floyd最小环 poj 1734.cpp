#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 105;
const int INF = 100000000;
int n,m;
int f[MAXN][MAXN],dist[MAXN][MAXN],g[MAXN][MAXN],res[MAXN],num;
void dfs(int i ,int j) {
    int k = f[i][j];
    if (k == 0) {
        res[num++] = j;
        return;
    }
    dfs(i,k);
    dfs(k,j);
}
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    int n,m,u,v,w;
    //while (scanf("%d%d",&n,&m)!=EOF) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                g[i][j] = g[j][i] = dist[i][j] = dist[j][i] = INF;
            }
            g[i][i] = dist[i][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d",&u,&v,&w);
            g[u][v] = g[v][u] = dist[u][v] = dist[v][u] = min(dist[v][u],w);
        }
        int mm = INF;
        memset(f,0,sizeof(f));
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i < k; ++i) {
                for (int j = i+1; j < k; ++j) {
                    if (dist[i][j]+g[i][k]+g[k][j] < mm) {
                        mm = dist[i][j]+g[i][k]+g[k][j];
                        num = 0;
                        res[num++] = i;
                        dfs(i,j);
                        res[num++] = k;
                    }
                }
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dist[i][k]+dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k]+dist[k][j];
                        f[i][j] = k;
                    }
                }
            }
        }
        if (mm == INF) {
            puts("No solution.");
        } else {
            for (int i = 0; i < num; ++i) {
                printf("%d%c",res[i],i==num -1?'\n':' ');
            }
        }
    //}
    return 0;
}
