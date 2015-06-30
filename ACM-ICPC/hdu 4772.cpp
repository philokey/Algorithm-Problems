#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 105;
int a[2][MAXN][MAXN],b[MAXN][MAXN];
int n;
int solve(int s)
{
    int ret = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ret+=(a[s][i][j]==b[i][j]);
    return ret;
}
void rotate(int s)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[s^1][j][n-i-1] = a[s][i][j];
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    while(scanf("%d",&n)&&n)
    {
        for(int i =0;i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d",&a[0][i][j]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n;j++)
                scanf("%d",&b[i][j]);
        bool s = 0;
        int ans = 0;
        for(int i = 0; i < 4; i++)
        {
            ans = max(ans,solve(s));
            rotate(s);
            s^=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
