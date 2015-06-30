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
bool is[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d",&u,&v);
        is[u] = 1, is[v] = 1;
    }
    for(int i = 1; i <= n; i++)
        if(!is[i]){u=i;break;}
    printf("%d\n",n-1);
    for(int i = 1; i <= n; i++)
        if(i==u) continue;
        else printf("%d %d\n",u,i);
    return 0;
}


