#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 1005;
const int inf = 1111111111;
struct Node{
    double x,y;
    bool operator < (const Node&a)const
    {
        return x>a.x;
    }
}node[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int ca,n;
    double h,ans;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        ans = 0;
        for(int i = 0; i < n ; i++)
            scanf("%lf%lf",&node[i].x,&node[i].y);
        if(n==1)
        {
            printf("%.2f\n",node[0].y);
            continue;
        }
        sort(node,node+n);
        h = node[0].y;
        for(int i = 1; i < n; i++)
        {
            if(node[i].y>h)
            {
                double tmp = node[i].y-h;
                double si = (node[i].y-node[i-1].y)/sqrt((node[i].y-node[i-1].y)*(node[i].y-node[i-1].y)+(node[i].x-node[i-1].x)*(node[i].x-node[i-1].x));
                ans+=tmp/si;
                h = node[i].y;
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}


