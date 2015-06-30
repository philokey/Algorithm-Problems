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
const int MAXN = 1005;
const int INF = 1111111111;
int dp[MAXN][MAXN];
char sa[MAXN],sb[MAXN];
int n,m;
int main() {
    freopen("F:\\retired\\in.txt","r",stdin);
    while (scanf("%d%s%d%s",&n,sa+1,&m,sb+1)!=EOF) {
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (sa[i] == sb[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                }

            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
