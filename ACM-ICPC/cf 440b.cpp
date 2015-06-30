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
const int MAXN = 50005;
const int INF = 1111111111;
int a[MAXN];
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    int n;
    long long sum;
    int arv;
    while (scanf("%d",&n) != EOF) {
        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        arv = sum/n;
        for (int i = 0; i < n; ++i) {
            a[i] -= arv;
        }
        long long ans = 0,s = 0;

        for (int i = 0; i < n; ++i) {
            s += a[i];
            ans += abs(s);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
