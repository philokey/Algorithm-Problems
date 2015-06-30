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
const int INF = 0x3f3f3f3f;
int dis[MAXN][MAXN];
int tonum(char str[]) {
    int ret = 0;
    int n = strlen(str);
    for (int i = 0; i < n; ++i) {
        ret = ret * 10 + str[i]-'0';
    }
    return ret;
}
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    int n;
    char str[35];
    while (scanf("%d",&n) != EOF) {
        memset(dis,0x3f,sizeof(dis));
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                scanf("%s",str);
                if (str[0] != 'x')
                    dis[i][j] = dis[j][i] = tonum(str);
            }
        }
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = max(ans,dis[1][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
