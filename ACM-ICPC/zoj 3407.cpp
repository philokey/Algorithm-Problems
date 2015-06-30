#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int ca;
    int n,m,up;
    int x,y,z,ans;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        up = sqrt(n*1.0);
        ans = INF;
        if(n<=m) {printf("-1\n");continue;}
        if(n==m+1){printf("0\n");continue;}
        for(x = 0; x <= up; x++)
        {
            y = (n-m-x)/(2*x-1);
            z = m-x-y;
            if(2*x*(y+1)+z==n&&z>=0&&y>=0)
                ans = min(ans,z);
        }
        for(y = 0; y <= up; y++)
        {
            x =(n-m+y)/(2*y+1);
            z = m-x-y;
            if(2*x*(y+1)+z==n&&z>=0&&x>0)
                ans = min(ans,z);
        }
        if(ans==INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
