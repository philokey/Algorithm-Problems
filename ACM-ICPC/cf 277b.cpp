//���⣬��n���㣬���͹������m���㣬�������㹲�ߣ�����һ����н�
//���������߼���
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
