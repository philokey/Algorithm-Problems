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
        if (b&1) ret = ret*a;
        a*=a;
        b>>=1;
    }
    return ret;
}
LL polya(int n,int m) {
    LL ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret += pow(m,__gcd(n,i));
    }
    if (n&1) {
        ret += n*pow(m,n/2+1);
    } else {
        ret += n/2*pow(m,n/2+1) + n/2*pow(m,n/2);
    }
    return ret/(n*2);
}
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    int n,m;
    while (scanf("%d%d",&m,&n)&&(n+m)) {
        printf("%lld\n",polya(n,m));
    }
    return 0;
}
