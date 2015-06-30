#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 100005;
char str[MAXN];
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int ca,n,m;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d%s",&n,&m,str);
        int len = strlen(str);
        for(int i = 0; i < len; i+=m)
        {
            for(int j = 0; j < m; j++)
                printf("%c",str[i+j]);
            printf("\n");
        }
    }
    return 0;
}
