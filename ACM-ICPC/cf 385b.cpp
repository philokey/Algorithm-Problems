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
const int MAXN = 10005;
char str[MAXN],bear[]="bear";
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    while(scanf("%s",str)!=EOF)
    {
        int len = strlen(str),pre=-1;
        int ans=0;
        for(int i = 0; i+4<len;i++)
        {
            bool flag = 1;
            for(int j = 0; j < 4; j++)
            {
                if(str[i+j]!=bear[j]) flag = 0;
            }
            if(flag)
            {
                ans = ans+(i-pre)*(len-i-3);
                pre = i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
