//题意：给出七段译码器显示的数字，但相邻两个最右边是重合的，问最多可能有几种数字的组合可以是这样
/*解法：简单dp+大模拟。由于有1500组数据，不能n*10*10的做。dp[i][j]表示第i位，以j结尾的数有几个。
我的做法是枚举j，再手动判断可以和在第i-1为以哪几个数结尾的数拼一起。只要判断竖直字符是否匹配就可以
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 10005;
const int mod = 1000000007;
const int inf = 1111111111;
char a[]=" _     _  _     _  _  _  _  _ ";
char b[]="| |  | _| _||_||_ |_   ||_||_|";
char c[]="|_|  ||_  _|  | _||_|  ||_| _|";
long long dp[maxn][10];
char ax[maxn*3],bx[maxn*3],cx[maxn*3];

bool check(int n,int x,int k)
{
    if(ax[2*n+x]==a[k*3+x]&&bx[2*n+x]==b[k*3+x]&&cx[2*n+x]==c[k*3+x])
        return 1;
    return 0;
}
long long sum(int x){
	return (dp[x][0]+dp[x][1]+dp[x][3]+dp[x][4]+dp[x][7]+dp[x][8]+dp[x][9])%mod;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
		gets(ax);
        gets(ax),gets(bx),gets(cx);
        memset(dp,0,sizeof(dp));
        if(n==1)
        {
            for(int i = 0; i <= 9; i++)
                if(check(0,0,i)&&check(0,1,i)&&check(0,2,i)) dp[0][i]=1;
        }
        else
        {
            for(int i = 0; i <= 9; i++)
                if(check(0,0,i)&&check(0,1,i)) dp[0][i]=1;
            for(int i = 1; i <= n-1; i++)
            {
                for(int j = 0; j <= 9; j++)
                {
                    if(!check(i,1,j)) continue;
					if(bx[i*2]=='|' && cx[i*2]=='|')
					{
						dp[i][j]=sum(i-1)%mod;
						if(j==0||j==2||j==6||j==8)	dp[i][j]=(dp[i][j]+dp[i-1][2])%mod;
						if(j==0||j==4||j==5||j==6||j==8||j==9)	dp[i][j]=(dp[i][j]+(dp[i-1][5]+dp[i-1][6]))%mod;
					}
					else if(bx[i*2]=='|')
					{
						if(j==1 || j==3 ||j==4||j==5||j==7||j==9)	dp[i][j]=dp[i-1][2];
					}
					else{
						if(j==1 || j==3 ||j==7||j==2)	dp[i][j]=dp[i-1][5]+dp[i-1][6];
					}
                }
            }

        }
        long long ans = 0;
        for(int i = 0; i <= 9; i++)
            if(check(n-1,2,i)) ans=(ans+dp[n-1][i])%mod;
        cout<<ans<<"\n";
    }
    return 0;
}


