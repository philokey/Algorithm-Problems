#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const double EPS = 1e-8;
long long a,b,c;
int mgot()
{
    int a,b;
    scanf("%d.%d",&a,&b);
    return a*100+b;
}
int main()
{
    int ncase,ans,sum;
    double aa,bb,cc;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&sum);
        a=mgot(),b=mgot(),c=mgot();
        if((a*b+b*c+c*a)*100>=a*b*c)
        {
            printf("%d\n",sum);
            continue;
        }
        ans=0;
        aa=a/100.0,bb=b/100.0,cc=c/100.0;
        int x=0,y=0,z=0,ax=0,by=0,cz=0,m=0;
        for(int i=1;i<=sum;++i)
        {
            if(ax==m)   ax=(++x)*aa;
            else    if(by==m)   by=(++y)*bb;
            else    cz=(++z)*cc;
            m=min(ax,min(by,cz));
            ans=max(m-i,ans);
        }
        printf("%d\n",sum+ans);
    }
    return 0;
}
