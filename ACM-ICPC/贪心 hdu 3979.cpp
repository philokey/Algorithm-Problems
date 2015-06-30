#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 10005;
const int inf = 1111111111;
struct Node{
    int x,y;
    bool operator < (const Node&b)const
    {
       return b.y*x<y*b.x;
    }
}a[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m,cas,att;
    long long ans,sum[maxn];
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas;ca++)
    {
        ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
             a[i].x=a[i].x/m+(a[i].x%m!=0);
        }
        sort(a,a+n);

        sum[n-1]=a[n-1].y;
        for(int i = n-2; i >= 0; i--)
            sum[i]=sum[i+1]+a[i].y;
        for(int i = 0; i < n; i++)
        {

            ans+=sum[i]*a[i].x;
        }
        cout<<"Case #"<<ca<<": "<<ans<<endl;
    }
    return 0;
}


