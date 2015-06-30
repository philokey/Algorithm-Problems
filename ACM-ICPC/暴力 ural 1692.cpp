//题意：给k种不同颜色，制作旗子，任意两面旗至少要有一种颜色相同，且一种颜色最多用两次，问最多可以制作几面不同的旗，并输出颜色
//解法：相当于是找完全图。要制作n面旗，至少需要n*(n-1)/2种颜色，然后暴力枚举就是了
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
int ans[maxn][maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d",&n);
    for(m = 1; m*(m-1)/2<n;m++);
    if(m*(m-1)/2!=n) m--;
    printf("%d\n",m);
    int c = 1;
    for(int i = 1; i < m; i++)
    {
        for(int j = i,k=0; j < m;j++,k++)
            ans[i][j] =c+k;
        for(int j = i+1; j <= m;j++)
            ans[j][i] = c++;
    }
    for(int i = 1; i <= m; i++)
    {
        printf("%d",m-1);
        for(int j = 1;j < m; j++)
            printf(" %d",ans[i][j]);
        printf("\n");
    }
    return 0;
}


