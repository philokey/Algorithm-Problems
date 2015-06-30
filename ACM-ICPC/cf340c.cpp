#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int MAXN = 100005;
const int INF = 1111111111;
const double EPS = 1e-6;
const double PI = acos(-1.0);
typedef long long LL;
LL a[MAXN],sum;
int main()
{
    //freopen("F:\\acmcode\\in.txt","r",stdin);
    int n;
    sum = 0;
    scanf("%d",&n);
    //a[1]=0;

    for(int i = 1; i <= n; i++)
    {
        scanf("%I64d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1);

    LL tmp=0;
    for(int i = 0; i < n; i++)
    {
        tmp+=a[n-i]*(n-(2*i+1));
    }
    //cout<<sum<<" "<<n<<endl;
    sum+=2*tmp;

    LL g = __gcd(sum,(LL)n);
    sum/=g,n/=g;
    cout<<sum<<" "<<n<<endl;
    return 0;
}
