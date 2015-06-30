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
int main()
{
    //freopen("in.txt","r",stdin);
    int cas,a[3];
    bool vis[15][15][15];
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas;ca++)
    {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        memset(vis,0,sizeof(vis));
		printf("Case #%d:\n",ca);
		sort(a,a+3);
		for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    if(i!=j&&i!=k&&k!=j&&!vis[a[i]][a[j]][a[k]])
                    {
                        printf("%d %d %d\n",a[i],a[j],a[k]);
                        vis[a[i]][a[j]][a[k]]=1;
                    }
    }
    return 0;
}


