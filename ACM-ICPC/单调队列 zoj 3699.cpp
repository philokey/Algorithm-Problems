#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 200005;
const int inf = 1111111111;
int q[maxn],head,tail,cost[maxn];
int p[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int ca,n,m,use[maxn];
    int u,v;
    long long w;
    bool flag;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        flag = 1;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d",&u,&v,&p[i]);
            w=(long long)u*(long long)v;
            if(w>m) flag = 0;
            else cost[i]=u*v;
        }
        if(flag == 0)
        {
            printf("Impossible\n");
            continue;
        }
        head = tail = 0;
        long long ans = 0;
        int gas=0;
        for(int i = 1; i <= n; i++)
        {
            while(head<tail&&p[i]<p[q[tail-1]]) gas-=use[--tail];
            use[tail]=m - gas;
            q[tail++]=i;
            //cout<<gas<<" "<<m-gas<<endl;
            gas = m - cost[i];
            //cout<<gas<<endl;
            while(cost[i])
            {
                if(use[head]<=cost[i])
                {
                    cost[i]-=use[head];
                    ans+=(long long)use[head]*(long long)p[q[head]];
                    head++;
                }
                else
                {
                    use[head]-=cost[i];
                    ans+=(long long)cost[i]*(long long)p[q[head]];
                    cost[i]=0;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
