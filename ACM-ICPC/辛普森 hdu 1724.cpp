#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 100005;
const double EPS = 1e-9;
double a,b,l,r;
double sqr(double x){return x*x;}
double f(double x)
{
    return b*sqrt(1-sqr(x)/sqr(a));
}
double simpson(double l,double r)
{
    return (f(l)+f(r)+4*f((l+r)/2))/6*(r-l);
}
double solve(double l,double r)
{
    double ans = simpson(l,r),m = (l+r)/2;
    if(fabs(ans-simpson(l,m)-simpson(m,r))<EPS)
        return ans;
    return solve(l,m)+solve(m,r);
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
        printf("%.3f\n",2*solve(l,r));
    }
    return 0;
}
