#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
const double EPS = 1e-8;
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int ca;
    double a,b,c;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        double tmp = -1/a+1-1/c;
        printf("%s\n",tmp>1/b+EPS?"Aha":"No way");
    }
    return 0;
}
