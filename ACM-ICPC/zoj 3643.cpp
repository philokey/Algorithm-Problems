#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
const int MAXN = 1256;
const int INF = 0x3f3f3f3f;
int nnext[MAXN],len;
char mst[MAXN], text[512005];

int sta[512005],pos[512005];
void findnext() {
    nnext[1] = 0;
    for (int j = 0, i = 2;mst[i]; i++) {
        while (j > 0 &&mst[j+1] != mst[i]) j = nnext[j];
        if (mst[j+1] == mst[i]) j++;
        nnext[i] = j;
    }
}
int kmp() {
    int j = 0;
    int ret = 0, top = -1;
    int msl = strlen(mst+1);

    findnext();
    for (int i = 1; i <= len; i++) {
        sta[++top] = i;
        while (j > 0 && mst[j+1]!=text[i]) {
            j = nnext[j];
        }
        if (mst[j+1] == text[i]) {
             ++j;
        }
        pos[i] = j;
        if (j == msl) {
            ++ret;
            top -= msl;
            if (top == -1) {
                j = 0;
            } else {
                j = pos[sta[top]];
            }
        }
    }
    return ret;
}
int main() {
    //freopen("F:\\retired\\in.txt","r",stdin);
    while (scanf("%s%s",mst+1,text+1)!=EOF) {
        len = strlen(text+1);
        printf("%d\n",kmp());
    }
    return 0;
}
