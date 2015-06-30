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
const int MAXN = 10000005;
const int INF = 1111111111;
char str[MAXN];
int next[MAXN];
void findnext() {
    next[1] = 0;
    for (int i = 2, j = 0; str[i]; ++i) {
        if (j && str[j+1] != str[i]) j = next[j];
        if (str[j+1] == str[i]) ++j;
        next[i] = j;
    }
}
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    while (scanf("%s",str+1) && str[1] != '.') {
        findnext();
        int len = strlen(str+1);
        int n = len - next[len];
        //cout<<n<<"****"<<endl;
        if (len % n == 0) {
            printf("%d\n",len/n);
        } else {
            printf("1\n");
        }
    }
    return 0;
}
