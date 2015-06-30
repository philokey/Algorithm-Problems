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
const int MAXN = 10000005;
const int MAXn = 10000000;
int cnt[MAXN],sum[MAXN];
bool prim[MAXN];
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int a,n,m;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a);
        cnt[a]++;
    }
    for(int i = 2; i < MAXN; i++ )
    {
        sum[i] = sum[i-1];
        if(!prim[i])
        {
            sum[i]+=cnt[i];
            for(int j = 2; i*j<MAXN; j++)
            {
                int tmp = i*j;
                prim[tmp] = 1;
                sum[i]+=cnt[tmp];
            }
        }
    }
    scanf("%d",&m);
    int l,r;
    while(m--)
    {
        scanf("%d%d",&l,&r);
        if(l>MAXn) printf("0\n");
        else if(r>MAXn) printf("%d\n",sum[MAXn]-sum[l-1]);
        else printf("%d\n",sum[r]-sum[l-1]);
    }
    return 0;
}
