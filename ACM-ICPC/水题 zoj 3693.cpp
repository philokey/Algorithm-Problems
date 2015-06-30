//time 0ms
//memory 180KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100005
int main()
{
    int n,k;
    double w;
    while(scanf("%d%lf%d",&n,&w,&k)==3)
    {
        n+=2;
        printf("%.2f\n",((n-n/k)*w+0.005)/2.0);
    }
    return 0;
}
