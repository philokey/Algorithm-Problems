#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 300005;
const int inf = 1111111111;
int n,m,a[maxn],sum[maxn],q[maxn],head,tail;
int main()
{
    //freopen("in.txt","r",stdin);
    int ca,ans,s,t;
    scanf("%d",&ca);
    //cout<<ca<<endl;
    while(ca--)
    {

        scanf("%d%d",&n,&m);
        sum[0]=0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for(int i = n+1; i < 2*n; i++)
            sum[i]=sum[i-1]+a[i-n];
        head = tail = 0;
        ans = -inf;
        for(int i = 1; i < 2*n; i++)
        {
            while(head<tail&&sum[i-1]-sum[q[tail-1]-1]<0) tail--;
            q[tail++]=i;
            if(sum[i]-sum[q[head]-1]>ans)
            {
                ans = sum[i]-sum[q[head]-1];
                s = q[head],t = i;
            }
            if(i - q[head]+1>= m) head++;
        }
        if(t>n)t-=n;
        printf("%d %d %d\n",ans,s,t);
    }
    return 0;
}
