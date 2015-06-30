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
const int MAXN = 1005;
const int INF = 1111111111;
const double PI = acos(-1.0);
int n,m;
char str[MAXN];
inline int gao(int x)
{
    int tmp,ret = 0;
    while(x)
    {
        tmp = x%m;
        ret+=tmp*tmp;
        x/=m;
    }
    return ret;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        int ans=0;
        for(i = 1; i*i<n; i++)
        {
            if(n%i==0)
            {
                ans+=gao(i);
                ans+=gao(n/i);
            }
        }
        if(i*i==n) ans+=gao(i);
        int cnt = 0,tmp;
        while(ans)
        {
            tmp = ans%m;
            ans/=m;
            if(tmp>=10) str[cnt++] = 'A'+(tmp-10);
            else str[cnt++]=tmp+'0';
        }
        for(int i = cnt-1; i >= 0; i--)
            printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
