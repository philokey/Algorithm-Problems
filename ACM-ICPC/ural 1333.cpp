#include<cstdio>
#include<cmath>
using namespace std;
int dcmp(double x)
{
    if(fabs(x)<1e-8) return 0;
    return x<0?-1:1;
}
int main()
{
    int n;
    double x[15],y[15],r[15];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
    //printf("%.3lf\n",x[0]);
    double EPS = 1e-3,ans=0;
    for(double i = 0; i < 1; i+=EPS)
        for(double j = 0; j < 1; j+=EPS)
        {
            for(int k = 0; k < n; k++)
            {

                if(dcmp(sqrt((x[k]-i)*(x[k]-i)+(y[k]-j)*(y[k]-j))-r[k])<=0)
                {
                    ans+=EPS*EPS;
                    break;
                }

            }
        }
    printf("%lf\n",ans*100);
    return 0;
}
