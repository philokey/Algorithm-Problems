#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int MAXN = 1005;
const int INF = 1111111111;
const double EPS = 1e-6;
const double PI = acos(-1.0);
typedef long long LL;
int main()
{
    //freopen("F:\\acmcode\\in.txt","r",stdin);
    int cas,n,len[MAXN];
    LL p[MAXN],a[MAXN],b[MAXN];
    char str[MAXN];
    p[0] = 1;
    for(int i = 1; i <= 1000; i++) p[i]=p[i-1]*131;
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas;ca++)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s",str);
            len[i] = strlen(str);
            a[i]=b[i] = 0;
            for(int j = 0; str[j]; j++)
            {
                a[i]=a[i]*131+str[j]-'a';
                b[i]+=(str[j]-'a')*p[j];
            }
        }
        int ans = 0;
        for(int i = 0; i < n;i++)
            for(int j = 0; j < n; j++)
            {
                if(i==j) continue;
                if(a[i]*p[len[j]]+a[j]==b[j]*p[len[i]]+b[i])
                    ans++;
            }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
