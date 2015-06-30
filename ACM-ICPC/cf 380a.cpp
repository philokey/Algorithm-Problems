#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
long long cnt[MAXN];
int a[MAXN];
int n,m,len;
struct Nod{
    int tp;
    int c,l;
}rec[MAXN];
int bs(long long p)
{
    int ans,l,r,m;
    l = 0, r = n+1;
    while(l<=r)
    {
        m = (l+r)/2;
        if(cnt[m]>=p) r = m-1;
        else l = m+1,ans = m;
    }
    return ans+1;
}
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);

    int c,l,tp;
    len = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&tp);
        if(tp == 1)
        {
            scanf("%d",&c);
            rec[i].tp = 1;
            rec[i].c = c;
            cnt[i] = cnt[i-1]+1;
            if(len<MAXN) a[len++] = c;
        }
        else
        {
            scanf("%d%d",&l,&c);
            rec[i].tp = 2;
            rec[i].l = l,rec[i].c = c;
            cnt[i] = cnt[i-1]+l*c;
            for(int i = 0; i<c&&len<MAXN; i++)
                for(int j = 0; j<l&&len<MAXN; j++)
                    a[len++] = a[j];
        }

    }
    scanf("%d",&m);
    long long p;
    for(int i = 0; i <m; i++)
    {
        scanf("%I64d",&p);
        if(p<MAXN) printf("%d ",a[p-1]);
        else
        {
            c = bs(p);
            if(rec[c].tp==1) printf("%d ",rec[c].c);
            else
            {
                long long ps = p - cnt[c-1]-1;
                ps%=rec[c].l;
                printf("%d ",a[ps]);
            }
        }

    }
    return 0;
}
