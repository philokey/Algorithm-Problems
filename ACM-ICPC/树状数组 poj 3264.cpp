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
int mxtr[MAXN],mitr[MAXN];
int a[MAXN];
int n,q;
inline int lowbit(int x) {
    return x&(-x);
}
void update(int x,int v) {
    while (x <= n) {
        mxtr[x]  = max(mxtr[x], v);
        mitr[x] = min(mitr[x], v);
        x += lowbit(x);
    }
}
int query(int l,int r) {
    int mx,mi;
    mx = mi = a[r];
    while (true) {
        mx = max(mx,a[r]);
        mi = min(mi,a[r]);
        if (l == r) break;
        for (r-=1; l+lowbit(r)<=r;r-=lowbit(r)) {
            mx = max(mx,mxtr[r]);
            mi = min(mi,mitr[r]);
        }
    }
    //cout<<mi<<" "<<mx<<endl;
    return mx-mi;
}
int main() {
   // freopen("F:\\retired\\in.txt","r",stdin);
    while (scanf("%d%d",&n,&q)!=EOF) {
        memset(mxtr,0,sizeof(mxtr));
        memset(mitr,0x3f,sizeof(mitr));
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&a[i]);
            update(i,a[i]);
        }
        int u,v;
        while (q--) {
            scanf("%d%d",&u,&v);
            printf("%d\n",query(u,v));
        }
    }

    return 0;
}
