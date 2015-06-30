#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#define FI first
#define SE second

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const double EPS = 1e-8;
const int MAXN = 50005;
const int INF = 1111111111;

int mxtr[MAXN<<2],mitr[MAXN<<2];
int a[MAXN];
int n,q;
void update(int w,int pos,int l,int r,int rt) {
    if (l == r) {
        mxtr[rt] = w;
        mitr[rt] = w;
        return;
    }
    int m = (l+r)>>1;
    if (pos <= m) {
        update(w,pos,lson);
    } else {
        update(w,pos,rson);
    }
    mxtr[rt] = max(mxtr[rt<<1],mxtr[rt<<1|1]);
    mitr[rt] = min(mitr[rt<<1],mitr[rt<<1|1]);
}
int query1(int L,int R,int l,int r,int rt) {
    //cout<<L<<" "<<l<<" "<<R<<" "<<r<<endl;
    if (L<=l && r <= R) {
        return mxtr[rt];
    }
    int m = (l+r)>>1;
    int ret = 0;
    if (L <= m) ret = max(ret,query1(L,R,lson));
    if (R > m) ret = max(ret,query1(L,R,rson));
    return ret;
}
int query2(int L,int R,int l,int r,int rt) {
    if (L<=l && r <= R) {
        return mitr[rt];
    }
    int m = (l+r)>>1;
    int ret = 0x3f3f3f3f;
    if (L <= m) ret = min(ret,query2(L,R,lson));
    if (R > m) ret = min(ret,query2(L,R,rson));
    return ret;
}
int main() {
   // freopen("F:\\retired\\in.txt","r",stdin);
     while (scanf("%d%d",&n,&q)!=EOF) {
        memset(mxtr,0,sizeof(mxtr));
        memset(mitr,0x3f,sizeof(mitr));
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&a[i]);
            update(a[i],i,
                   1,n,1);
        }
        int u,v;
        while (q--) {
            scanf("%d%d",&u,&v);
           // cout<<query1(u,v,1,n,1)<<" "<<query2(u,v,1,n,1)<<endl;
            printf("%d\n",query1(u,v,1,n,1)-query2(u,v,1,n,1));
        }
    }
    return 0;
}
