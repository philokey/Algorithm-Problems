#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 100005;
const int INF = 1111111111;
int h[MAXN];
stack<int> sta;
int main() {

    //freopen("F:\\retired\\in.txt","r",stdin);
    int n;
    while (scanf("%d",&n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d",&h[i]);
        }
        h[n] = 0;
        long long ans = 0;
        long long tmp;
        while (!sta.empty()) {
            sta.pop();
        }
        sta.push(0);
        int tp;
        for (int i = 1; i <= n; ++i) {
            while (!sta.empty()) {
                tp = sta.top();

                if (h[tp] <= h[i]) break;
                sta.pop();
                tmp = (long long)(i-tp)*h[tp];
                if (!sta.empty()) {
                    tmp = (long long)(i-sta.top()-1)*h[tp];
                } else {
                    tmp = (long long)(i)*h[tp];
                }
                ans = max(tmp,ans);

            }
            sta.push(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
