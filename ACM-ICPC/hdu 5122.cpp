#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;

int a[MAXN];
int main() {
    freopen("in.txt", "r", stdin);
    int cas;
    int n;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ++ca) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int now = a[n - 1];
        int ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (now < a[i]) {
                ++ans;
            }
            now = min(now, a[i]);
        }
        printf("Case #%d: %d\n", ca, ans);
    }
}
