/*
题意：将一个十进制的正数装换成phi进制的数。
解法：比赛的时候太二，没有发现十进制数可以等于一个phi进制数，而不是约等于。这个想想就知道，因为一个十进制的数肯定可以表示成n*(phi^0),于是显然可以化简成一个规范的phi进制数。
利用题目中给出的公式和hint可以得到两个有用的公式：
phi^(n) = phi^(n-1)+phi^(n-2)
2*(phi^n) = phi^(n+1)+phi^(n-2)
可以计算出phi^100远大于10^9，所以推测最后得到的phi进制的数整数和小数部分应该不会超过100位，事实表明，50位就能过。
所以最终变成了简单的模拟。
可是为什么，比赛的时候什么都想不到呢，郁闷
*/
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
const int MAXN = 205;

int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int a[MAXN],n,bas=100;
    bool flag;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        a[50] = n;
        flag = 1;
        while(flag)
        {
            flag = 0;
            for(int i = 2; i < 100; i++)
            {
                if(a[i]>1)
                {
                    a[i-2]+=a[i]/2;
                    a[i+1]+=a[i]/2;
                    a[i]%=2;
                    flag = 1;
                }
            }
            for(int i = 0; i<100;i++)
            {
                if(a[i]&&a[i+1])
                {
                    int tmp = min(a[i],a[i+1]);
                    a[i+2]+=tmp;
                    a[i]-=tmp;
                    a[i+1]-=tmp;
                    flag = 1;
                }
            }
        }
        int st,ed;
        for(int i = 100; i >= 0; i--)
            if(a[i])
            {
                st = i;
                break;
            }
        for(int i = 0; i < 100; i++)
            if(a[i])
            {
                ed = i;
                break;
            }
        for(int i = st; i >= ed; i--)
        {
            if(i==49) printf(".");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
