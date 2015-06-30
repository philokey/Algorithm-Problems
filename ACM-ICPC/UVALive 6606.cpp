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
const int MAXN = 105;
const int INF = 1111111111;
struct Node{
    int s,t;
    bool operator <(const Node&a)const {
        return t < a.t;
    }
}node[MAXN];
int main()
{
    //freopen("F:\\retired\\in.txt","r",stdin);
    int cnt,ca;
    int u,v,ans;
    scanf("%d",&ca);
    cnt = 0;
    //cout<<ca<<endl;
    while (ca) {
        scanf("%d%d",&u,&v);
        //cout<<u<<" "<<v<<endl;
        if (u + v == 0) {
            --ca;
            ans = 0;
            sort (node,node+cnt);
            v = 0;
            for (int i = 0; i < cnt; ++i) {
                if (node[i].s >= v) {
                    ++ans;
                    v = node[i].t;
                }
            }
            printf("%d\n",ans);
            cnt = 0;
            continue;
        } else {
            node[cnt].s = u;
            node[cnt].t = v;
            ++cnt;
        }

    }
    return 0;
}
