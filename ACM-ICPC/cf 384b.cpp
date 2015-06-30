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
int n,m,p;
int a[1005][1005];
pair<int,int> pa[MAXN*10];
int main()
{
    int ans;
    //freopen("F:\\code\\in.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        ans = 0;
        for(int i = 0; i <n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d",&a[i][j]);
        bool flag;
        if(p==0)
        {
            for(int i = 0 ; i <m; i++)
            {
                for(int j = i+1; j < m; j++)
                {
                    flag = 0;
                    for(int k = 0; k < n; k++)
                        if(a[k][i]>a[k][j]) swap(a[k][i],a[k][j]),flag = 1;
                    if(flag)
                    {
                        pa[ans++] = make_pair(i,j);
                    }
                }

            }
        }
        else
        {
            for(int i = 0 ; i <m; i++)
            {
                for(int j = i+1; j < m; j++)
                {
                    flag = 0;
                    for(int k = 0; k < n; k++)
                    {
                        if(a[k][i]<a[k][j]) swap(a[k][i],a[k][j]),flag = 1;
                    }
                    if(flag)pa[ans++] = make_pair(j,i);
                }

            }
        }
        printf("%d\n",ans);
        for(int i =0; i < ans; i++)
            printf("%d %d\n",pa[i].first+1,pa[i].second+1);
    }
    return 0;
}
