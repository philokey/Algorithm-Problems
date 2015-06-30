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
int text[1000005],mstr[10005];
int next[10005];
int n,m;

void findnext() {
    next[1] = 0;
    for (int i = 2, j = 0; i <= m; ++i) {
        if (j && mstr[i] != mstr[j+1]) j = next[j];
        if (mstr[i] == mstr[j+1]) ++j;
        next[i] = j;
    }
}

int kmp() {
    int j = 0;
    findnext();
    for (int i = 1; i <= n; ++i) {
        if (j && mstr[j+1]!=text[i]) j = next[j];
        if (mstr[j+1] == text[i]) ++j;
        if (j == m) return i-j+1;
    }
    return -1;
}
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    int ca;
    scanf("%d",&ca);
    while (ca--) {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&text[i]);
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d",&mstr[i]);
        }
        printf("%d\n",kmp());
    }
    return 0;
}
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
int text[1000005],mstr[10005];
int next[10005];
int n,m;

void findnext() {
    next[1] = 0;
    for (int i = 2, j = 0; i <= m; ++i) {
        if (j && mstr[i] != mstr[j+1]) j = next[j];
        if (mstr[i] == mstr[j+1]) ++j;
        next[i] = j;
    }
}

int kmp() {
    int j = 0;
    findnext();
    for (int i = 1; i <= n; ++i) {
        if (j && mstr[j+1]!=text[i]) j = next[j];
        if (mstr[j+1] == text[i]) ++j;
        if (j == m) return i-j+1;
    }
    return -1;
}
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    int ca;
    scanf("%d",&ca);
    while (ca--) {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&text[i]);
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d",&mstr[i]);
        }
        printf("%d\n",kmp());
    }
    return 0;
}
