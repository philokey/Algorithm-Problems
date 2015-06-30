#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 105;
const int inf = 1111111111;
char g[maxn][maxn];
bool c[maxn],r[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i =0; i < n; i++)
        scanf("%s",g[i]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(g[i][j]=='.'){c[i]=1;break;}
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        if(g[j][i]=='.'){r[i]=1;break;}
    bool flag = 1;
    for(int i = 0; i < n&&flag; i++)
        if(!c[i])flag = 0;
    if(flag)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(g[i][j]=='.')
                {
                    printf("%d %d\n",i+1,j+1);
                    break;
                }
        return 0;
    }
    flag = 1;
    for(int i = 0; i < n&&flag; i++)
        if(!r[i])flag = 0;
    if(flag)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(g[j][i]=='.')
                {
                    printf("%d %d\n",j+1,i+1);
                    break;
                }
        return 0;
    }
    printf("-1\n");
    return 0;
}


