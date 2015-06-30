#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f;
int dp[MAXN][MAXN],n,way[MAXN][MAXN];
char a[MAXN];
void print(int i,int j){
    if(i>j) return;
    if(i==j){
        if(a[i]=='[' || a[i]==']') printf("[]");
        else printf("()");
    }
    else if(way[i][j]==-1){
        printf("%c",a[i]);
        print(i+1,j-1);
        printf("%c",a[j]);
    }
    else{
        print(i,way[i][j]);
        print(way[i][j]+1,j);
    }
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    while(gets(a))
    {
        n = strlen(a);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
            {
                if(i<j) dp[i][j] = INF;
                else if(i>j) dp[i][j] = 0;
                else dp[i][j] = 1;
            }
        memset(way,-1,sizeof(way));
        for(int l = 1; l < n; l++)
            for(int i = 0; i+l < n; i++)
            {
                int j = i+l;
                for(int k = i; k < j; k++)
                {
                    if(dp[i][j]>dp[i][k]+dp[k+1][j])
                    {
                        dp[i][j] = dp[i][k]+dp[k+1][j];
                        way[i][j] = k;
                    }
                }
                if((a[i]=='('&&a[j]==')')||(a[i]=='['&&a[j]==']'))
                    if(dp[i+1][j-1]<dp[i][j]) dp[i][j]=dp[i+1][j-1],way[i][j] = -1;
            }
        print(0,n-1);
        printf("\n");
    }
    return 0;
}
