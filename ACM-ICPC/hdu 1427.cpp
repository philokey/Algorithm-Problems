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
int pa[15];
bool flag;
int input(char* str) {
    if (str[0] == '1' && str[1] == '0') return 10;
    char ch = str[0];
    if (ch == 'A') return 1;
    if (ch == 'J') return 11;
    if (ch == 'Q') return 12;
    if (ch == 'K') return 13;
    return ch-'0';
}
void solve(int dep,int pre,int now) {
    if (flag) return;
    if (dep >= 4) {
         if (pre+now == 24 || pre - now == 24 || pre*now == 24 ||(now != 0 && pre%now == 0 && pre/now == 24)) {
            flag = 1;
        }
        return;
    }
    solve(dep+1,pre+now,pa[dep]);
    solve(dep+1,pre-now,pa[dep]);
    solve(dep+1,pre*now,pa[dep]);
    if (now&&pre%now==0) solve(dep+1,pre/now,pa[dep]);

    solve(dep+1,pre,now+pa[dep]);
    solve(dep+1,pre,now-pa[dep]);
    solve(dep+1,pre,now*pa[dep]);
    if(pa[dep]&&now%pa[dep] == 0) solve(dep+1,pre,now/pa[dep]);
}
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    char op[5];
    while (scanf("%s",op)!=EOF) {
        pa[0] = input(op);
        for (int i = 1; i < 4; ++i) {
            scanf("%s",op);
            pa[i] = input(op);
        }
        flag = 0;
        sort(pa,pa+4);
        do {
            solve(2,pa[0],pa[1]);
        } while(next_permutation(pa,pa+4));

        if (flag) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
