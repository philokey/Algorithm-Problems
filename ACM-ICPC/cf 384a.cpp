#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1005;
int n,m;
int a[MAXN][MAXN];
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    scanf("%d",&n);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j]==0)
            {
                cnt++;
                a[i][j]=2;
                a[i-1][j] = a[i+1][j] = a[i][j-1] = a[i][j+1] = 1;
            }
        }
    }
    printf("%d\n",cnt);
    for(int i = 1; i <=n; i++)
    {
       for(int j = 1; j <=n; j++)
            if(a[i][j] == 2)
                printf("C");
            else printf(".");
        printf("\n");
    }


    return 0;
}
