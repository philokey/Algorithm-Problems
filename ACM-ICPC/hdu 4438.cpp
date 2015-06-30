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
const int MAXN = 1005;
const int INF = 1111111111;
const double PI = acos(-1.0);
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int ca;
    scanf("%d",&ca);
    double x,y,q,p;
    while(ca--)
    {
        scanf("%lf%lf%lf%lf",&x,&y,&p,&q);
        double a = (1-q)*x+q*(p*x+p*y);
        double b = q*y+(1-q)*(p*y+p*x);
        if(a>b) printf("tiger %.4f\n",a);
        else printf("wolf %.4f\n",b);
    }
    return 0;
}
