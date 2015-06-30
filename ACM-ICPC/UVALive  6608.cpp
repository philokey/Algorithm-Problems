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
const int MAXN = 10005;
const int INF = 1111111111;
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    double sl = 25, sw = 45, sd = 56, wei = 7;
    int ca,cnt = 0;
    double a[4],wt;
    scanf("%d",&ca);
    while (ca--) {
        cin>>a[0]>>a[1]>>a[2]>>wt;
        sort(a,a+3);
        if (((a[0] - EPS < sl && a[1] - EPS < sw && a[2] - EPS < sd) ||
            (a[0] + a[1] + a[2] - EPS < 125)) && wt - EPS < wei) {
                ++cnt;
                printf("1\n");
            } else {
                printf ("0\n");
            }
    }
    printf ("%d\n",cnt);
    return 0;
}
