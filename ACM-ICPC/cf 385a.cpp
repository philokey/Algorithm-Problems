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
int n,m;
int a[MAXN];
int c;
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&c)!=EOF)
    {
        int ans = 0,p,a;
        scanf("%d",&p);
        for(int i = 1; i < n; i++)
        {
            scanf("%d",&a);
            ans = max(ans,p-a-c);
            p = a;
        }
        printf("%d\n",ans);
    }
    return 0;
}
