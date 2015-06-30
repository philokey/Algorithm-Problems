/*题意：给ｎ个数和它们之间的符号，只有(& | ^)，每个符号和它后面的数字有ｐ的概率会消失，问运算之后期望是多少
解法：因为上述运算不会涉及进位，所以可以变成二进制形式每位分开考虑．dp[i][j] 表示某一位运算到第ｉ个位置值为ｊ的概率，
则dp[i][j] = dp[i-1][j]*p[i]+dp[i-1][j?num[i]]*(1-p[i]).因为只和前一位有关系，所以可以滚动
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1005;
int num[MAXN],op[MAXN],m;
double dp[2][2],p[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,ca=1;
    char str[3];
    while(scanf("%d",&n)!=EOF)
    {
        m = 0;
        for(int i = 0; i <= n; i++)
            scanf("%d",&num[i]),
            m = max(m,num[i]);
        for(int i = 1; i <= n; i++)
        {
            scanf("%s",str);
            if(str[0]=='&') op[i] = 0;
            else if(str[0]=='|') op[i] = 1;
            else op[i] = 2;
        }
        for(int i = 1; i <= n; i++)
            scanf("%lf",&p[i]);
        int s,tmp,bit=1;
        double ans = 0;
        for(;m;m>>=1)
        {
            tmp = num[0]&1;
            s = 0;
            dp[s][tmp] = 1;
            dp[s][!tmp] = 0;
            for(int i = 1; i <= n; i++)
            {
                tmp = num[i]&1;
                for(int j = 0; j < 2; j++) dp[!s][j] = dp[s][j]*p[i];
                for(int j = 0; j < 2; j++)
                {
                    if(op[i]==0) dp[!s][j&tmp]+=dp[s][j]*(1-p[i]);
                    else if(op[i]==1) dp[!s][j|tmp]+=dp[s][j]*(1-p[i]);
                    else dp[!s][j^tmp]+=dp[s][j]*(1-p[i]);
                }
                s=!s;
            }
            ans+=dp[s][1]*bit;
            bit<<=1;
            for(int i = 0; i <= n; i++) num[i]>>=1;
        }
        printf("Case %d:\n%.6f\n",ca++,abs(ans));
    }

    return 0;
}
