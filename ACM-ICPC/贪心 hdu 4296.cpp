#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 1111111111;
struct Node{
    int a,b;
    bool operator < (const Node&x)const
    {
        return b-x.a<x.b-a;
    }
}a[maxn];
long long sum[maxn],ans;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d%d",&a[i].a,&a[i].b);
        sort(a,a+n);
        ans = 0;
        sum[0]=0;
        for(int i = 1;i < n; i++)
        {
            sum[i]=sum[i-1]+a[i-1].a;
        }
        for(int i = 0; i < n; i++)
            ans=max(ans,sum[i]-a[i].b);
        cout<<max(ans,0ll)<<endl;
    }
    return 0;
}


