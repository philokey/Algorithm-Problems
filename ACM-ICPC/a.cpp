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
int n;
int a[MAXN];
char str[MAXN];
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    while(scanf("%s",str)!=EOF)
    {
        int a[3];
        int stp=0;
        memset(a,0,sizeof(a));
        for(int i = 0; str[i]; i++)
        {
            if(str[i]=='+') stp++;
            else if(str[i]=='=') stp++;
            else a[stp]++;
        }

        if(a[0]+a[1]-a[2]==2)
        {
            a[2]++;
            if(a[0]>a[1]) a[0]--;
            else a[1]--;
        }
        else if(a[0]+a[1]-a[2]==-2)
        {
            a[0]++;
            a[2]--;
        }
        else if(a[0]+a[1]-a[2]==0);
        else
            {
                printf("Impossible\n");
                continue;
        }
        for(int i = 0; i < a[0]; i++)
            printf("|");
        printf("+");
        for(int i = 0; i < a[1]; i++)
            printf("|");
        printf("=");
        for(int i = 0; i < a[2]; i++)
            printf("|");
        printf("\n");
    }
    return 0;
}
