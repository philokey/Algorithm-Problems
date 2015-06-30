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
const int MAXN = 1000005;
const int INF = 1111111111;
const double PI = acos(-1.0);
int a[MAXN];
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0 ; i <n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int ans = n;
        for(int i = n-1,j = n/2-1; i>n/2-1&&j>=0; i--,j--)
        {
            while(a[j]*2>a[i]&&j>=0) j--;
            if(j>=0) ans--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
