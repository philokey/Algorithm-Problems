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
int n,m;
long long a,b,x,y;
int main()
{
    //freopen("F:\\acmcode\\in.txt","r",stdin);
    cin>>x>>y>>a>>b;
    long long l = x*y/ __gcd(x,y);
    //a = min(a,b);
    long long ans = b/l-(a-1)/l;
    cout<<ans<<endl;
    return 0;
}
