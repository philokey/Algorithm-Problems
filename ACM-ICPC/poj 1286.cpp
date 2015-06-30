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
typedef long long LL;
LL pow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b&1) ret *= a;
        a*=a;
        b>>=1;
    }
    return ret;
}
LL polya(int n,int m) {
    LL ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret += pow(m,__gcd(i,n));
    }
    if (n&1) {
        ret += n*pow(m,n/2+1);
    } else {
        ret += n/2*pow(m,n/2+1) + n/2*pow(m,n/2);
    }
    return ret/n/2;
}
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    int n;
    while (scanf("%d",&n)&&(n!=-1)) {
        if (n == 0) {
            printf("0\n");
        }
        else {
            printf("%lld\n",polya(n,3));
        }
    }
    return 0;
}
