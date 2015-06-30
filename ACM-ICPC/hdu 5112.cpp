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
pair<int, int> pa[MAXN];
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    int cas;
    int n;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ++ca) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &pa[i].first, &pa[i].second);
        }
        sort(pa, pa + n);
        int tpre = pa[0].first;
        double ppre = pa[0].second;
        double ans = 0;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, abs(ppre - pa[i].second) / (pa[i].first - tpre));
            tpre = pa[i].first;
            ppre = pa[i].second;
        }
        printf("Case #%d: %.2f\n", ca, ans);
    }
    return 0;
}
