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
double node[MAXN];
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int n,m;
    int u,v;
    double w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i = 1;i<=n; i++)
            scanf("%lf",&node[i]);

        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%lf",&u,&v,&w);
            node[u]+=w/2;
            node[v]+=w/2;
        }
        sort(node+1,node+1+n);
        double a,b;
        a =b =0;

        for(int i = n; i>0; i--)
        {
            if(i%2==0) a+=node[i];
            else b+=node[i];
        }
        printf("%.0f\n",a-b);
    }
    return 0;
}
