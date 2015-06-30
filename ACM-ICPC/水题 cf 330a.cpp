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
int a[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    int cnt= 0;
    char g[50][50];
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
        scanf("%s",g[i]);
    bool c[50]={0},r[50]={0};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            if(g[i][j]=='S'){c[i]=1;break;}
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        if(g[j][i]=='S'){r[i]=1;break;}
    }
    for(int i = 0; i < n; i++)
    {
        if(c[i]) continue;
        for(int j = 0; j < m;j++)
            g[i][j]='a',cnt++;
    }
    for(int i = 0; i < m; i++)
    {
        if(r[i]) continue;
        for(int j = 0; j < n; j++)
            if(g[j][i]=='.') cnt++;
    }

    printf("%d\n",cnt);
    return 0;
}


