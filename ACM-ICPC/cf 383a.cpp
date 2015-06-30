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
const int MAXN = 200005;
int n;
int a[MAXN],s[MAXN];
long long ans;
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(s,0,sizeof(s));
        for(int i = 0; i <n; i++)
            scanf("%d",&a[i]);
        for(int i = n-1; i >=0; i--)
            s[i] = s[i+1]+(a[i]==0);
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 1) ans+=s[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
