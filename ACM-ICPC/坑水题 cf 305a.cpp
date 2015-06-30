#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 1005;
const int inf = 1111111111;
int ans[maxn],an;
bool judge(int x)
{
    bool flag = 0;
    if(x==0) return 1;
    while(x)
    {
        if(x%10==0) flag = 1;
        x/=10;
    }
    return flag;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,a,b=-1,c;
    scanf("%d",&n);
    an = 0;
    int f1,f2,f3,f0;
    f0=f1=f2=f3=0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a);
        if(a==0&&f0==0) ans[an++]=a,f0=1;
        else if(a==100&&f3==0)ans[an++]=a,f3=1;
        else if(f1==0&&a<10) ans[an++]=a,f1=1;
        else if(f2==0&&a%10==0) ans[an++]=a,f2=1;
        if(a!=0&&a!=100&&a>10&&a%10!=0) b=a;
        c=a;
    }
    sort(ans,ans+an);
    an=unique(ans,ans+an)-ans;
    if(f0+f1+f2+f3>=2)
    {
		if(f0+f1+f2+f3==2&&f0==1&&f3==1&&b!=-1)  printf("%d\n",an+1);
		else printf("%d\n",an);
        for(int i =0; i < an; i++)
            printf("%d ",ans[i]);
		if(f0+f1+f2+f3==2&&f0==1&&f3==1&&b!=-1) printf("%d",b);
        printf("\n");
    }
    else if(b!=-1&&(f0+f3)>0)
    {
        printf("2\n%d %d\n",b,ans[0]);
    }
    else printf("1\n%d",c);
    return 0;
}


