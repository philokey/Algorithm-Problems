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
const int MAXN = 2005;
const int INF = 1111111111;
const double PI = acos(-1.0);
priority_queue<int> q;
int a[MAXN],b[MAXN];
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int n,m,ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&m,&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(int k = 1; k < m; k++)
        {
            for(int i = 0; i<n; i++)
                scanf("%d",&b[i]);
            sort(b,b+n);
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(q.size()<n||(a[i]+b[j]<q.top()))
                    {
                        if(q.size()==n) q.pop();
                        q.push(a[i]+b[j]);
                    }
                }
            }
            int cn = n-1;
            while(!q.empty())
            {
                a[cn--] = q.top();
                q.pop();
            }
        }


        for(int i = 0; i < n-1; i++)
            printf("%d ",a[i]);
       printf("%d\n",a[n-1]);
    }

    return 0;
}
