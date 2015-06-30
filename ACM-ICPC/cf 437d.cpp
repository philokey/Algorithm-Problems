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
const int MAXN = 1000005;
const int INF = 1111111111;
int fa[MAXN],cnt[MAXN],val[MAXN];
struct Edge{
    int u,v,w;
    bool operator < (const Edge a)const {
        return w > a.w;
    }
}edge[MAXN];
int find(int x) {
    //cout<<x<<endl;
    if (fa[x] == x) return x;
    return fa[x] = find(x);
}

int main() {
    freopen("F:\\retired\\in.txt","r",stdin);
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&val[i]);
            fa[i] = i;
            cnt[i] = 1;
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d%d",&edge[i].u,&edge[i].v);
            edge[i].w = max(val[edge[i].u],val[edge[i].v]);
        }
        double ans = 0;
        sort(edge,edge+m);

        int u,v;
        for (int i = 0; i < m; ++i) {
            u = find(edge[i].u);
            v = find(edge[i].v);
            cout<<u<<" "<<v<<endl;
            if (u != v) {
                ans += edge[i].w*(cnt[u]+cnt[v]);
                fa[u] = v;
                cnt[u] += cnt[v];
            }
        }
        printf("%.6f\n",ans/(n*(n-1)));
    }
    return 0;
}
