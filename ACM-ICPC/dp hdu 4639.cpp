#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int MAXN = 200005;
const int INF = 1111111111;
const int MOD = 10007;
const double EPS = 1e-6;
const double PI = acos(-1.0);
char str[MAXN],he[]="hehe";
int dp[MAXN];
bool check(int x)
{
    for(int i = 0; i < 4; i++)
        if(str[x+i]!=he[i]) return 0;
    return 1;
}
int main()
{
    //freopen("F:\\acmcode\\in.txt","r",stdin);
    int cas,ans;
    scanf("%d",&cas);
    for(int ca = 1;ca<=cas; ca++)
    {
        scanf("%s",str);
        ans = 1;
        for(int i = 0; str[i+3];i++)
        {
            dp[i] = i?dp[i-1]:1;
            if(check(i))
                dp[i]+=i-4>=0?dp[i-4]:1;
            dp[i]%=MOD;
            ans = dp[i];
        }
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
