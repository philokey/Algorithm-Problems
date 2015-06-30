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
bool g[MAXN][MAXN];
int a[MAXN];
int main()
{
    //freopen("F:\\code\\in.txt","w",stdout);
    int n,p,bi,m;
    while(scanf("%d",&p)!=EOF)
    {
        if(p==1)
        {
            printf("2\nNY\nYN\n");
            continue;
        }
        n = 2;
        bi = 0;
        m = 999;
        memset(g,0,sizeof(g));
        while(p)
        {
            a[bi++] = p&1;
            p>>=1;
        }
        bi-=2;
        g[0][2] = g[2][0] = 1;
        for(int i = bi; i>=0; i--)
        {

            if(n==2)
            {
                g[n][n+1]=g[n+1][n] = 1;
                g[n][n+2]=g[n+2][n] = 1;
            }
            else
            {
                int tmp = a[i+1];
                for(int l=n-1-tmp; l<=n; l++)
                    for(int r=n+1;r<=n+2;r++)
                        g[l][r] = g[r][l] = 1;
            }
            n+=2;
            if(a[i])
            {
                n++;
                int pre = n;
                for(int j = 0; j<bi-i+1; j++)
                {
                    g[pre][m]=g[m][pre]=1;
                    pre=m--;
                }
                g[pre][0] = g[0][pre] = 1;
            }

        }
        for(int i = n-1-a[0]; i<=n; i++)
            g[i][1] = g[1][i] = 1;
        printf("1000\n");
        for(int i = 0; i < 1000; i++)
        {
            for(int j = 0; j< 1000; j++)
                if(g[i][j]) printf("Y");
                else printf("N");
            printf("\n");
        }

    }
    return 0;
}
