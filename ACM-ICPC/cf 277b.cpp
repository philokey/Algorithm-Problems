//题意，给n个点，最大凸包上有m个点，且无三点共线，给出一组可行解
//两条抛物线即可
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
const int MAXN = 100005;
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>4&&m==3){printf("-1\n");return 0;}
    for(int i=1; i <= m; i++)
        printf("%d %d\n",i,i*i);
    n-=m;
    for(int i=1; i <= n; i++)
        printf("%d %d\n",1000000-i,-i*i);
    return 0;
}
